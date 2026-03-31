class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret(2);
        int l = 0 , r = numbers.size() - 1;
        while (l < r){
            if (target > numbers[l] + numbers[r])   l++;
            else if (target < numbers[l] + numbers[r])   r--;
            else{
                if (l == r) return ret;
                ret[0] = l + 1;
                ret[1] = r + 1;
                return ret;
            }
        }
    }
};
