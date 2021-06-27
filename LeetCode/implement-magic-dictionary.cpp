// 676. Implement Magic Dictionary
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class MagicDictionary {
    unordered_map<string, int> Map;
    unordered_set<string> Set;
    public:
        /** Initialize your data structure here. */
        MagicDictionary() {
        }

        void buildDict(vector<string> dictionary) {
            // Time O(N * M ** 2) Space O(N * M ** 2)
            for (int k = 0; k < dictionary.size(); k++) {
                for (int i = 0; i < dictionary[k].size(); i++) {
                    char c = dictionary[k][i];
                    dictionary[k][i] = '*';
                    Map[dictionary[k]]++;
                    dictionary[k][i] = c;
                }
                Set.insert(dictionary[k]);
            }
        }

        bool search(string searchWord) {
            // O(M);
            int M = searchWord.size();
            string original = searchWord;
            for (int i = 0; i < M; i++) {
                char c = searchWord[i];
                searchWord[i] = '*';
                if (Map.count(searchWord)) {
                    if (Map[searchWord] > 1)
                        return true;
                    else if (!Set.count(original))
                        return true;
                }
                searchWord[i] = c;
            }
            return false;
        }
};

int main(void) {
    MagicDictionary *obj;
}
