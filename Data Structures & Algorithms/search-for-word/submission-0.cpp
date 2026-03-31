class Solution {
private:
    bool backtrack(vector<vector<char>>& board, string& word, int column, int row, int idx){
        if (idx == word.size()) return true;

        if (row < 0 || column < 0 || row >= board.size() || column >= board[0].size() || 
            board[row][column] != word[idx])  
                return false;

        char temp = board[row][column];
        board[row][column] = '#';

        bool found = backtrack(board, word, column + 1, row, idx + 1) || backtrack(board, word, column - 1, row, idx + 1) 
                    || backtrack(board, word, column, row + 1, idx + 1) || backtrack(board, word, column, row - 1, idx + 1);

        board[row][column] = temp;

        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0 ; row < board.size() ; row++){
            for (int column = 0 ; column < board[0].size() ; column++){
                if (backtrack(board, word, column, row, 0)) return true;
            }
        }return false;
    }
};
