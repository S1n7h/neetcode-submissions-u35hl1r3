class Solution {
private:
    int ret = 0;
    void recurse(vector<vector<int>>& grid, int r, int c, int& area){
        if (r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 ||
            grid[r][c] == 0)    return;

        area++;
        grid[r][c] = 0;

        recurse(grid, r + 1, c, area);
        recurse(grid, r - 1, c, area);
        recurse(grid, r , c + 1, area);
        recurse(grid, r , c - 1, area);

        ret = max(ret, area);
    }

    void helper(vector<vector<int>>& grid){
        for (int r = 0 ; r < grid.size() ; r++){
            for (int c = 0 ; c < grid[0].size() ; c++){
                int t_area = 0;
                if (grid[r][c] == 1) recurse(grid, r, c, t_area);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())   return ret;
        helper(grid);
        return ret;
    }
};
