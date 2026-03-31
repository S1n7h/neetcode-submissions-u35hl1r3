public class Solution {
    public bool IsHappy(int n) {
        var computed = new List<int>();
        while (n != 1){
            if (computed.Contains(SumofSquares(n)))  return false;
            computed.Add(n);
            n = SumofSquares(n);
        }return true;
    }

    public int SumofSquares(int n){
        if (n <= 0) return 0;
        int ret = (n%10) * (n%10) + SumofSquares(n/10);
        return ret;
    }
}
