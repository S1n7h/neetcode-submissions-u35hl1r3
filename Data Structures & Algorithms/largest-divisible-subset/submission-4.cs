public class Solution {
    public List<int> LargestDivisibleSubset(int[] nums) {
        Dictionary<int, List<int>> dict = new Dictionary<int, List<int>>();

        Array.Sort(nums);
        List<int> ret = new List<int>();

        for(int i = 0 ; i < nums.Length ; i++){
            var temp = Dfs(nums, dict, i);
            if (ret.Count < temp.Count){
                ret.Clear();
                ret.AddRange(temp);
            }
        }return ret;
    }

    List<int> Dfs(int[] nums, Dictionary<int, List<int>> dict, int idx){
        if (idx == nums.Length - 1) return new List<int> {nums[idx]};

        if (dict.ContainsKey(idx)) return dict[idx];

        List<int> ret = new List<int>();
        ret.Add(nums[idx]);
        
        List<int> actualTemp = new List<int>();
        for(int i = idx + 1 ; i < nums.Length ; i++){
            //check divisibility
            if (nums[i] % nums[idx] == 0){
                var temp = Dfs(nums, dict, i);
                if (temp.Count > actualTemp.Count){
                    actualTemp.Clear();
                    actualTemp.AddRange(temp);
                }
            }
        }
        ret.AddRange(actualTemp);

        dict[idx] = ret;
        return ret;
    }
}