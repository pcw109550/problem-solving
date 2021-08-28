# 331. Verify Preorder Serialization of a Binary Trees

class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        # O(N)
        tokens = preorder.split(",")
        track = 1
        N = len(tokens)
        for i in range(N):
            if tokens[i] != "#":
                track += 1
            else:
                track -= 1
                if i != N - 1 and track == 0:
                    return False
        result = track == 0
        return result