// 881. Boats to Save People
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int numRescueBoats(std::vector<int>& people, int limit) {
            // O(N log(N))
            int result = 0;
            std::sort(people.begin(), people.end());
            int i = 0, j = people.size() - 1;
            while (i <= j) {
                result++;
                if (people[i] + people[j] <= limit)
                    i++;
                j--;
            }            
            return result;
        }
};

class Solution2 {
    public:
        int numRescueBoats(std::vector<int>& people, int limit) {
            // O(N log(N))
            int result = 0;
            int N = people.size();
            std::vector<bool> visited (N, false);
            std::sort(people.begin(), people.end(), std::greater<int>());
            for (int i = 0; i < N; i++) {
                if (visited[i])
                    continue;
                result++;
                visited[i] = true;
                auto it = std::lower_bound(people.begin(), people.end(), limit - people[i], std::greater<int>());
                int idx = it - people.begin();
                while (idx < N && visited[idx]) {
                    idx++;
                }
                if (idx == N)
                    continue;
                visited[idx] = true;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}