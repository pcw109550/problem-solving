# 224. Basic Calculator
from typing import List, Union, Dict

class Solution:
    def __init__(self):
        self.match_idx: Dict[int, int] = dict()
        self.tokens: List[Union[int, str]] = []

    def calculate(self, s: str) -> int:
        # O(N)
        self.tokenize(s)
        self.match()
        result = self.evaluate(0, len(self.tokens) - 1)
        return result
    
    def match(self) -> None:
        idx = []
        for i in range(len(self.tokens)):
            if self.tokens[i] == "(":
                idx.append(i)
            elif self.tokens[i] == ")":
                back = idx.pop()
                self.match_idx[back] = i
    
    def tokenize(self, s: str) -> None:
        # O(N)
        s = s.replace(" ", "")
        tokens = []
        move = -1
        for i in range(len(s)):
            if move > i:
                continue
            if s[i] in "()-+":
                tokens.append(s[i])
            else:
                token = ""
                for j in range(i, len(s)):
                    if s[j].isdigit():
                        token += s[j]
                        if j == len(s) - 1:
                            move = j + 1
                    else:
                        move = j
                        break
                if tokens and tokens[-1] == "-":
                    tokens.pop()
                    token = "-" + token
                tokens.append(int(token))
        self.tokens = tokens
        
    def evaluate(self, start: int, end: int) -> int:
        result = 0
        move = -1
        for i in range(start, end + 1):
            if move > i:
                continue
            if self.tokens[i] == "-":
                back = self.match_idx[i + 1]
                move = back + 1
                result += -self.evaluate(i + 2, back - 1)
            elif self.tokens[i] == "(":
                back = self.match_idx[i]
                move = back + 1
                result += self.evaluate(i + 1, back - 1)
            elif isinstance(self.tokens[i], int):
                result += self.tokens[i]
        return result
            
        