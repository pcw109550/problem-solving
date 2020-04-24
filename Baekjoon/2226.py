#!/usr/bin/env python3
N = int(input()) - 1
a = 0
for i in range(N):
    a = (1 << i) - a
print(a)