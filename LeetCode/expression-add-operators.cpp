// 282. Expression Add Operators
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Solution {
    vector<char> ops;
    vector<long long> vals;
    vector<string> result;
    int N;
public:
    vector<string> addOperators(string num, int target) {
        // O(4 ** N)
        string s;
        N = num.size();
        long long t = target;
        traversal(num, t, 0, s);
        return result;
    }
    
    void traversal(string &num, long long &target, int start, string &s) {
        if (start == N) {
            if (eval(s) == target)
                result.push_back(s);
            return;
        }
        if (s.empty() || (!s.empty() && !isdigit(s.back()))) {
            s.push_back(num[start]);
            traversal(num, target, start + 1, s);
            s.pop_back();
        } else if (!s.empty() && isdigit(s.back())) {
            bool concat = true;
            if (s.size() == 1 && s.back() == '0')
                concat = false;
            if (s.size() >= 2 && s.back() == '0' && !isdigit(s[s.size() - 2]))
                concat = false;
            if (concat) {
                s.push_back(num[start]);
                traversal(num, target, start + 1, s);
                s.pop_back();
            }
            s.push_back('+');
            s.push_back(num[start]);
            traversal(num, target, start + 1, s);
            s.pop_back();
            s.pop_back();
            s.push_back('-');
            s.push_back(num[start]);
            traversal(num, target, start + 1, s);
            s.pop_back();
            s.pop_back();
            s.push_back('*');
            s.push_back(num[start]);
            traversal(num, target, start + 1, s);  
            s.pop_back();
            s.pop_back();
        }
    }
    
    inline long long eval(string &s) {
        ops.clear();
        vals.clear();
        long long result = 0;
        long long cur = 0;
        int K = s.size();
        for (int i = 0; i < K; i++) {
            if (isdigit(s[i])) {
                cur *= 10L;
                cur += s[i] - '0';
            } else {
                if (ops.empty() || ops.back() != '*')
                    vals.push_back(cur);
                else {
                    long long prev = vals.back(); vals.pop_back();
                    vals.push_back(cur * prev);
                    ops.pop_back();
                }
                ops.push_back(s[i]);
                cur = 0;
            }
        }
        if (ops.empty() || ops.back() != '*')
            vals.push_back(cur);
        else {
            long long prev = vals.back(); vals.pop_back();
            vals.push_back(cur * prev);
            ops.pop_back();
        }
        int L = ops.size();
        result = vals[0];
        for (int i = 0; i < L; i++) {
            char op = ops[i];
            if (op == '+') 
                result += vals[i + 1];
            else if (op == '-')
                result -= vals[i + 1];
        }
        return result;
    }
};

int main(void) {
    Solution s;
}