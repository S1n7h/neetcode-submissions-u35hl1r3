class Solution {
    vector<string> ret;
    vector<string> digitToChar = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
private:
    void backtrack(string& digits, string& res, int idx){
        if (idx >= digits.size()){
            ret.push_back(res);
            return;
        }
        for (int i = 0 ; i < digitToChar[digits[idx] - '0'].size() ; i++){
            res += digitToChar[digits[idx] - '0'][i];
            backtrack(digits, res, idx + 1);
            res.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ret;
        string res = "";
        backtrack(digits, res, 0);
        return ret;
    }
};
