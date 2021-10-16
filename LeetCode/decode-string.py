# 394. Decode String
class Solution:
    pair = {}
    
    def decodeString(self, s: str) -> str:
        # O(N)
        self.preprocess(s)
        return self.recurse(0, s)
    
    def preprocess(self, s: str) -> str:
        stack = []
        for i in range(len(s)):
            if s[i] == "[":
                stack.append(i)
            elif s[i] == "]":
                self.pair[stack.pop()] = i

    def recurse(self, base: int, s: str) -> str:
        result = ""
        digit = 0
        i, N = 0, len(s)
        while i < N:
            if s[i] == "[":
                token_len = self.pair[base + i] - (i + base) - 1
                result += digit * self.recurse(base + i + 1, s[i + 1: i + token_len + 1])
                digit = 0
                i += token_len + 1
            elif s[i].isalpha():
                result += s[i]
            elif s[i].isdigit():
                digit = 10 * digit + ord(s[i]) - ord('0')
            i += 1
        return result