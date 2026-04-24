class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if((int)connections.size() < n-1) return -1;
        
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        int components = n;
        for(auto& c : connections){
            int a = find(c[0]), b = find(c[1]);
            if(a != b){
                parent[a] = b;
                components--;
            }
        }
        
        return components - 1;
    }
};