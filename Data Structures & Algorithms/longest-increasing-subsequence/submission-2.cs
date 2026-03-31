public class Solution
{
    public int LengthOfLIS(int[] nums)
    {
        Dictionary<int, int> visited = new Dictionary<int, int>();

        int ret = -1001;
        for (int i = 0; i < nums.Length; i++)
        {
            int path_length = Dfs(ref nums, nums[i], i, ref visited);
            ret = Math.Max(ret, path_length);
        }
        return ret;
    }
    int Dfs(ref int[] nums, int curr, int idx, ref Dictionary<int, int> visited)
    {
        if (visited.ContainsKey(idx))
        {
            return visited[idx];
        }
        for (int i = idx; i < nums.Length; i++)
        {
            if (nums[i] > curr)
            {
                int temp = Dfs(ref nums, nums[i], i, ref visited);
                if (!visited.ContainsKey(idx))
                {
                    visited[idx] = temp + 1;
                }
                else visited[idx] = Math.Max(visited[idx], temp + 1);
            }
        }
        if (!visited.ContainsKey(idx)) return 1;
        else return visited[idx];
    }
}