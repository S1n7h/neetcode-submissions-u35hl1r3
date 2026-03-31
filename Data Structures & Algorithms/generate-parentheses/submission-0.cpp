class Solution {
public:
    void backtrack(string current, int open, int close, int n, vector<string>& ret){
        if (open + close == 2*n){
            ret.push_back(current);
        }
        if (open < n){
            backtrack(current + "(",  open + 1, close, n, ret);
            
        }if (close < open){
            backtrack(current + ")", open, close + 1, n, ret);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        backtrack("", 0, 0, n, ret);
        return ret;        
    }
};
