class Solution {
    queue<pair<int, int>> q;
    int fresh_count = 0;
    int traversefresh_count = 0;
    int time = 0;
private:
    void Push(queue<pair<int, int>>& q, vector<vector<int>>& grid,
              int r, int c) {
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
            if (grid[r][c] == 1) {
                grid[r][c] = 2;          // rot immediately
                q.push({r, c});
                traversefresh_count++;
            }
        }
    }

    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        while (!q.empty()) {
            int Size = q.size();
            for (int i = 0; i < Size; i++) {
                auto [r, c] = q.front();
                q.pop();
                Push(q, grid, r+1, c);
                Push(q, grid, r-1, c);
                Push(q, grid, r, c+1);
                Push(q, grid, r, c-1);
            }if (!q.empty()) time++;  // only increment if more to process
            if (traversefresh_count == fresh_count) return;
        }
    }

    void helper(vector<vector<int>>& grid) {
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fresh_count++;
            }
        }
        bfs(q, grid);
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        helper(grid);
        if (fresh_count == 0) return 0;
        else if (fresh_count > traversefresh_count) return -1;
        else return time;
    }
};
