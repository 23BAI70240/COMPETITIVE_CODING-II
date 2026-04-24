#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    
    int sumA = 0;
    double totalB = 0;
    for(int i = 0; i < n; i++){ sumA += a[i]; totalB += b[i]; }
    
    const double NEG = -1e18;
    vector<vector<double>> dp(n+1, vector<double>(sumA+1, NEG));
    dp[0][0] = 0;
    
    for(int i = 0; i < n; i++){
        for(int k = min(i+1,n); k >= 1; k--){
            for(int ca = a[i]; ca <= sumA; ca++){
                if(dp[k-1][ca-a[i]] > NEG)
                    dp[k][ca] = max(dp[k][ca], dp[k-1][ca-a[i]] + b[i]);
            }
        }
    }
    
    for(int k = 1; k <= n; k++){
        double ans = 0;
        for(int ca = 0; ca <= sumA; ca++){
            if(dp[k][ca] > NEG){
                double win = dp[k][ca];
                double wout = totalB - win;
                double val = min((double)ca, win + wout/2.0);
                ans = max(ans, val);
            }
        }
        cout << fixed << setprecision(10) << ans;
        if(k < n) cout << ' ';
    }
    cout << '\n';
    
    return 0;
}