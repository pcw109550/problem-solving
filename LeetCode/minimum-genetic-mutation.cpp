// 433. Minimum Genetic Mutation
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // O(N)
        int N = bank.size();
        unordered_map<long long, long long> visited;
        unordered_set<long long> bank_translated;
        for (auto &b : bank)
            bank_translated.insert(encode(b));
        long long s = encode(start), e = encode(end);
        if (!bank_translated.count(e))
            return -1;
        queue<long long> Q; 
        visited[s] = 0;
        Q.push(s);
        while (!Q.empty()) {
            long long cur = Q.front(); Q.pop();
            if (cur == e)
                break;
            long long chunk = 0b11, b1 = 0b10, b2 = 0b01;
            for (int i = 0; i < 8; i++) {
                long long target = cur;
                if (target & b1)
                    target -= b1;
                if (target & b2)
                    target -= b2;
                if (!visited.count(target) && bank_translated.count(target)) {
                    Q.push(target); visited[target] = visited[cur] + 1;
                }
                if (!visited.count(target | b1) && bank_translated.count(target | b1)) {
                    Q.push(target | b1); visited[target | b1] = visited[cur] + 1;
                }
                if (!visited.count(target | b2) && bank_translated.count(target | b2)) {
                    Q.push(target | b2); visited[target | b2] = visited[cur] + 1;
                }
                if (!visited.count(target | chunk) && bank_translated.count(target | chunk)) {
                    Q.push(target | chunk); visited[target | chunk] = visited[cur] + 1;
                }
                chunk <<= 2;
                b1 <<= 2;
                b2 <<= 2;
            }
        }
        if (!visited.count(e))
            return -1;
        return visited[e];
    }
    
    inline long long encode(string &s) {
        long long chunk = 1;
        long long result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'A')
                result += 0;
            else if (s[i] == 'C')
                result += 1 * chunk;
            else if (s[i] == 'G')
                result += 2 * chunk;
            else if (s[i] == 'T')
                result += 3 * chunk;
            chunk <<= 2;
        }
        return result;
    }
    
};

int main(void) {
    Solution s;
}