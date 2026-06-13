public class Solution {
    public int MaxCoins(int[] nums) {
        Dictionary<(int, int), int> dp = new Dictionary<(int, int), int>();
        int[] new_nums = new int[nums.Length + 2];
        new_nums[0] = 1;
        new_nums[nums.Length + 1] = 1;
        int idx = 1;
        foreach(var num in nums){
            new_nums[idx++] = num;
        }
        return dfs(dp, new_nums, 1, nums.Length);
    }

    int dfs(Dictionary<(int, int), int> dp, int[] nums, int l, int r){
        if (l > r) return 0;
        if (dp.ContainsKey((l, r))) return dp[(l, r)];

        int ret = 0;
        for(int i = l ; i <= r ; i++){
            int coins = nums[l - 1] * nums[i] * nums[r + 1];
            coins += dfs(dp, nums, l, i - 1) + dfs(dp, nums, i + 1, r);
            ret = Math.Max(ret, coins);
        }
        return dp[(l, r)] = ret;
    }
}
