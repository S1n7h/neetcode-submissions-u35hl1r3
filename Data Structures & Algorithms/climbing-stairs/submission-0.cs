public class Solution {
    int dfs(int n, int curr){
        if (curr > n)   return 0;
        if (curr == n)  return 1;

        int left = dfs(n, curr + 1);
        int right = dfs(n, curr + 2);

        return left + right;
    }
    public int ClimbStairs(int n) {     
        return dfs(n - 1, -1);
    }
}
