class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int b : batteries) sum += b;
        
        sort(batteries.rbegin(), batteries.rend());
        
        long long lo = 1, hi = sum / n;
        
        for(int i = 0; i < (int)batteries.size(); i++){
            if(batteries[i] > hi){
                sum -= batteries[i];
                n--;
                hi = sum / n;
            } else break;
        }
        
        return sum / n;
    }
};