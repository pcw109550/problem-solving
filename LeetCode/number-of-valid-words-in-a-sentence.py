class Solution:
    def countValidWords(self, sentence: str) -> int:
        # O(N)
        result = 0
        tokens = sentence.split()
        for token in tokens:
            if self.check(token):
                result += 1
        return result
    
    def check(self, token: str) -> bool:
        N = len(token)
        hyphenCnt = 0
        for i in range(N):
            if token[i].isdigit():
                return False
            elif token[i] == '-':
                if hyphenCnt == 1:
                    return False
                if i == 0 or i == N - 1:
                    return False
                hyphenCnt = 1
                if not token[i - 1].isalpha() or not token[i + 1].isalpha():
                    return False
            elif token[i] in ".!,":
                if i != N - 1:
                    return False
        return True
                