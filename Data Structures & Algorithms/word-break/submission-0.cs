public class Solution {
    public bool WordBreak(string s, List<string> wordDict) {
        Dictionary<int, bool> dict = new Dictionary<int, bool> {{s.Length, true}};
        return Dfs(s, ref wordDict, 0, ref dict);
    }
    private bool Dfs(string s, ref List<string> wordDict, int idx, ref Dictionary<int, bool> dict){
        if (dict.ContainsKey(idx)){
            return dict[idx];
        }

        foreach(var substr in wordDict){
            if (idx + substr.Length <= s.Length && s.Substring(idx, substr.Length) == substr){
                if (Dfs(s, ref wordDict, idx + substr.Length, ref dict)){
                    dict[idx] = true;
                    return true;
                }
            }
        }dict[idx] = false;
        return false;
    }
}
