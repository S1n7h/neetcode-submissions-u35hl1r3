public class Solution {
    public int NumSubarrayProductLessThanK(int[] nums, int k) {
        if (k == 0) return 0;

        int ret = 0;
        int l = 0;
        int product = 1;
        for(int i = 0 ; i < nums.Length ; i++){
            product = nums[i] * product;
            while(l <= i && product >= k){
                product /= nums[l];
                l++;
            }ret += i - l + 1;
        }return ret;
    }
}