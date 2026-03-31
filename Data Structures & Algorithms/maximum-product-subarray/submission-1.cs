public class Solution {
    public int MaxProduct(int[] nums) {
        int ret = nums[0];
        int max = 1, min = 1;

        foreach(int num in nums){
            int temp = max * num;
            max = Math.Max(Math.Max(temp, min * num), num);
            min = Math.Min(Math.Min(temp, min * num), num);
            ret = Math.Max(ret, max);
        }return ret;
    }
}
