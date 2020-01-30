#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, y, z; cin >> x >> y >> z;    
    int a = min(x, min(y, z));
    int b = max(x, max(y, z));
    cout << a << " " << (x + y + z - a - b) << " " << b;
}