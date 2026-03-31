class Solution {
private:
    void dfs(int& node, vector<vector<int>>& adj, vector<bool>& passed){
        if (passed[node] == true) return;
        passed[node] = true;

        for(auto& subnode : adj[node]){
            dfs(subnode, adj, passed);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> passed(n, false);
        int ret = 0;

        for (auto& pair : edges){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        for (int i = 0 ; i < n ; i++){
            if (passed[i] == false){
                dfs(i, adj, passed);
                ret++;
            }
        }
        return ret;
    }
};
