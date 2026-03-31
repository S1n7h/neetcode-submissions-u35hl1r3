public class Solution {
    public void SetZeroes(int[][] matrix) {
        var visited = new List<(int, int)> ();
        for (int r = 0 ; r < matrix.Length ; r++){
            for (int c = 0 ; c < matrix[0].Length ; c++){
                if (visited.Contains((r, c)) == false && matrix[r][c] == 0){
                    visited.Add((r, c));
                    ChangetoZero(r, c, matrix, visited);
                }
            }
        }
    }

    public void ChangetoZero(int r, int c, int[][] matrix, List<(int, int)> visited){
        for (int i = 0 ; i < matrix.Length ; i++){
            if (matrix[i][c] == 0 && visited.Contains((i , c)) == false) continue;
            matrix[i][c] = 0;
            visited.Add((i , c));
        }
        for (int i = 0 ; i < matrix[0].Length ; i++){
            if (matrix[r][i] == 0 && visited.Contains((r, i)) == false) continue;
            matrix[r][i] = 0;
            visited.Add((r , i));
        }
    }
}
