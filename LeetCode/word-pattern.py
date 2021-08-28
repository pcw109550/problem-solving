# 290. Word Pattern

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        # O(N)
        d, dinv = {}, {}
        tokens = s.split()
        if len(tokens) != len(pattern):
            return False
        for i, token in enumerate(tokens):
            if token not in d and pattern[i] not in dinv:
                d[token] = pattern[i]
                dinv[pattern[i]] = token
            else:
                if token in d and d[token] != pattern[i]:
                    return False
                if pattern[i] in dinv and dinv[pattern[i]] != token:
                    return False
        return True