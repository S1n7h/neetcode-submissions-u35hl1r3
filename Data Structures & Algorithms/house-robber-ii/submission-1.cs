public class Solution {
    public int Rob(int[] nums) {
        int l = 0 , r = 0;
        int ret = 0;
        if (nums.Length == 1)   return nums[0];
        for (int i = 0 ; i < nums.Length - 1; i++){
            int temp = r;
            r = Math.Max(l + nums[i], r);
            l = temp;
        }ret = Math.Max(r, l);

        r = l = 0;

        for (int i = 1 ; i < nums.Length ; i++){
            int temp = r;
            r = Math.Max(l + nums[i], r);
            l = temp;
        }return Math.Max(ret, Math.Max(r, l));
    }
}
