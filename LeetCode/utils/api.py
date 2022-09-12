import json
import os
from typing import Dict, Tuple

from cred import cred
from parse import parse_html


def get_submission_list(problem_name: str) -> Dict:
    file_name = f"{problem_name}_list.json"
    cmd = f"""curl --output {file_name} --compressed -s -k -X $'POST' """
    cmd += f""" -H $'Content-Length: {543 - len("maximum-performance-of-a-team") + len(problem_name)}' """
    cmd += cred
    payload = r"""--data-binary $'{\"operationName\":\"Submissions\",\"variables\":{\"offset\":0,\"limit\":20,\"lastKey\":null,\"questionSlug\":\"maximum-performance-of-a-team\"},\"query\":\"query Submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {\\n  submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {\\n    lastKey\\n    hasNext\\n    submissions {\\n      id\\n      statusDisplay\\n      lang\\n      runtime\\n      timestamp\\n      url\\n      isPending\\n      memory\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\"}' """
    payload = payload.replace("maximum-performance-of-a-team", problem_name)
    cmd += payload
    cmd += """    $'https://leetcode.com/graphql' """
    assert os.system(cmd) == 0
    with open(file_name) as f:
        result = json.loads(f.read())
    return result


def get_extension(lang: str) -> str:
    extension = "py" if "python" in lang else lang
    return extension


def get_problem_data(
    submission_id: int, problem_name: str, lang: str
) -> Tuple[str, str, int]:
    extension = get_extension(lang)
    file_name = f"{problem_name}.{extension}"
    cmd = f"""curl --output {file_name} --compressed -s -k -X $'GET' """
    cmd += cred
    cmd += f"""    $'https://leetcode.com/submissions/detail/{submission_id}/' """
    assert os.system(cmd) == 0
    with open(file_name, "r") as f:
        html = f.read()
        source, question_id = parse_html(html)
    with open(f"../{file_name}", "w") as f:
        f.write(source)
    return source, extension, question_id


def get_problem_frontend_question_id(problem_name: str) -> int:
    file_name = f"{problem_name}_frontend_id.json"
    cmd = f"""curl --output {file_name} --compressed -s -k -X $'POST' """
    cmd += f""" -H $'Content-Length: {221 - len("string-to-integer-atoi") + len(problem_name)}' """
    cmd += cred
    payload = r"""--data-binary $'{\"operationName\":\"questionData\",\"variables\":{\"titleSlug\":\"string-to-integer-atoi\"},\"query\":\"query questionData($titleSlug: String!) {\\n  question(titleSlug: $titleSlug) {\\n    questionId\\n    questionFrontendId\\n }\\n}\\n\"}' """
    payload = payload.replace("string-to-integer-atoi", problem_name)
    cmd += payload
    cmd += """    $'https://leetcode.com/graphql' """
    assert os.system(cmd) == 0
    with open(file_name) as f:
        result = json.loads(f.read())
    problem_frontend_question_id = int(result["data"]["question"]["questionFrontendId"])
    return problem_frontend_question_id
