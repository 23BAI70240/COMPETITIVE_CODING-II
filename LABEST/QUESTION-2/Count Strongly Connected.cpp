class Solution {
    void dfs1(int node, vector<bool>& visited, vector<vector<int>>& adj, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node])
            if (!visited[neighbor])
                dfs1(neighbor, visited, adj, st);
        st.push(node);
    }

    void dfs2(int node, vector<bool>& visited, vector<vector<int>>& transpose) {
        visited[node] = true;
        for (int neighbor : transpose[node])
            if (!visited[neighbor])
                dfs2(neighbor, visited, transpose);
    }

public:
    int kosaraju(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]);


        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs1(i, visited, adj, st);
 
        vector<vector<int>> transpose(V);
        for (int i = 0; i < V; i++)
            for (int neighbor : adj[i])
                transpose[neighbor].push_back(i);

     
        fill(visited.begin(), visited.end(), false);
        int count = 0;
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!visited[node]) {
                dfs2(node, visited, transpose);
                count++;
            }
        }

        return count;
    }
};