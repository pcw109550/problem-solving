// 1268. Search Suggestions System
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::vector<std::vector<std::string> > suggestedProducts(std::vector<std::string>& products, std::string searchWord) {
            // O(N * log(N))
            int N = products.size();
            int K = searchWord.size();
            std::vector<std::vector<std::string> > result(K, std::vector<std::string>());
            std::sort(products.begin(), products.end());
            std::vector<int> overlap;
            for (auto product : products) {
                int len = 0;
                int product_len = product.size();
                while (len < std::min(product_len, K)) {
                    if (product[len] == searchWord[len])
                        len++;
                    else
                        break;
                }
                overlap.push_back(len);                
            }
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < N; j++) {
                    if (result[i].size() >= 3)
                        break;
                    if (i + 1 <= overlap[j])
                        result[i].push_back(products[j]);
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}