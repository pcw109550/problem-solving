// 816. Ambiguous Coordinates
#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Solution {
    std::vector<std::string> result;
    std::string _s;
    int N;
    public:
        std::vector<std::string> ambiguousCoordinates(std::string s) {
            // O(N ** 4)
            N = s.size() - 2;
            _s = s.substr(1, N);
            for (int i = 0; i < N - 1; i++)
                task(i);
            return result;
        }
    
        void task(int i) {
            // O(N ** 3)
            auto words = split(_s, i);
            auto cand1 = gen_cand(words.first);
            auto cand2 = gen_cand(words.second);
            for (auto it1 : cand1)
                for (auto it2 : cand2) {
                    auto s = "(" + it1 + ", " + it2 + ")";
                    result.push_back(s);
                }
        }
    
        std::pair<std::string, std::string> split(std::string &s, int i) {
            // O(N)
            std::string a = s.substr(0, i + 1);
            std::string b = s.substr(i + 1, N - i - 1);
            return {a, b};
        }
    
        std::vector<std::string> gen_cand(std::string &s) {
            // O(N ** 2)
            std::vector<std::string> cands;
            int l = s.size();
            if (s[0] == '0' && l == 1)
                cands.push_back(s);
            if (s[0] != '0')
                cands.push_back(s);
            if (l == 1)
                return cands;
            for (int i = 0; i < l - 1; i++) {
                auto words = split(s, i);
                if (words.first[0] == '0' && words.first.size() > 1)
                    continue;
                if (words.second[words.second.size() - 1] == '0')
                    continue;
                auto cand = words.first + "." + words.second;
                cands.push_back(cand);
            }
            return cands;
        }
};

int main(void) {
    Solution s;
}