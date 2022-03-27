# 165. Compare Version Numbers
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # O(1)
        _version1 = version1.split(".")
        _version2 = version2.split(".")
        max_len = max(len(_version1), len(_version2))
        _version1 += ["0"] * (max_len - len(_version1))
        _version2 += ["0"] * (max_len - len(_version2))
        for _p1, _p2 in zip(_version1, _version2):
            p1 = int(_p1.lstrip("0") if _p1.rfind("0") != len(_p1) - 1 else _p1)
            p2 = int(_p2.lstrip("0") if _p2.rfind("0") != len(_p2) - 1 else _p2)
            if p1 == p2:
                continue
            return -1 if p1 < p2 else 1
        return 0
