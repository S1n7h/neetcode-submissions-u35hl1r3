//basic thing is that you want to xor all the number from 0 to n with all numbers in array,
//to do that, you need a for loop to iterate through all the numbers from 0 to n and
//you need to iterate through the array itself
public class Solution {
    public int MissingNumber(int[] nums) {
        int range = nums.Length;
        for (int i = 0 ; i < nums.Length ; i++){
            range ^= i ^ nums[i];
        }return range;
    }
}
