public class Solution {
    public bool CanFinish(int numCourses, int[][] prerequisites) {
        Dictionary<int, List<int>> hash = new Dictionary<int, List<int>>();

        foreach(var pair in prerequisites){
            if (!hash.ContainsKey(pair[1])) hash[pair[1]] = new List<int>();
            hash[pair[1]].Add(pair[0]);
        }

        foreach(var crs in hash.Keys){
            List<int> visited = new List<int>();
            if (!Dfs(crs, hash, visited)) return false;
        }return true;
    }

    bool Dfs(int course, Dictionary<int, List<int>> hash, List<int> visited){
        if (visited.Contains(course)) return false;
        if (!hash.ContainsKey(course)){
            return true;
        }

        visited.Add(course);

        foreach(var crs in hash[course]){
            if (!Dfs(crs, hash, visited)) return false;
        }

        visited.RemoveAt(visited.Count - 1);

        return true;
    }
}
