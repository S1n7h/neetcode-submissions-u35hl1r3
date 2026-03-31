class Solution {
private:
    void dfsfromchest(vector<vector<int>>& grid, int r, int c, int distance){
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())  return;
        if (grid[r][c] == -1)   return;

        if (distance > grid[r][c])  return;

        grid[r][c] = distance;
        distance++;
        dfsfromchest(grid, r + 1, c, distance);
        dfsfromchest(grid, r - 1, c, distance);
        dfsfromchest(grid, r, c + 1, distance);
        dfsfromchest(grid, r, c - 1, distance);
    }

    void helper(vector<vector<int>>& grid, int row, int column){
        for (int r = 0 ; r < grid.size() ; r++){
            for (int c = 0 ; c < grid[0].size() ; c++){
                if (grid[r][c] == 0){
                    int distance = 0;
                    dfsfromchest(grid, r, c, distance);
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        helper(grid, grid.size(), grid[0].size());
    }
};
