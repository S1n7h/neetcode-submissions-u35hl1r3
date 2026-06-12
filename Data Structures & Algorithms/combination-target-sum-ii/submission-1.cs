public class Solution {
    public List<List<int>> CombinationSum2(int[] candidates, int target) {
        Array.Sort(candidates);
        foreach(var candidate in candidates) Console.WriteLine(candidate);
        List<List<int>> ret = new List<List<int>>();
        
        dfs(candidates, ref ret, new List<int>(), target, 0);
        return ret;
    }

    void dfs(int[] candidates, ref List<List<int>> ret, List<int> visited, int target, int idx){
        if (target == 0)  {
            ret.Add(new List<int>(visited));
            return;
        }if (target < 0) {            
            return;
        }
        if (idx >= candidates.Length) {          
            return;
        }
        
        int next_idx = idx;

        while(next_idx < candidates.Length && candidates[idx] == candidates[next_idx]) next_idx++;
        //skip current element
        dfs(candidates, ref ret, visited, target, next_idx);

        //take the current element
        visited.Add(candidates[idx]);
        dfs(candidates, ref ret, visited, target - candidates[idx], idx + 1);
        visited.RemoveAt(visited.Count - 1);
    }
}
