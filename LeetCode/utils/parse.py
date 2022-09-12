import csv
from dataclasses import dataclass
from enum import Enum
from typing import List

DATABASE = "PS - LeetCode.csv"
INDICATOR = "Commit starts from here"


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
            if INDICATOR in row:
                commit_idx = idx
            if not is_problem(row):
                continue
            problem = parse_problem(row)
            problems.append(problem)
    return problems, commit_idx


database, commit_idx = init_database()
