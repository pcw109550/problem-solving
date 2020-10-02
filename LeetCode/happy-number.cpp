// 202. Happy Number
#include <iostream>
#include <unordered_set>

class Solution {
    public:
        bool isHappy(int n) {
            // Space O(1) using tortoise and hare
            if (n <= 0)
                return false;
            if (n == 1)
                return true;
            int tortoise = n, hare = n;
            while (true) {
                tortoise = sum_square(tortoise);
                hare = sum_square(sum_square(hare));
                if (tortoise == 1 || hare == 1)
                    return true;
                if (tortoise == hare)
                    break;
            }
            return false;
        }

        int sum_square(int n) {
            int result = 0;
            while (n > 0) {
                result += (n % 10) * (n % 10);
                n /= 10;
            }
            return result;
        }
};

class Solution2 {
    public:
        bool isHappy(int n) {
            // Space O(N) using hashmap
            if (n <= 0)
                return false;
            std::unordered_set<int> set;
            int current = n, next;
            set.insert(current);
            while (true) {
                next = sum_square(current);
                if (next == 1)
                    return true;
                if (set.find(next) == set.end()) {
                    set.insert(next);
                    current = next;
                } else
                    break;
            }
            return false;
        }

        int sum_square(int n) {
            int result = 0;
            while (n > 0) {
                result += (n % 10) * (n % 10);
                n /= 10;
            }
            return result;
        }
};

int main(void) {
    Solution s;
    int n = 1;
    std::cout << s.isHappy(n);
}