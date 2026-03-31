class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && target == nums[0])   return 0;
        if (nums.size() == 1 && target != nums[0])   return -1;
        int l = 0 , r = nums.size() - 1;
        
        while (l < r){
            int mid = (l + r) / 2;

            if (nums[mid] <= nums[r])   r = mid;
            else l = mid + 1;
        }// l points to the least int in nums

        int pivot = l;

        if (target > nums[nums.size() - 1]){
            int l = 0, r = pivot;

            while (l <= r){
                int mid = (l + r)/2;

                if (nums[mid] < target)    l = mid + 1;
                else if (nums[mid] > target) r = mid - 1;
                else return mid;
            }
        }else{
            int l = pivot, r = nums.size() - 1;

            while (l <= r){
                int mid = (l + r)/2;

                if (nums[mid] < target)    l = mid + 1;
                else if (nums[mid] > target) r = mid - 1;
                else return mid;
            }
        }return -1;
    }
};
