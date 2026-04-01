public class Solution {
    public int MaxSubarraySumCircular(int[] nums) {
        int n = nums.Count();
        int sum = 0;
        foreach(var num in nums)    sum += num;
        
        int maxSum = nums[0];
        int minSum = nums[0];
        int curMax = 0;
        int curMin = 0;

        for(int i = 0 ; i < n ; i++){
            curMax = Math.Max(curMax, 0) + nums[i];
            curMin = Math.Min(curMin, 0) + nums[i];

            maxSum = Math.Max(curMax, maxSum);
            minSum = Math.Min(curMin, minSum);
        }

        if (sum == minSum)  return maxSum;
        return Math.Max(maxSum, sum - minSum);
    }
}