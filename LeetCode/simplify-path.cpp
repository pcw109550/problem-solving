// 71. Simplify Path
#include <iostream>
#include <string>

typedef enum State
{
    START,
    SLASH,
    DOT1,
    DOT2,
    NAME
} State;

class Solution {
    int i;
    State state;
    std::string _path;
    std::string result;
    std::string temp;
    public:
        std::string simplifyPath(std::string path) {
            // O(N) using DFA
            state = START; _path = path; i = 0;
            while (i < path.size()) {
                switch(state) {
                    case START:
                        start();
                        break;
                    case SLASH:
                        slash();
                        break;
                    case DOT1:
                        dot1();
                        break;
                    case DOT2:
                        dot2();
                        break;
                    case NAME:
                        name();
                        break;
                    default:
                        break;
                }
                i++;
            }
            end();
            return result;
        }

        inline void end() {
            if (temp == "..")
                level_up();
            else if (temp != ".")
                result += temp;
            if (result.size() > 1 && result.back() == '/')
                result.pop_back();
        }
    
        inline void start() {
            if (_path[i] == '/') {
                result.push_back('/');
                state = SLASH;
            }
        }
    
        inline void slash() {
            if (_path[i] == '/') {
                state = SLASH;
            } else if (_path[i] == '.') {
                temp.clear();
                temp.push_back('.');
                state = DOT1; 
            } else {
                temp.clear();
                temp.push_back(_path[i]);
                state = NAME;
            }
        }
    
        inline void dot1() {
            if (_path[i] == '/') {
                temp.clear();
                state = SLASH;
            } else if (_path[i] == '.') {
                temp.push_back('.');
                state = DOT2;
            } else {
                temp.push_back(_path[i]);
                state = NAME;
            }
        }
    
        inline void dot2() {
            if (_path[i] == '/') {
                temp.clear();
                level_up();
                state = SLASH;
            } else {
                temp.push_back(_path[i]);
                state = NAME;
            }
        }
    
        inline void name() {
            if (_path[i] == '/') {
                result += temp;
                if (i != _path.size() - 1)
                    result.push_back('/');
                temp.clear();
                state = SLASH;
            } else {
                temp.push_back(_path[i]);
                state = NAME;
            }
        }

        inline void level_up() {
            if (result.size() == 1)
                return;
            result.pop_back();
            int N = result.size();
            for (int i = N - 1; i >= 0; i--) {
                if (result[i] != '/')
                    result.pop_back();
                else
                    break;
            }
        }
};

int main(void) {
    Solution s;
}