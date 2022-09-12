import logging
from time import sleep
from typing import Dict, List, Tuple

import git

from api import get_problem_data, get_problem_frontend_id, get_submission_list
from parse import Problem, commit_idx, database

logging.basicConfig(level=logging.INFO)
repo = git.Repo("../../")

PROBLEM_PER_COMMIT = 10
SLEEP_INTERVAL = 1.5


def get_accepted_submission_info(submission_list: Dict) -> Tuple[int, str]:
    for submission in submission_list["data"]["submissionList"]["submissions"]:
        # get most recent accepted solution
        if submission["statusDisplay"] == "Accepted":
            return int(submission["id"]), submission["lang"]
    assert False


def get_source_complexity(problem_source: str) -> str:
    # example line containing complexity: // O(N ** 3)
    for line in problem_source.split("\n"):
        start_idx = line.find("O(")
        if start_idx == -1:
            continue
        complexity = line[start_idx:].rstrip()
        return complexity
    # complexity not included in source
    return ""


def get_problem_metadatas(problems: List[Problem]) -> List:
    problem_metadatas, problem_list_length = [], len(problems)
    for idx, problem in enumerate(problems):
        submission_list = get_submission_list(problem.name)
        submission_id, lang = get_accepted_submission_info(submission_list)
        source, extension, question_id = get_problem_data(
            submission_id, problem.name, lang
        )
        complexity = get_source_complexity(source)
        question_frontend_id = get_problem_frontend_id(problem.name)
        problem_metadata = extension, question_id, question_frontend_id, complexity
        problem_metadatas.append(problem_metadata)
        logging.info(
            f"{idx + 1}/{problem_list_length}: {problem}: {str(problem_metadata)}"
        )
        # avoid rate limiting
        sleep(SLEEP_INTERVAL)

    return problem_metadatas


def format_source_file_name(problem_name: str, extension: str) -> str:
    source_file_name = f"{problem_name}.{extension}"
    return source_file_name


def format_metadata_msg(question_id: int, problem_name: str, complexity: str) -> str:
    metadata_msg = f"- {question_id}. {problem_name}"
    metadata_msg += f": {complexity}" if complexity != "" else ""
    return metadata_msg


def format_commit_msg(question_ids: List[int], metadata_msgs: List[str]) -> str:
    commit_msg = (
        f"[LeetCode] {', '.join(str(question_id) for question_id in question_ids)}"
    )
    commit_msg += "\n\n"
    commit_msg += "\n".join(metadata_msg for metadata_msg in metadata_msgs)
    return commit_msg


if __name__ == "__main__":
    problems = database[commit_idx:]
    problem_metadatas = get_problem_metadatas(problems)

    for i in range(0, len(problems), PROBLEM_PER_COMMIT):
        question_ids, source_file_names, metadata_msgs = [], [], []
        for j in range(i, min(i + PROBLEM_PER_COMMIT, len(problems))):
            problem: Problem = problems[j]
            extension, _, question_frontend_id, complexity = problem_metadatas[j]
            question_ids.append(question_frontend_id)
            source_file_name = format_source_file_name(problem.name, extension)
            source_file_names.append(source_file_name)
            metadata_msg = format_metadata_msg(
                question_frontend_id, problem.name, complexity
            )
            metadata_msgs.append(metadata_msg)

        commit_msg = format_commit_msg(question_ids, metadata_msgs)
        logging.info(commit_msg)

        repo.git.add(
            [f"LeetCode/{source_file_name}" for source_file_name in source_file_names]
        )
        repo.git.commit("-m", commit_msg)
