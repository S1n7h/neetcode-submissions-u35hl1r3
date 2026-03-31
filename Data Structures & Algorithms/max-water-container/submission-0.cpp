class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0 ; 
        int r = heights.size() - 1;
        int area = 0;
        while (l < r){
            int temp_area = min(heights[l], heights[r]) * (r - l);
            area = max(area, temp_area);
            if (heights[l] < heights[r])    l++;
            else    r--; 
        }return area;
    }
};
