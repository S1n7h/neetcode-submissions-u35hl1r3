public class Solution {
    public bool CanJump(int[] nums) {
        int goalIndex = nums.Length - 1;

        for (int curr_idx = nums.Length - 2 ; curr_idx >= 0 ; curr_idx--){
            if (nums[curr_idx] + curr_idx < goalIndex)
                continue;
            goalIndex = curr_idx;
        }if (goalIndex == 0)    return true;
        return false;
    }
}
