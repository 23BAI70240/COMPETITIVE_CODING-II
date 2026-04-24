#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> L(n), R(n);
    vector<long long> coords;
    
    for(int i = 0; i < n; i++){
        cin >> L[i] >> R[i];
        coords.push_back(L[i]);
        coords.push_back(R[i] + 1);
    }
    
 
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    int m = coords.size();
    
 
    vector<int> diff(m + 1, 0);
    for(int i = 0; i < n; i++){
        int a = lower_bound(coords.begin(), coords.end(), L[i])   - coords.begin();
        int b = lower_bound(coords.begin(), coords.end(), R[i]+1) - coords.begin();
        diff[a]++;
        diff[b]--;
    }
    
    vector<long long> ans(n + 1, 0);
    int cur = 0;
    for(int i = 0; i < m - 1; i++){
        cur += diff[i];
        if(cur >= 1 && cur <= n){
            long long len = coords[i+1] - coords[i];
            ans[cur] += len;
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << ans[i];
        if(i < n) cout << ' ';
    }
    cout << '\n';
    
    return 0;
}