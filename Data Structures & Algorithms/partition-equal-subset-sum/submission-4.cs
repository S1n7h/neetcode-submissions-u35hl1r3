public class Solution {
    public bool CanPartition(int[] nums) {
        if (nums.Sum() % 2 != 0) return false;
        // bool[] visited = new bool[nums.Length];
        // Array.Fill(visited, false);
        Dictionary<(int, int), bool> dp = new Dictionary<(int, int), bool>();
        
        return dfs(nums, dp, 0, nums.Sum() / 2);
    }

    bool dfs(int[] nums, Dictionary<(int, int), bool> dp, int idx, int target){
        if (target == 0) return true;
        if (idx == nums.Length || target < 0) return false;
        if (dp.ContainsKey((idx, target))) return dp[(idx, target)];

        //skip current number
        bool ret = dfs(nums, dp, idx + 1, target);

        //take current number
        ret = ret || dfs(nums, dp, idx + 1, target - nums[idx]);

        dp[(idx, target)] = ret;
        return ret;
    }
}
