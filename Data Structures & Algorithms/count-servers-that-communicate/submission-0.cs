public class Solution {
    public int CountServers(int[][] grid) {
        int ret = 0;
        Queue<(int row, int column)> q = new Queue<(int row, int column)>();
        Dictionary<(int, int), bool> visited = new Dictionary<(int, int), bool>();
        for(int r = 0 ; r < grid.Length ; r++){
            for(int c = 0 ; c < grid[0].Length ; c++){
                q.Enqueue((r,c));
                while(q.Count != 0){
                    var top = q.Dequeue();
                    if (grid[top.row][top.column] == 0 || visited.ContainsKey((top.row, top.column))) continue;
                    visited[(top.row, top.column)] = true;
                    
                    for(int i = 0 ; i < grid.Length ; i++){
                        if (grid[i][top.column] == 1 && i != top.row) q.Enqueue((i, top.column));
                    }for(int i = 0 ; i < grid[0].Length ; i++){
                        if (grid[top.row][i] == 1 && i != top.column) q.Enqueue((top.row, i));
                    }
                    if (q.Count != 0) ret++;
                }
            }
        }return ret;
    }
}