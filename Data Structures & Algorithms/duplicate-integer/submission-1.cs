public class Solution {
    public bool hasDuplicate(int[] nums) {
        HashSet<int> hash = new HashSet<int>();
        foreach(var num in nums){
            if (hash.Contains(num)) return true;
            hash.Add(num);
        }return false;
    }
}