class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size());
        unordered_map<int, int> prefix;
        unordered_map<int, int> suffix;
        prefix[0] = 1;
        suffix[nums.size() - 1] = 1;
        int product = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            product *= nums[i-1];
            prefix[i] = product;
        }product = 1;
        for(int i = nums.size() - 2 ; i > -1 ; i--){
            product *= nums[i+1];
            suffix[i] = product;
        }
        for (int i = 0 ; i < nums.size() ; i++){
            ret[i] = prefix[i] * suffix[i];
        }return ret;
    }
};
