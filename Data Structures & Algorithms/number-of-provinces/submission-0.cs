public class Solution {
    public int FindCircleNum(int[][] isConnected) {
        bool[] visited = new bool[isConnected.Length];
        int ret = 0;
        for(int i = 0 ; i < isConnected.Length ; i++){
            if (!visited[i]){
                Dfs(i, visited, isConnected);
                ret++;
            }
        }return ret;
    }

    void Dfs(int node, bool[] visited, int[][] isConnected){
        if (visited[node]) return;

        visited[node] = true;
        for(int i = 0 ; i < isConnected.Length ; i++){
            if (isConnected[node][i] == 1 && !visited[i]) 
                Dfs(i, visited, isConnected);
        }
    }
}