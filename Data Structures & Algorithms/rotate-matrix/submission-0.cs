public class Solution {
    public void Rotate(int[][] matrix) {
        int l = 0 ; 
        int r = matrix.Length - 1;

        while(l < r){
            for (int i = 0 ; i < r - l ; i++){
                int top = l;
                int bottom = r;
                int temp = matrix[top][l + i];

                //top left gets value of bottom left
                matrix[top][l + i] = matrix[bottom - i][l];

                //bottom left gets values of bottom right
                matrix[bottom - i][l] = matrix[bottom][r - i];

                //bottom right gets value of top right
                matrix[bottom][r - i] = matrix[top + i][r];

                //top right gets value of top left
                matrix[top + i][r] = temp;
            }
            l++;
            r--;
        }
    }
}
