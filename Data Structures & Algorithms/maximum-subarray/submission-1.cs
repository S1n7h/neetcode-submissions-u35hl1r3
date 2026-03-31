public class Solution {
    public int MaxSubArray(int[] nums) {
        if (nums.Length == 1)   return nums[0];
        List<int> prefix = new List<int> ();

        prefix.Add(0);
        int sum = nums[0];

        int ret = int.MinValue;
        for (int i = 1 ; i < nums.Length ; i++){
            prefix.Add(sum);

            //sum updates to sum till this point, including this item
            sum += nums[i];

            for (int j = 0 ; j < prefix.Count ; j++){
                ret = Math.Max(ret, sum - prefix[j]);
            }ret = Math.Max(ret, sum - nums[i]);
        }
        return ret;
    }
}
