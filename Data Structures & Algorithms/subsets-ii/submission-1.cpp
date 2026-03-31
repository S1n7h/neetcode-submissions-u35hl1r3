class Solution {
    vector<vector<int>> ret;
private:
    void backtrack(vector<int>& nums, int start, vector<int>& res){
        if (start == nums.size()) {
            ret.push_back(res);
            return;
        }      

        // include the current num[start]
        res.push_back(nums[start]);
        backtrack(nums, start + 1, res);
        res.pop_back();

        //don't include the current nums[i] (duplicates)
        while(start + 1 < nums.size() && nums[start] == nums[start + 1]){
            start++;
        }backtrack(nums, start + 1, res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        backtrack(nums, 0, res);
        return ret;
    }
};
