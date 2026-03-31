class Solution {
private:
    bool isCycle(vector<vector<int>>& neighbours, vector<bool>& visited, int parent, int child){
        visited[child] = true;
        for(auto& neighbour : neighbours[child]){
            if (!visited[neighbour]) {
                if(isCycle(neighbours, visited, child, neighbour)) //if the neighbour of the child has not been visited
                    return true;
            }
            else{
                if (neighbour == parent)    continue;
                else{   
                    if (visited[neighbour] == true) return true;
                    return false;
                }
            }
        }return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> neighbours(edges.size() + 1);
        vector<int> ret;
        for (auto& pair : edges){
            neighbours[pair[0]].push_back(pair[1]);
            neighbours[pair[1]].push_back(pair[0]);
            vector<bool> visited(edges.size() + 1, false);
            if (isCycle(neighbours, visited, -1, pair[0]) == true){
                ret = {pair[0], pair[1]};
                neighbours[pair[0]].pop_back();
                neighbours[pair[1]].pop_back();
            }
        }return ret;
    }
};
