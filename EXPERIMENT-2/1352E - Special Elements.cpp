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
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        vector<bool> isSum(n+1, false);
        
        for(int l = 0; l < n; l++){
            int sum = 0;
            for(int r = l; r < n; r++){
                sum += a[r];
                if(sum > n) break;
                if(r > l) isSum[sum] = true;
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            if(isSum[a[i]]) count++;
        }
        cout << count << "\n";
    }
    return 0;
}