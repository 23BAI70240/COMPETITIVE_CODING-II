#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    const long long MOD1 = 1e9+7, MOD2 = 1e9+9;
    const long long BASE1 = 131, BASE2 = 137;
    
    unordered_map<int, vector<pair<long long,long long>>> byLen;
    
    vector<string> strs(n);
    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }
    
    int maxLen = 0;
    for(auto& s : strs) maxLen = max(maxLen, (int)s.size());
    
    vector<long long> pw1(maxLen+1), pw2(maxLen+1);
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i <= maxLen; i++){
        pw1[i] = pw1[i-1] * BASE1 % MOD1;
        pw2[i] = pw2[i-1] * BASE2 % MOD2;
    }
    
    auto getHash = [&](const string& s) -> pair<long long,long long> {
        long long h1 = 0, h2 = 0;
        for(char c : s){
            h1 = (h1 * BASE1 + c) % MOD1;
            h2 = (h2 * BASE2 + c) % MOD2;
        }
        return {h1, h2};
    };
    
    set<pair<long long,long long>> hashSet;
    
    for(auto& s : strs){
        hashSet.insert(getHash(s));
        byLen[s.size()].push_back(getHash(s));
    }
    
    for(int q = 0; q < m; q++){
        string s;
        cin >> s;
        int len = s.size();
        
        if(byLen.find(len) == byLen.end()){
            cout << "NO\n";
            continue;
        }
        
        vector<long long> pre1(len+1,0), pre2(len+1,0);
        for(int i = 0; i < len; i++){
            pre1[i+1] = (pre1[i] * BASE1 + s[i]) % MOD1;
            pre2[i+1] = (pre2[i] * BASE2 + s[i]) % MOD2;
        }
        
        auto getRange = [&](int l, int r) -> pair<long long,long long> {
            int rlen = r - l;
            long long h1 = (pre1[r] - pre1[l] * pw1[rlen] % MOD1 + MOD1*2) % MOD1;
            long long h2 = (pre2[r] - pre2[l] * pw2[rlen] % MOD2 + MOD2*2) % MOD2;
            return {h1, h2};
        };
        
        bool found = false;
        for(char rep = 'a'; rep <= 'c' && !found; rep++){
            for(int i = 0; i < len && !found; i++){
                if(s[i] == rep) continue;
                auto [lh1, lh2] = getRange(0, i);
                auto [rh1, rh2] = getRange(i+1, len);
                
                long long h1 = (lh1 * pw1[len-i] % MOD1 + (long long)rep * pw1[len-i-1] % MOD1 + rh1) % MOD1;
                long long h2 = (lh2 * pw2[len-i] % MOD2 + (long long)rep * pw2[len-i-1] % MOD2 + rh2) % MOD2;
                
                if(hashSet.count({h1, h2})) found = true;
            }
        }
        
        cout << (found ? "YES" : "NO") << "\n";
    }
    
    return 0;
}