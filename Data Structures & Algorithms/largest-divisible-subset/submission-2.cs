public class Solution {
    public List<int> LargestDivisibleSubset(int[] nums) {
        Array.Sort(nums);

        //store highest at the end index
        int[] max_length = new int[nums.Length + 1];
        Array.Fill(max_length, 1);

        List<int> perma = new List<int>();
        List<int> temp = new List<int>();
        for(int i = 0 ; i < nums.Length ; i++) {
            Dfs(nums, max_length, i, 1, 1, temp, perma);
        }
        return perma;
    }

    void Dfs(int[] nums, int[] max_length, int idx, int curr_length, int div, List<int> temp, List<int> perma){
        if (idx == nums.Length){
            if (curr_length > max_length[idx]) {
                max_length[idx] = curr_length;
                perma.Clear();
                perma.AddRange(temp);
            }
            return;
        }

        //if maxlegnth up until that point is greater than curr_length, return
        if (max_length[idx] > curr_length) return; 

        max_length[idx] = curr_length;
        temp.Add(nums[idx]);

        for(int i = idx + 1 ; i < nums.Length + 1 ; i++){
            if (i == nums.Length || nums[i] % nums[idx] == 0){
                Dfs(nums, max_length, i, curr_length + 1, nums[idx], temp, perma);
            }
        }
        
        temp.RemoveAt(temp.Count() - 1);
        return;
    }
}