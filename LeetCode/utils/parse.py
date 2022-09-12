import csv
from dataclasses import dataclass
from enum import Enum
from typing import List, Tuple

DATABASE = "PS - LeetCode.csv"
COMMIT_INDICATOR = "Commit starts from here"
END_INDICATOR = "Failed"


class Difficulty(Enum):
    EASY, MEDIUM, HARD = "Easy", "Medium", "Hard"


@dataclass
class Problem:
    category: str
    name: str
    difficulty: Difficulty


def is_problem(row: List[str]) -> bool:
    try:
        Difficulty(row[2])
    except ValueError:
        return False
    return True


def parse_problem(row: List[str]) -> Problem:
    category, name, difficulty = row[0], row[1], Difficulty(row[2])
    return Problem(category=category, name=name, difficulty=difficulty)


def init_database() -> List:
    problems: List[Problem] = []
    commit_idx = 0
    with open(DATABASE, newline="") as db:
        db_reader = csv.reader(db, delimiter=",")
        for idx, row in enumerate(db_reader):
            if COMMIT_INDICATOR in row:
                commit_idx = idx
            if END_INDICATOR in row:
                break
            if not is_problem(row):
                continue
            problem = parse_problem(row)
            problems.append(problem)
    return problems, commit_idx


def parse_source(html: str) -> str:
    start_idx = html.find("submissionCode:") + len("submissionCode: '")
    end_idx = html.find("editCodeUrl") - 5
    assert start_idx != -1 and end_idx != -1
    source = html[start_idx:end_idx].encode("ascii").decode("unicode-escape")
    return source


def parse_question_id(html: str) -> int:
    start_idx = html.find("questionId:") + len("questionId: '")
    end_idx = html.find("submissionId") - 5
    assert start_idx != -1 and end_idx != -1
    question_id = int(html[start_idx:end_idx])
    return question_id


def parse_html(html: str) -> Tuple[str, int]:
    source = parse_source(html)
    question_id = parse_question_id(html)
    return source, question_id


database, commit_idx = init_database()
