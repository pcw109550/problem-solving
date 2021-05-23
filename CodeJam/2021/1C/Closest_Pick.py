#!/usr/bin/env python3
from itertools import product


def task(idx):
    [N, K] = [int(c) for c in str(input()).split()]
    temp = [int(c) for c in str(input()).split()]
    occ = [False] * K
    for t in temp:
        occ[t - 1] = True
    cand_target = []
    not_cand_target = []
    for cand in range(K):
        if not occ[cand]:
            cand_target.append(cand)
        else:
            not_cand_target.append(cand)

    result = 0.0
    for p1, p2 in product(cand_target, repeat=2):
        cnt = 0
        for c in range(K):
            min_res = min(abs(c - p1), abs(c - p2))
            min_res_cmp = K + 1
            for d in not_cand_target:
                min_res_cmp = min(min_res_cmp, abs(c - d))
            if min_res < min_res_cmp:
                cnt += 1
        result = max(result, cnt / K)

    print(f'Case #{idx}: {result}')


def main():
    T = int(input())
    for t in range(1, T + 1):
        task(t)


if __name__ == '__main__':
    main()