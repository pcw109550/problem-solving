// 952. Largest Component Size by Common Factor
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
#define MAX 100000
#define MAX_ELEM 20000
#define PRIME_NUM 9592

class Solution {
    vector<pair<int, int> > mySet; // {rank, parent}
public:
    int largestComponentSize(vector<int>& nums) {
        // O(N * log(M) * invack(N + M))
        int N = nums.size();
        mySet = vector<pair<int, int> > (MAX_ELEM + MAX, {0, -1});
        int result = 1;
        for (int i = 0; i < N; i++) {
            // O(N)
            int num = nums[i];
            bool seen = false;
            for (int j = 2; j * j <= nums[i]; j++) {
                // O(sqrt(N))
                seen = false;
                while (num % j == 0) {
                    if (!seen)
                        Union(i, MAX_ELEM + j);
                    seen = true;
                    num /= j;
                }
            }
            if (num != 1)
                Union(i, MAX_ELEM + num);
        }
        unordered_map<int, int> M;
        for (int i = 0; i < N; i++)
            M[Find(i)]++;
        for (auto it : M)
            result = max(result, it.second);
        return result;
    }
    
    int Find(int x) {
        if (mySet[x].second < 0)
            return x;
        return mySet[x].second = Find(mySet[x].second);
    }

    bool Union(int x, int y) {
        int X = Find(x);
        int Y = Find(y);
        if (X == Y)
            return true;
        if (mySet[X].first < mySet[Y].first)
            swap(X, Y);
        mySet[Y].second = X;
        if (mySet[X].first == mySet[Y].first)
            mySet[X].first++;
        return false;
    }
};

class Solution2 {
    vector<int> primes;
    vector<pair<int, int> > mySet; // {rank, parent}
public:
    int largestComponentSize(vector<int>& nums) {
        // O(M * log(log(M) + N * log(M) * invack(N + M))
        int N = nums.size();
        mySet = vector<pair<int, int> > (MAX_ELEM + PRIME_NUM, {0, -1});
        int result = 1;
        gen_prime();
        unordered_map<int, int> prime_map;
        for (int i = 0; i < PRIME_NUM; i++)
            prime_map[primes[i]] = i;
        for (int i = 0; i < N; i++) {
            // O(N)
            int num = nums[i];
            bool seen = false;
            for (int j = 2; j * j <= nums[i]; j++) {
                // O(sqrt(N))
                seen = false;
                while (num % j == 0) {
                    if (!seen)
                        Union(i, MAX_ELEM + prime_map[j]);
                    seen = true;
                    num /= j;
                }
            }
            if (num != 1)
                Union(i, MAX_ELEM + prime_map[num]);
        }
        unordered_map<int, int> M;
        for (int i = 0; i < N; i++)
            M[Find(i)]++;
        for (auto it : M)
            result = max(result, it.second);
        return result;
    }
    
    void gen_prime() {
        // O(N * log(log(N)))
        vector<bool> is_prime(MAX + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= MAX; i++) {
            if (!is_prime[i])
                continue;
            for (int j = i * i; j <= MAX; j += i)
                is_prime[j] = false;
        }
        for (int i = 2; i <= MAX; i++)
            if (is_prime[i])
                primes.push_back(i);
    }
    
    int Find(int x) {
        if (mySet[x].second < 0)
            return x;
        return mySet[x].second = Find(mySet[x].second);
    }

    bool Union(int x, int y) {
        int X = Find(x);
        int Y = Find(y);
        if (X == Y)
            return true;
        if (mySet[X].first < mySet[Y].first)
            swap(X, Y);
        mySet[Y].second = X;
        if (mySet[X].first == mySet[Y].first)
            mySet[X].first++;
        return false;
    }
};

class Solution3 {
public:
    int largestComponentSize(vector<int>& nums) {
        // O(N ** 2) TLE
        int result = 1;
        int N = nums.size();
        vector<vector<int> > edges(N, vector<int>());
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                int gcd = __gcd(nums[i], nums[j]);
                if (gcd == 1)
                    continue;
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            int cur_cnt = 1;
            queue<int> Q;
            Q.push(i);
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                for (auto edge : edges[cur]) {
                    if (visited[edge])
                        continue;
                    visited[edge] = true;
                    cur_cnt++;
                    Q.push(edge);
                }
            }
            result = max(result, cur_cnt);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}