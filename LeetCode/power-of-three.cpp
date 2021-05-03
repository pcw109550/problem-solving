// 326. Power of Three
class Solution {
    public:
        bool isPowerOfThree(int n) {
            // O(log(N))
            if (n <= 0)
                return false;
            while (n > 0) {
                if (n % 3 != 0) {
                    if (n == 1)
                        break;
                    else
                        return false;
                }
                n /= 3;
            }
            return true;
        }
};

int main(void) {
    Solution s;
}