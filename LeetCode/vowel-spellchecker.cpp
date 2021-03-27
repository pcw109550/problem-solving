// 966. Vowel Spellchecker
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cctype>

class Solution {
    public:
        std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
            // O(N)
            std::vector<std::string> result;
            std::unordered_set<std::string> S;
            std::unordered_map<std::string, std::string> M;
            std::unordered_map<std::string, std::string> V;
            for (auto it : wordlist)
                S.insert(it);
            for (auto it : wordlist) {
                auto lower = to_lower(it);
                if (!M.count(lower))
                    M[lower] = it;
                auto sensor = to_sensor(lower);
                if (!V.count(sensor))
                    V[sensor] = it;
            }
            
            for (auto query : queries) {
                if (S.count(query)) {
                    result.push_back(query);
                    continue;
                }
                auto lower = to_lower(query);
                if (M.count(lower)) {
                    result.push_back(M[lower]);
                    continue;
                }
                auto sensor = to_sensor(lower);
                if (V.count(sensor)) {
                    result.push_back(V[sensor]);
                    continue;
                }
                result.push_back("");                
            }
            return result;
        }
    
        inline std::string to_lower(std::string data) {
            std::transform(data.begin(), data.end(), data.begin(),
            [](unsigned char c){ return std::tolower(c); });
            return data;
        }
    
        inline std::string to_sensor(std::string data) {
            std::transform(data.begin(), data.end(), data.begin(), 
            [](unsigned char c){ 
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    return '*';
                return static_cast<char>(c);
            });
            return data;
        }
};

int main(void) {
    Solution s;
}