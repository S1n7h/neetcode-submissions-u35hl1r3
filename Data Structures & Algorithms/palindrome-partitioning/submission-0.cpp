class Solution {
    vector<vector<string>> ret;
private:
    bool palindrome(string& s, int l, int r){
        while (l < r){
            if (s[l] != s[r])   return false;
            l++;
            r--;
        }return true;
    }

    void backtrack(string s, int start, vector<string>& res){
        if (start >= s.size()){
            ret.push_back(res);
            return;
        }

        for (int i = start ; i < s.size() ; i++){
            if (palindrome(s, start, i)){
                res.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, res);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> res;
        backtrack(s, 0, res);
        return ret;
    }
};
