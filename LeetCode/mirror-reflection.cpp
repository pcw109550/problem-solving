

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int gcd = __gcd(p, q);
        int l = p / gcd, r = q / gcd;
        if (l % 2 == 0)
            return 2;
        return r % 2 ? 1 : 0;
    }
};