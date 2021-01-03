#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
unordered_set<int> S;

inline bool is_prime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

void calc(vector<int> &nums, int len) {
    vector<int> idx (nums.size(), 0);
    fill(idx.begin(), idx.begin() + len, 1);
    do {
        vector<int> target;
        for (int i = 0; i < idx.size(); i++)
            if (idx[i] == 1)
                target.emplace_back(nums[i]);
        do {
            int cand = 0;
            for (auto it : target) {
                cand *= 10;
                cand += it;
            }
            if (is_prime(cand))
                S.insert(cand);
        } while (next_permutation(target.begin(), target.end()));
    } while (prev_permutation(idx.begin(), idx.end()));
}

int solution(string numbers) {
    int answer = 0;
    vector<int> nums;
    for (auto num : numbers)    
        nums.emplace_back(num - '0');
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= nums.size(); i++)
        calc(nums, i);
    answer = S.size();
    return answer;
}

int main(void) {
}