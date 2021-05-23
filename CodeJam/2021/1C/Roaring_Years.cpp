#include <bits/stdc++.h>
using namespace std;

int isConsecutive(string str) {
	int start;
    int length = str.size();
	for (int i = 0; i < length / 2; i++) {
		string new_str = str.substr(0, i + 1);
		int num = atoi(new_str.c_str());
		start = num;
		while (new_str.size() < length) {
            num++;
			new_str = new_str + to_string(num);
		}
		if (new_str == str)
		    return start;
	}
	return -1;
}

int main() {
    vector<int> nums;
    int i = 1;
    while (true) {
        if (isConsecutive(to_string(i)) != -1) {
            nums.push_back(i);
            if (i >= 1000000)
                break;
        }
        i++;
    }
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int target; cin >> target;
        int result = *std::lower_bound(nums.begin(), nums.end(), target + 1);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
