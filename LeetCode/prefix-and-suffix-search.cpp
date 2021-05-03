// 745. Prefix and Suffix Search
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class WordFilter {
    std::unordered_map<std::string, int> Map;
    public:
        WordFilter(std::vector<std::string>& words) {
            // O(N * M ** 2)
            int N = words.size();
            for (int i = 0; i < N; i++) {
                int M = words[i].size();
                for (int j = 0; j <= M; j++)
                    for (int k = 0; k <= M; k++) {
                        std::string s = words[i].substr(j, M - j);
                        s += std::string(1, ' ');
                        s += words[i].substr(0, k);
                        Map[s] = i;
                    }
            }
        }

        int f(std::string prefix, std::string suffix) {
            // O(1)
            std::string s = suffix;
            s += std::string(1, ' ');
            s += prefix;
            if (Map.count(s))
                return Map[s];
            return -1;
        }
};

int main(void) {
    WordFilter* obj;
}