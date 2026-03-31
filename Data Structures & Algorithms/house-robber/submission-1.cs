public class Solution {
    public int Rob(int[] nums) {
        int l = 0 , r = 0;
        foreach (var num in nums)
        {
            int temp = r;
            r = Math.Max(num + l, r);
            l = temp;            
        }return Math.Max(l, r);
    }
}
