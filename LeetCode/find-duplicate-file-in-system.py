#!/usr/bin/env python3
# 609. Find Duplicate File in System
from collections import defaultdict
from typing import List


class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        # O(N)
        memory = defaultdict(list)
        for path in paths:
            tokens = path.split()
            path = tokens[0]
            for file_and_content in tokens[1:]:
                probe = file_and_content.find('(')
                file_name = file_and_content[:probe]
                content = file_and_content[probe + 1:-1]
                memory[content].append(f'{path}/{file_name}')
        result = []
        for key, value in memory.items():
            if len(value) >= 2:
                result.append(value)
        return result
            