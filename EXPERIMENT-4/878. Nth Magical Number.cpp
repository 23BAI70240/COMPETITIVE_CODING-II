class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const long long MOD = 1e9 + 7;
        long long lcm = (long long)a / __gcd(a, b) * b;
        
        long long lo = 1, hi = (long long)n * min(a, b);
        while(lo < hi){
            long long mid = (lo + hi) / 2;
            if(mid/a + mid/b - mid/lcm >= n)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo % MOD;
    }
};