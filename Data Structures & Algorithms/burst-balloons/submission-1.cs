public class Solution {
    public int MaxCoins(int[] nums) {
        var dp = new int[nums.Length + 2, nums.Length + 2];
        var new_nums = new int[nums.Length + 2];

        new_nums[0] = new_nums[new_nums.Length - 1] = 1;
        
        for (int i = 0 ; i < nums.Length  ; i++)    new_nums[i + 1] = nums[i];

        return DfsWithDp(dp, new_nums, 1, new_nums.Length - 2);
    }

    int DfsWithDp(int[,] dp, int[] new_nums, int l, int r){
        if (l > r)  return 0;

        if (dp[l, r] != 0) return dp[l, r];

        int ret = 0;

        for (int idx = l ; idx < r + 1 ; idx++){
            int product = new_nums[l - 1] * new_nums[idx] * new_nums[r + 1];

            product += DfsWithDp(dp, new_nums, idx + 1, r) + DfsWithDp(dp, new_nums, l, idx - 1);
            ret = Math.Max(ret, product);
        }
        dp[l, r] = ret;
        return dp[l, r];
    }
}
