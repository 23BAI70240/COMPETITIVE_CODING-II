#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> h(n);
        for(auto& x : h) cin >> x;
        
        long long H = *max_element(h.begin(), h.end());
        
        auto check = [&](long long target) -> long long {
            long long needOdd = 0, needEven = 0;
            for(int i = 0; i < n; i++){
                long long d = target - h[i];
                needEven += d / 2;
                needOdd  += d % 2;
            }
            
            long long lo = 0, hi = 4e9;
            while(lo < hi){
                long long mid = (lo + hi) / 2;
                long long avEven = mid / 2;
                long long avOdd  = (mid + 1) / 2;
                
                long long useOdd = needOdd;
                long long useEven = needEven;
                
                if(useEven > avEven){
                    long long excess = useEven - avEven;
                    useOdd += excess * 2;
                    useEven = avEven;
                } else {
                    long long freeEven = avEven - useEven;
                    long long saved = min(freeEven, needOdd);
                    useOdd -= saved;
                    useEven += saved;
                }
                
                if(useEven <= avEven && useOdd <= avOdd)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            return lo;
        };
        
        cout << min(check(H), check(H+1)) << "\n";
    }
    return 0;
}