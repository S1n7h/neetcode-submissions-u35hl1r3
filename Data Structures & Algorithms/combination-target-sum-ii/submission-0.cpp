class Solution {
    vector<vector<int>> ret;
private:
    void backtrack(vector<int>& candidates, int target, int sum, int start, vector<int> res){
        if (sum == target){
            ret.push_back(res);
            return;
        }
        for (int i = start; i < candidates.size() ; i++){
            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (sum + candidates[i] > target){
                break;
            }
            res.push_back(candidates[i]);
            backtrack(candidates, target, sum + candidates[i], i + 1, res);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> res;
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, 0 /* start */, res);
        return ret;
    }
};
