class Solution {
    vector<vector<int>> ret;
private:
    void dfs(vector<int>& nums, int sum, int target, int start, vector<int>& res){
        if (target == sum){
            ret.push_back(res);
            return;
        }
        for (int i = start ; i < nums.size() ; i++){
            if (sum + nums[i] > target){
                break;
            }
            res.push_back(nums[i]);
            dfs(nums, sum + nums[i], target, i, res);
            res.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        dfs(nums, 0, target, 0, res);
        return ret;
    }
};
