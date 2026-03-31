class Solution {
public:
    int findMin(vector<int> &nums) {
        int t_min = INT_MAX;
        int l = 0 , r = nums.size() - 1;

        while (l <= r){
            int mid = (l + r)/2;

            if (nums[mid] <= nums[r]){
                r = mid - 1;
                t_min = min(t_min,nums[mid]);
            }else l = mid + 1;
        }return t_min;
    }
};
