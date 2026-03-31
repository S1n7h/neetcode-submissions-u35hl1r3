//the main idea of the solution is to find out what is the minimum number of coins required to achieve the value of every number before the amount.
//so, for example, if the total amount were to be 5, we would want to find out what is the number of coins required to achieve 0,1,2,3,4 and 5.
//0 is going to have a value of 0 stored in the dp for obvious reasons. Now, the way we find out the minimum number of coins required for every amount
//is to bottom up approach wherein, we start from 1 all the way upto 5. for every amount, we take one of the coins(from the coins array) so that means,
//we already take 1 coin. and for the remaining amount, ie , the value we took - the coin's value, we find out whether it is below 0 or not, if it's not
//below 0, it means that such a index is already present in the dp, so we find out the value stored at that idx. We then compare this value to the value
//already stored in that location in the dp. We do this for every coin which we can take.

//if coins = [1,5,10]
//amount = 6
//and dp = [0,7,7,7,7,7,7]

//for every one of these index, we find out what is the minimum number of coins required to reach the value of the idx
//to reach 1, we only require coin 1 so, dp = [0,1,7,7,7,7,7]
//to reach 2, we only have 1 coin whose value is less than 2 (1), so, we HAVE to take 2 coins of value 1. so, dp = [0,1,2,7,7,7,7]
//to reach 3 and 4 we require 3 and 4 coins of value 1 , so dp = [0,1,2,3,4,7,7]
//to reach 5, we need only one coin of value 5 so, dp = [0,1,2,3,4,1,7]
//to reach the amount 6, we calculate to situations, one, where we take just one coin of value 1
//we find that, the remaining value becomes 6, so we check the dp and see that at index 6, there is an entry (1). so, we require only 2 coins.
//we do the same with 5, we check how much is needed to reach the value 1 (since we take one coin of value 5) and then we check the dp at index 1, 
//which has the value 1. so even here, we require 2 coins. since the minimum of both the situations is 2, we require 2 coins to reach 6.
public class Solution {
    public int CoinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Array.Fill(dp, amount + 1);
        dp[0] = 0;
        
        for (int i = 1 ; i <= amount ; i++){
            foreach(int coin in coins){
                if (i - coin >= 0){
                    dp[i] = Math.Min(dp[i], dp[i - coin] + 1);
                }
            }
        }if (dp[amount] == amount + 1) return -1;
        return dp[amount];
    }
}
