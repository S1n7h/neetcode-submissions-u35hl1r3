public class Solution {
    public int[] CountBits(int n) {
        var list = new List<int>();
        for (int i = 0 ; i <= n ; i++){
            int nums = i;
            int res = 0;
            while(nums != 0){
                if (nums % 2 == 1)  res++;
                nums /= 2;
            }list.Add(res);
        }return list.ToArray();
    }
}
