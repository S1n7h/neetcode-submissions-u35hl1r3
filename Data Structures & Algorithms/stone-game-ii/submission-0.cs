public class Solution {
    public int StoneGameII(int[] piles) {
        //(idx, limit)    stores the maximum number of stones alice can get at idx having a maximum of limit
        //idx is supposed to start from a pile, which she hasn't take, ie, there are limit number of piles after idx which she can take
        //this turn so, she can take idx -> idx + limit - 1
        Dictionary<(int, int), int> visited = new Dictionary<(int, int), int>();
        int[] prefixSum = new int[piles.Length + 1];
        for(int i = piles.Length - 1; i>= 0 ; i--){
            prefixSum[i] = prefixSum[i + 1] + piles[i];
        }
        return Dfs(piles, visited, prefixSum, 0, 1);
    }

    int Dfs(int[] piles, Dictionary<(int, int), int> visited, int[] prefixSum, int idx, int limit){
        if (visited.ContainsKey((idx, limit)))  return visited[(idx, limit)];
        if (idx >= piles.Length) return 0;

        int ret = 0;
        int total = 0;
        for(int i = 0; i < limit * 2 ; i++){
            if (idx + i >= piles.Length) break;
            int opponent = Dfs(piles, visited, prefixSum, idx + i + 1, Math.Max(limit, i + 1));
            ret = Math.Max(ret, prefixSum[idx] - opponent);         
        }
        visited[(idx, limit)] = ret;
        return ret;
    }
}