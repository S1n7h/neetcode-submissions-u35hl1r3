class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int, int> hash;
        int maximum = 0, minimum = 0, count = 0,t_count = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            hash[nums[i]]++;
            if (nums[i] > maximum)  maximum = nums[i];
            if (nums[i] < minimum)  minimum = nums[i];
        }for (int i = minimum ; i < maximum + 1 ; i++){
            t_count++;
            if (hash.count(i) == 0){ //no continuation
                if (count < t_count - 1)    count = t_count - 1;
                t_count = 0;
            }
        }std::cout << t_count << "  " << count;
        if (t_count > count)   return t_count;
        return count;
    }
};
