#!/usr/bin/env python3


def measure(n):
    width = 1
    last = 0
    while n >= 10:
        width += 1
        n //= 10
    last = n
    return width, last


def substr(a, b, t):
    for i in range(t):
        a //= 10
    return a == b


def task(idx):
    N = int(input())
    temp = [0] * N
    result = 0
    inp = [int(c) for c in str(input()).split(' ')]
    temp[0] = inp[0]

    for i in range(1, N):
        prev_width, prev_last = measure(temp[i - 1])
        curr_width, curr_last = measure(inp[i])
        if prev_width < curr_width:
            temp[i] = inp[i]
            continue
        elif prev_width == curr_width:
            if prev_last < curr_last:
                temp[i] = inp[i]
                continue
            elif prev_last == curr_last:
                if temp[i - 1] < inp[i]:
                    temp[i] = inp[i]
                    continue
                else:
                    temp[i] = inp[i] * 10
                    result += 1
                    continue
            elif prev_last > curr_last:
                temp[i] = inp[i] * 10
                result += 1
                continue
        elif prev_width > curr_width:
            if prev_last < curr_last:
                temp[i] = inp[i] * 10 ** (prev_width - curr_width)
                result += prev_width - curr_width
                continue
            elif prev_last > curr_last:
                temp[i] = inp[i] * 10 ** (prev_width - curr_width + 1)
                result += prev_width - curr_width + 1
                continue
            elif prev_last == curr_last:
                is_substr = substr(temp[i - 1], inp[i], prev_width - curr_width)
                if is_substr:
                    t = temp[i - 1] + 1
                    new_cand_width, new_cand_last = measure(t)
                    if new_cand_last == curr_last and substr(t, inp[i], new_cand_width - curr_width):
                        temp[i] = t
                        result += prev_width - curr_width
                        continue
                    else:
                        temp[i] = inp[i] * 10 ** (prev_width - curr_width + 1)
                        result += prev_width - curr_width + 1
                        continue
                else:
                    temp[i] = inp[i] * 10 ** (prev_width - curr_width + 1)
                    result += prev_width - curr_width + 1
                    continue

    print('###')
    for i in range(N):
        print(inp[i], temp[i])
    print(f'Case #{idx}: {result}')


def main():
    T = int(input())
    for t in range(1, T + 1):
        task(t) 


if __name__ == '__main__':
    main()