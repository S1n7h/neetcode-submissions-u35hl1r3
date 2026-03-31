class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, slow2 = 0;
        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast){
                break;
            }
        }while (true){
            slow2 = nums[slow2];
            slow = nums[slow];
            if (slow == slow2){
                return slow;
            }
        }
    }
};
