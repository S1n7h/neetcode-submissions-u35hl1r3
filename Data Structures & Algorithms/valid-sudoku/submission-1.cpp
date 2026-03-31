class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> hash;
        //checking horizontal lines
        for (int i = 0 ; i < 9 ; i++){
            hash.clear();
            for (int j = 0 ; j < 9 ; j++){
                if (board[i][j] == '.')  continue;
                if (hash.find(board[i][j]) != hash.end()){
                    return false;
                }
                char temp = board[i][j];
                hash[temp]++;
            }
        }hash.clear();
        //checking vertical lines
        for (int i = 0 ; i < 9 ; i++){
            hash.clear();
            for (int j = 0 ; j < 9 ; j++){
                if (board[j][i] == '.')  continue;
                if (hash.find(board[j][i]) != hash.end()){
                    return false;
                }
                char temp = board[j][i];
                hash[temp]++;
            }
        }hash.clear();

        int start[2] = {0,0};
        int i = 0 , j = 0;

        while(i < 9 && j < 9){     
            if (board[i][j] != '.'){
                if (hash.find(board[i][j]) != hash.end())
                    return false;
                hash[board[i][j]]++;
            }                
            if (i == 8 && j == 8)   break;
            if (i == start[0] + 2 && j == start[1] + 2){//corner
                if (j == 8){start[0] += 3; i = start[0]; start[1] = 0; j = start[1];}
                else{i = start[0]; start[1] += 3; j = start[1];}
                hash.clear();
            }else{ //not corners
                if (j == start[1] + 2){i += 1; j = start[1];}
                else{j++;}
            }
        }return true;
    }
};
