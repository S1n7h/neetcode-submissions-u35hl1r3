public class Solution {
    public bool Makesquare(int[] matchsticks) {
        if (matchsticks.Length < 4) return false;

        return backtracking(matchsticks, 0, 0, 0, 0, 0);
    }

    bool backtracking(int[] matchsticks, int idx, int u, int r, int b, int l){
        if (idx >= matchsticks.Length){
            if (u == r && r == b && b == l && l == u)   return true;
            else return false;
        }    

        return (backtracking(matchsticks, idx + 1, u + matchsticks[idx], r, b, l) ||
                backtracking(matchsticks, idx + 1, u, r + matchsticks[idx], b, l) ||
                backtracking(matchsticks, idx + 1, u, r, b + matchsticks[idx], l) ||
                backtracking(matchsticks, idx + 1, u, r, b, l + matchsticks[idx]));
    }
}