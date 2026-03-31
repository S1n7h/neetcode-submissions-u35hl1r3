class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()*matrix[0].size() - 1;
        int submat_size = matrix[0].size(); //4

        while (l <= r){
            int mid = (l + r) / 2; //5
            int temp_matrix = mid/submat_size; //index val of main matrix(1)
            int val = mid%submat_size; //index val at sub matrix(1)
            vector<int> submat = matrix[temp_matrix]; 
            if (target > submat[val]){
                l = mid + 1;
            }else if (target < submat[val]){
                r = mid - 1;
            }else if (target == submat[val]){
                return true;
            }
        }return false;
    }
};
