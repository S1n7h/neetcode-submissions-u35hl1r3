public class Solution {
    public int LongestOnes(int[] nums, int k) {
        int ret = 0;
        int l = 0;

        for(int i = 0 ; i < nums.Length ; i++){
            if (nums[i] == 0) k--;
            while(l <= i && k < 0){
                ret = Math.Max(ret, i - l);
                if (nums[l] == 0) k++;
                l++;
            }
        }

        ret = Math.Max(ret, nums.Length - l);
        return ret;
    }
}