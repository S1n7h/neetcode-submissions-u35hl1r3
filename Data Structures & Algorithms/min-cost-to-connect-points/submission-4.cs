public class Solution
{
    public int MinCostConnectPoints(int[][] points)
    {
        var Distance = new List<int>();
        var visited = new List<bool>();


        foreach (var point in points)
        {
            Distance.Add(int.MaxValue);
            visited.Add(false);
        }

        Distance[0] = 0;
        int currnode = 0;
        for (int i = 0; i < points.Length - 1; i++)
        {
            int nextnode = -1;
            visited[currnode] = true;
            for (int j = 0; j < points.Length; j++)
            {
                if (visited[j]) continue;

                int DistanceFromItoJ = Math.Abs(points[currnode][0] - points[j][0])
                                     + Math.Abs(points[currnode][1] - points[j][1]);
                Distance[j] = Math.Min(Distance[j], DistanceFromItoJ);
                if (nextnode == -1 || Distance[j] < Distance[nextnode])
                    nextnode = j;
            }currnode = nextnode;
        }return Distance.Sum();
    }
}