# 151. Reverse Words in a String

class Solution:
    def reverseWords(self, s: str) -> str:
        # O(N)
        N = len(s)
        result = ""
        i = 0
        start, end = 0, 0
        while i <= N:
            if i == N or s[i] == " ":
                if i >= 1 and s[i - 1] != " ":
                    result = s[start:end + 1] + " " + result
                start = end = i + 1
            else:
                end = i
            i += 1
        return result[:-1]