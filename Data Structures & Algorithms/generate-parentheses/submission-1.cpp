class Solution {
public:
    void backtrack(string current, int close, int open, int n, vector<string>& ret){
        if (close + open == 2*n){
            ret.push_back(current);
            return;
        }if (open < n){
            backtrack(current + "(", close, open + 1, n, ret);
        }if (close < open){
            backtrack(current + ")", close + 1, open, n, ret);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        backtrack("", 0, 0, n, ret);
        return ret;
    }
};
