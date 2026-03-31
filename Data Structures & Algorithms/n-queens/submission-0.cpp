class Solution {
    vector<vector<string>> ret;
private:
    void backtrack(unordered_map<int, int>& column, 
                    unordered_map<int, int>& diag,
                    unordered_map<int, int>& diag2, 
                    vector<string>& str, int row, int& n){
        if (row == n){
            ret.push_back(str);
            return;
        }

        for (int i = 0 ; i < n ; i++){
            if (column.find(i) == column.end() && diag.find(row - i) == diag.end() && diag2.find(row + i) == diag.end()){
                column[i]++;
                diag[row - i]++;
                diag2[row + i]++;
                string temp = "";
                for (int j = 0 ; j < n ; j++){
                    if (j == i) temp += 'Q';
                    else temp += '.';
                }str.push_back(temp);
                backtrack(column, diag, diag2, str, row + 1, n);
                column.erase(i);
                diag.erase(row - i);
                diag2.erase(row + i);
                str.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_map<int, int> column;
        unordered_map<int, int> diag;
        unordered_map<int, int> diag2;
        vector<string> str;
        backtrack(column, diag, diag2, str, 0, n);
        return ret;
    }
};
