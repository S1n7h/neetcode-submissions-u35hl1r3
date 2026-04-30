public class Solution {
    public double[] CalcEquation(List<List<string>> equations, double[] values, List<List<string>> queries) {
        Dictionary<string, List<(string, double)>> graph = new Dictionary<string, List<(string, double)>>();

        for(int i = 0 ; i < equations.Count ; i++){
            var equation = equations[i];
            var var1 = equation[0];
            var var2 = equation[1];

            if (!graph.ContainsKey(var1)) graph[var1] = new List<(string, double)>();
            if (!graph.ContainsKey(var2)) graph[var2] = new List<(string, double)>();

            graph[var1].Add((var2, values[i]));
            graph[var2].Add((var1, 1.0 / values[i]));
        } 

        double[] ret = new double[queries.Count];
        int idx = 0;
        foreach(var query in queries){
            var visited = new HashSet<string>();
            if (query[0] == query[1] && graph.ContainsKey(query[0])) ret[idx++] = 1.0;
            else if (query[0] == query[1] && !graph.ContainsKey(query[0])) ret[idx++] = -1.0;
            else ret[idx++] = Dfs(graph, query, visited, query[0], 1.0);
        }return ret;
    }
    double Dfs(Dictionary<string, List<(string, double)>> graph, IList<string> query, HashSet<string> visited, string curr, double product){
        if (curr == query[1]) return product;
        if (!graph.ContainsKey(curr) || visited.Contains(curr)) return -1.0;

        visited.Add(curr);
        foreach(var (next, val) in graph[curr]){
            double ret = Dfs(graph, query, visited, next, product * val);
            if (ret != -1.0) return ret;    
        }
        visited.Remove(curr);
        return -1.0;
    }
}