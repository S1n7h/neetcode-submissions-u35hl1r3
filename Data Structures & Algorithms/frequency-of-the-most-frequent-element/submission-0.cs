public class Solution {
    public int MaxFrequency(int[] nums, int k) {
        Array.Sort(nums);
        int l = 0;
        long total = 0;
        int ret = 0;
        for(int i = 0 ; i < nums.Length ; i++){
            total += nums[i];
            while(nums[i] * (i - l + 1) > total + k){
                total -= nums[l];
                l++;
            }ret = Math.Max(ret, (i - l + 1)); 
        }return ret;
    }
}