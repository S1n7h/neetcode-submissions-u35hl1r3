public class Solution {
    public bool StoneGame(int[] piles) {
        int n = piles.Length;
        int[,] dp = new int[n, n];
        for(int r = 0 ; r < n ; r++){
            for (int c = 0 ; c < n ; c++){
                dp[r, c] = -1;
            }
        }
        Dfs(piles, dp, 0, n - 1);
        int total = 0;
        foreach(var pile in piles)  total += pile;

        //since the dfs was called on 0, n - 1, it's going to be storing the maximum value
        if (dp[0, n - 1] > total - dp[0, n - 1])   return true;
        return false;
    }

    int Dfs(int[] piles, int[,] dp, int l, int r){
        if (l > r)  return 0; 
        if (dp[l, r] != -1) return dp[l, r];

        bool turn = (l + r + 1) % 2 == 0;
        if (turn){
            dp[l, r] = Math.Max(Dfs(piles, dp, l + 1, r) + piles[l], Dfs(piles, dp, l, r - 1) + piles[r]);
        }else dp[l, r] = Math.Max(Dfs(piles, dp, l + 1, r), Dfs(piles, dp, l, r - 1));
        
        return dp[l, r];
    }
}