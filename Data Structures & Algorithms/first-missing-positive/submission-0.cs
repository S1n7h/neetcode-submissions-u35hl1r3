public class Solution {
    public int FirstMissingPositive(int[] nums) {
        //the said number has to be between 1 and nums.Length + 1
        //if a number is negative, turn it to 0
        for(int i = 0 ; i < nums.Count() ; i++){
            if (nums[i] < 0)    nums[i] = 0;
        }
        //go through every number and if the number's index isn't out of bounds of the array, then change said 
        //number at that number's index to negative
        //example: if number is 3, change number in nums at index 2 to its negative form
        //this is to show that said number exists
        //if a number is negative, use its positive form to find out the index and then repeat the previous step
        //to the number at that number's positive indexes form
        for(int i = 0 ; i < nums.Count() ; i++){
            if (nums[i] - 1 >= nums.Count() || nums[i] == 0)    continue;

            int idx;
            if (nums[i] < 0){
                idx = -nums[i] - 1;
            }else idx = nums[i] - 1;

            if (nums[idx] > 0) nums[idx] = -nums[idx];
            else if (nums[idx] == 0) nums[idx] = -(idx + 1);
            Console.Write($"{nums[idx]}");
        }Console.WriteLine();
        foreach(var num in nums) Console.Write($"{num} ");
        for(int i = 0 ; i < nums.Count() ; i++){
            if (nums[i] >= 0)    return i + 1;
        }return nums.Count() + 1;
    }
}