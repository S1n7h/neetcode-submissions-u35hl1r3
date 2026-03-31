class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = 0, max_area = 0, max_l = 0, max_r = 0, temp_max_height = 0, temp_max_index = 0;
        while (height[l] == 0) l++;
        r = l; //r and l can be height.size() but it doesn't matter cuz it won't enter the while loop in that case as l < height.size()
        while (l < height.size()){
            while (r < height.size() && (r == l || height[r] < height[l])){
                r++;
                if (r < height.size() && temp_max_height < height[r]){
                    temp_max_height = height[r];
                    temp_max_index = r;
                }
            }
            if (r != height.size()){
                int min_height = height[l];
                while (l + 1 < r){
                    max_area += min_height - height[l + 1];
                    l++;
                }l++; // l = r;
            }else{
                if (l == temp_max_index)    return max_area;
                while (l + 1 < temp_max_index && l < height.size() - 1){
                    max_area += temp_max_height - height[l + 1];
                    l++;
                }l = temp_max_index; // l = r
                r = temp_max_index;
            }cout << "max_area: " << max_area << "  temp_max_height: " << temp_max_height << "  temp_max_index: " << temp_max_index << '\n';
            temp_max_height = 0;
        }return max_area;
    }
};