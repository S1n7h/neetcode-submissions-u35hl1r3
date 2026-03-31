class Solution {
private:
    vector<vector<int>> ret; 
    void dfs(vector<vector<int>>& heights, int r, int c, int& sum){
        if (sum == 3)   return;
        if ( r - 1 < 0 || c - 1 < 0){ //pacific
            if (sum == 2 || sum == 0){  //either atlantic visited or not visited it
                sum++;
            }
        }if (r + 1 >= heights.size() || c + 1 >= heights[0].size()){
            if (sum == 0 || sum == 1){  //either visited pacific or not visited it
                sum++;sum++;
            }
        }if (sum == 3) return;

        if (r + 1 < heights.size())
            if(heights[r+1][c] != -1 && heights[r+1][c] <= heights[r][c]){
                int temp = heights[r][c];
                heights[r][c] = -1;
                dfs(heights, r + 1, c, sum);
                heights[r][c] = temp;
            }
        if (r - 1 >= 0) 
            if(heights[r-1][c] != -1 && heights[r-1][c] <= heights[r][c]){
                int temp = heights[r][c];
                heights[r][c] = -1;
                dfs(heights, r - 1, c, sum);
                heights[r][c] = temp;
            }
        if (c + 1 < heights[0].size())
            if(heights[r][c+1] != -1 && heights[r][c+1] <= heights[r][c]){
                int temp = heights[r][c];
                heights[r][c] = -1;
                dfs(heights, r, c + 1, sum);
                heights[r][c] = temp;
            }
        if (c - 1 >= 0)
            if(heights[r][c-1] != -1 && heights[r][c-1] <= heights[r][c]){
                int temp = heights[r][c];
                heights[r][c] = -1;
                dfs(heights, r, c - 1, sum);
                heights[r][c] = temp;
            }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        for (int r = 0 ; r < heights.size() ; r++){
            for (int c = 0 ; c < heights[0].size() ; c++){
                int sum = 0;
                dfs(heights, r, c, sum);
                if (sum == 3){
                    ret.push_back({r,c});
                }
            }
        }return ret;
    }
};
