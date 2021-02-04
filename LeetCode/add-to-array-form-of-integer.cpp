// 989. Add to Array-Form of Integer
#include <iostream>
#include <vector>
#include <list>

class Solution {
    public:
        std::vector<int> addToArrayForm(std::vector<int>& A, int K) {
            // O(N)
            std::list<int> K_list;
            std::list<int> result_list;
            do {
                K_list.push_front(K % 10);
                K /= 10;
            } while (K > 0);
            auto K_probe = K_list.rbegin();
            bool carry = false;
            for (int i = A.size() - 1; i >= 0; i--) {
                int temp = A[i];
                if (K_probe != K_list.rend()) {
                    temp += *K_probe;
                    K_probe++;
                }
                result_list.push_front(temp % 10);
                if (temp >= 10) {
                    if (i >= 1)
                        A[i - 1]++;
                    else
                        carry = true;
                }
            }
            while (K_probe != K_list.rend()) {
                result_list.push_front((*K_probe + carry) % 10);
                carry = *K_probe + carry >= 10;
                K_probe++;
            }
            if (carry)
                result_list.push_front(1);
            std::vector<int> result (result_list.begin(), result_list.end());
            return result;
        }
};

int main(void) {
    Solution s;
}