// 535. Encode and Decode TinyURL
#include <iostream>
#include <unordered_map>
#include <string>
#include <random>

class Solution {
    std::random_device rd;
    std::mt19937 rng;
    std::uniform_int_distribution<int> uni;
    std::unordered_map<std::string, std::string> M;
    int keylen;
    public:
        Solution() {
            rng = std::mt19937(rd());
            uni = std::uniform_int_distribution<int>('A', 'z');
            keylen = 3;
        }
    
        // Encodes a URL to a shortened URL.
        std::string encode(std::string longUrl) {
            std::string key = rand_str(keylen);
            while (M.count(key))
                key = rand_str(keylen);
            M[key] = longUrl;
            return key;
        }

        // Decodes a shortened URL to its original URL.
        std::string decode(std::string shortUrl) {
            return M[shortUrl];
        }
    
        std::string rand_str(int N) {
            std::string result;
            for (int i = 0; i < N; i++)
                result += static_cast<char>(uni(rng));
            return result;
        }
    
    
};

int main(void) {
    Solution s;
}