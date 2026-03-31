public class Solution {
    public int CanCompleteCircuit(int[] gas, int[] cost) {
        int startingIndex = 0;
        int total = 0;

        if (gas.Sum() < cost.Sum()) return -1;
        
        for (int i = 0 ; i < gas.Length ; i++){
            total += gas[i] - cost[i];
            if (total < 0)  {
                startingIndex = i + 1;
                total = 0;
            }
        }if (startingIndex == gas.Length) return -1;
        return startingIndex; 
    }
}
