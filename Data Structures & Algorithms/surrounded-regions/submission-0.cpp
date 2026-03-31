class Solution {
private:
    void changetoT(vector<vector<char>>& board, int r, int c){
        if (board[r][c] != 'O') return;
        board[r][c] = 'T';
        if (r + 1 < board.size()){
            if (board[r+1][c] == 'O'){
                changetoT(board, r + 1, c);
            }
        }if (c + 1 < board[0].size()){
            if (board[r][c+1] == 'O'){
                changetoT(board, r, c + 1);
            }
        }if (r - 1 >= 0){
            if (board[r-1][c] == 'O'){
                changetoT(board, r - 1, c);
            }
        }if (c - 1 >= 0){
            if (board[r][c-1] == 'O'){
                changetoT(board, r, c - 1);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        for (int r = 0 ; r < board.size() ; r++){
            changetoT(board, r, 0);
            changetoT(board, r, board[0].size() - 1);
        }for (int c = 0 ; c < board[0].size() ; c++){
            changetoT(board, 0, c);
            changetoT(board, board.size() - 1, c);
        }
        for (int r = 0 ; r < board.size() ; r++){
            for (int c = 0 ; c < board[0].size() ; c++){
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
};
