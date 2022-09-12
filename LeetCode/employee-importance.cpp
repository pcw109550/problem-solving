#include <iostream>
#include <vector>
using namespace std;

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    int result;
    unordered_map<int, Employee* > M;
public:
    int getImportance(vector<Employee*> employees, int id) {
        // O(N)
        result = 0;
        for (auto it : employees)
            M[it->id] = it;
        traverse(id);
        return result;
    }
    
    void traverse(int id) {
        result += M[id]->importance;
        for (auto it : M[id]->subordinates)
            traverse(it);
    }
};