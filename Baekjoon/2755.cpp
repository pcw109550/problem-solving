#include<bits/stdc++.h>
using namespace std;

double convert(string s) {
    double grade;
    if (s[0] == 'F')
        return 0.0;
    switch (s[0]) {
        case 'A':
            grade = 4.0;
            break;
        case 'B':
            grade = 3.0;
            break;
        case 'C':
            grade = 2.0;
            break;
        case 'D':
            grade = 1.0;
            break;
        default:
            assert(false);
    }
    switch (s[1]) {
        case '+':
            grade += 0.3;
            break;
        case '0':    
            break;
        case '-':
            grade -= 0.3;
            break;
        default:
            assert(false);
    }
    return grade;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, num_credit, total_credit = 0;
    string s, grade;
    cin >> N;
    double sum = 0.0;
    while (N--) {
        cin >> s >> num_credit >> grade;
        sum += static_cast<double>(num_credit) * convert(grade);
        total_credit += num_credit;
    }
    double result = round(sum * 100.0 / static_cast<double>(total_credit)) / 100.0;
    if (sum == 0.0) {
        cout << "0.00";
        return 0;
    } else if (static_cast<int>(result) == result) {
        cout << result << ".00";
        return 0;
    }
    cout << left << setfill('0') << setw(4) << result;
}