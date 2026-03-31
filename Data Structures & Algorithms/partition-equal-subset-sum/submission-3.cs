public class Solution {
    public bool CanPartition(int[] nums) {
        List<int> memo = new List<int>();

        int target = 0;
        foreach(int num in nums){
            target += num;
        }
        if (target%2 != 0)  return false;
        target /= 2;

        foreach(int num in nums){
            if (memo.Contains(target)) return true;
            
            int Size = memo.Count;
            memo.Add(num);
            for(int i = 0 ; i < Size ; i++){
                memo.Add(num + memo[i]);
            }            
        }if (memo.Contains(target)) return true;
        return false;
    }
}
