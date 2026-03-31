public class Solution
{
    int Dfs(ref int[] coins, int amount, ref Dictionary<int, int> hoo)
    {
        if (amount == 0) return amount;
        if (hoo.ContainsKey(amount)) return hoo[amount];

        int ret = int.MaxValue;
        foreach(int coin in coins)
        {
            if (amount - coin >= 0)
            {
                int temp = Dfs(ref coins, amount - coin, ref hoo);
                if (temp != int.MaxValue)
                {
                    ret = Math.Min(ret, temp + 1);
                }
            }
        }
        hoo[amount] = ret;
        return ret;
    }

    public int CoinChange(int[] coins, int amount)
    {
        Dictionary<int, int> hoo = new Dictionary<int, int>(amount + 1);
        hoo[0] = 0;
        int ret = Dfs(ref coins, amount, ref hoo);
        return ret == int.MaxValue ? -1 : ret;
    }
}