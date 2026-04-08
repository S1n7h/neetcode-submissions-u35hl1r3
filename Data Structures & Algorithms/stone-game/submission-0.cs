public class Solution {
    public bool StoneGame(int[] piles) {
        int n = piles.Length;
        Dictionary<(int, int), int> visited = new Dictionary<(int, int), int>();
        int ret = Dfs(piles, visited, 0, n - 1);
        int total = 0;
        foreach(var pile in piles) total += pile;
        if (ret > total - ret)    return true;
        return false;
    }

    //turn: 0-> alice 1-> bob
    int Dfs(int[] piles, Dictionary<(int, int), int> visited, int l, int r){
        if (visited.ContainsKey((l, r)))    return visited[(l, r)];
        if (l > r)  return 0;

        //turn = true (alice), false (bob)
        bool turn = (l + r + 1) % 2 == 0;

        int ret = 0;
        //alice's turn currently
        if (turn)   ret = Math.Max(Dfs(piles, visited, l + 1, r) + piles[l] , Dfs(piles, visited, l, r - 1) + piles[r]);
        else ret = Math.Max(Dfs(piles, visited, l + 1, r), Dfs(piles, visited, l, r - 1));

        visited[(l, r)] = ret;
        return visited[(l, r)];
    }
}