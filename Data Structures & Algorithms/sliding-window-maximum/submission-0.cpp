class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret(nums.size() - k + 1);
        if (nums.size() < k)    return ret;

        int l = 0 , r = k - 1;
        int maximum = INT_MIN, maximum_index = 0;
        
        for (int i = 0 ; i < k ; i++){
            if (maximum < nums[i]){
                maximum = nums[i];
                maximum_index = i;
            }
        }int j = 0 ;
        ret[j] = maximum;

        for (int i = r ; i < nums.size() - 1; i++){
            l++;r++;j++;
            if (maximum_index < l){
                maximum = INT_MIN;
                for (int i = l ; i <= r ; i++){
                    if (maximum < nums[i]){
                        maximum = nums[i];
                        maximum_index = i;
                    }
                }
            }else{
                if (maximum <= nums[r]){
                    maximum = nums[r];
                    maximum_index = r;
                }
            }ret[j] = maximum;
        }return ret; 
    }
};
