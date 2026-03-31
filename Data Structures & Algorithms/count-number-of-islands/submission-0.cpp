class Solution {
private:
    int ret = 0;
    void backtrack(vector<vector<char>>& grid, int row, int column){
        if (row >= grid.size() || column >= grid[0].size() || row < 0 || column < 0 ||
            grid[row][column] == '0' || grid[row][column] == '#') return;
        
        if (grid[row][column] == '1'){
            grid[row][column] = '#';
        }
        backtrack(grid, row + 1, column);
        backtrack(grid, row - 1, column);
        backtrack(grid, row, column + 1);
        backtrack(grid, row, column - 1);
    }

    void helper(vector<vector<char>>& grid){
        for (int row = 0 ; row < grid.size() ; row++){
            for (int column =  0 ; column < grid[0].size() ; column++){
                if (grid[row][column] == '1'){
                    ret++;
                    backtrack(grid, row, column);
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())   return ret;
        helper(grid);
        return ret;
    }
};
