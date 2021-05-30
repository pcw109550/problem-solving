# 640. Solve the Equation
from typing import Tuple


class Solution:
    def solveEquation(self, equation: str) -> str:
        # O(N)
        l, r = equation.split("=")
        a1, b1 = self.parse(l)
        a2, b2 = self.parse(r)
        a = a1 - a2
        b = b2 - b1
        if a == 0 and b != 0:
            return "No solution"
        elif a == 0 and b == 0:
            return "Infinite solutions"
        return f"x={b // a}"
    
    def parse(self, poly: str) -> Tuple[int, int]:
        a, b = 0, 0
        prev = 0
        for i in range(len(poly)):
            if poly[i] == "x":
                if poly[prev : i] in ("+", "-"):
                    a += int(poly[prev : i] + "1")
                else:
                    a += 1 if i == prev else int(poly[prev : i])
                prev = i + 1
            elif poly[i] in ("+", "-"):
                b += 0 if i == prev else int(poly[prev : i])
                prev = i
        if poly[-1] != "x":
            b += int(poly[prev:])
        return a, b
            