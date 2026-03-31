public class CountSquares {

    List<(int, int)> points = new List<(int, int)> ();
    Dictionary<(int, int), int> dict = new Dictionary<(int, int), int>();

    public CountSquares() {
        
    }
    
    public void Add(int[] point) {
        if (!points.Contains((point[0], point[1]))){
            points.Add((point[0], point[1]));
            dict[(point[0], point[1])] = 1;
        }else dict[(point[0], point[1])]++;
    }
    
    public int Count(int[] point) {
        int total = 0;
        foreach(var coordinates in points){
            if ((coordinates.Item1 != point[0] || coordinates.Item2 != point[1]) 
                && Math.Abs(point[0] - coordinates.Item1) == Math.Abs(point[1] - coordinates.Item2)){
                var corner1 = (coordinates.Item1, point[1]);
                var corner2 = (point[0], coordinates.Item2);
                if (points.Contains(corner1) && points.Contains(corner2)){
                    if (points.Contains((point[0], point[1]))) total += dict[corner1] * dict[corner2] * dict[coordinates] * (dict[(point[0], point[1])]);
                    else total += dict[corner1] * dict[corner2] * dict[coordinates];
                }
            }
        }return total;
    }
}
