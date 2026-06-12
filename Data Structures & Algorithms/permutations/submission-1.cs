public class Solution {
    public List<List<int>> Permute(int[] nums) {
        bool[] visited = new bool[nums.Length];
        Array.Fill(visited, false);
        
        List<List<int>> ret = new List<List<int>>();

        dfs(nums, 0, new List<int>(), ref ret, visited);
        return ret;
    }

    void dfs(int[] nums, int count, List<int> visit, ref List<List<int>> ret, bool[] visited){
        if (count == nums.Length){
            ret.Add(new List<int>(visit));
            return;
        }

        for(int i = 0 ; i < nums.Length ; i++){
            if (visited[i]) continue;
            visit.Add(nums[i]);
            visited[i] = true;
            dfs(nums, count + 1, visit, ref ret, visited);
            visit.RemoveAt(visit.Count - 1);
            visited[i] = false;
        }
    }
}
