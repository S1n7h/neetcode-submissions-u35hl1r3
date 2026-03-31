class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int j = 0 ;
        ret.resize(nums.size() *nums.size());
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size() ; i++){
            if (nums[i] == nums[i-1] && i > 0)    continue;
            int l = i + 1 , r = nums.size() - 1;
            while (l < r){
                int target = -nums[i];                
                if (target < nums[r] + nums[l]){
                    r--;
                }else if (target > nums[r] + nums[l]){
                    l++;
                }
                else {
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[l];
                    temp[2] = nums[r];
                    ret[j] = temp;
                    j++;l++;r--;
                    while (l < r && l > i+1 && nums[l] == nums[l-1]) l++;
                }
            }
        }ret.resize(j); 
        return ret;
    }
};
