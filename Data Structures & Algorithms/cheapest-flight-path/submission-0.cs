public class Solution
{
    public int FindCheapestPrice(int n, int[][] flights, int src, int dst, int k)
    {
        var graph = new Dictionary<int, List<(int, int)>>();

        foreach (var ticket in flights)
        {
            int source = ticket[0];
            int destination = ticket[1];
            int price = ticket[2];

            if (!graph.ContainsKey(source))
                graph[source] = new List<(int, int)>();
            graph[source].Add(new(destination, price));
        }
        int ret = -1;
        Dfs(ref graph, src, dst, 0, ref ret, k);
        return ret;
    }

    void Dfs(ref Dictionary<int, List<(int, int)>> graph, int source, int destination, int amount, ref int ret, int k)
    {
        if (k == -1)
        {
            if (source == destination)
            {
                if (ret == -1) ret = amount;
                else ret = Math.Min(amount, ret);
            }
            return;
        }
        if (source == destination)
        {
            if (ret == -1) ret = amount;
            else ret = Math.Min(amount, ret);
        }
        if (!graph.ContainsKey(source)) return;

        var dummyList = new List<(int, int)>();
        foreach (var destination_price in graph[source])
        {
            dummyList.Add((destination_price.Item1, destination_price.Item2));
        }
        for (int i = 0; i < dummyList.Count; i++)
        {
            var currDestination_Price = graph[source][i];
            graph[source].RemoveAt(i);

            Dfs(ref graph, currDestination_Price.Item1, destination, amount + currDestination_Price.Item2, ref ret, k - 1);

            graph[source].Insert(i, (currDestination_Price));
        }
    }
}