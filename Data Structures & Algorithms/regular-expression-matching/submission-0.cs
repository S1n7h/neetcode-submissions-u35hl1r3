public class Solution {
    public bool IsMatch(string s, string p) {
        return Dfs(s, p, 0, 0);
    }

    bool Dfs(string s, string p, int i, int j){
        if (i >= s.Length && j >= p.Length) return true;
        if (i < s.Length && j >= p.Length)  return false;

        bool match = i < s.Length && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.Length && p[j + 1] == '*'){
            return Dfs(s, p, i, j + 2) || (match && Dfs(s, p, i + 1, j));
        }
        
        if (match) return Dfs(s, p, i + 1, j + 1);
        return false;
    }
}
