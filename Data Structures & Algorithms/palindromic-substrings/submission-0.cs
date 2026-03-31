public class Solution {
    public int CountSubstrings(string s) {
        int ret = 0;
        for (int i = 0 ; i < s.Length ; i++){
            int l = i, r = i;
            while (l >= 0 && r < s.Length && s[l] == s[r]){
                ret++;
                l--;r++;
            }l = i;
            r = i + 1;
            while (l >= 0 && r < s.Length && s[l] == s[r]){
                ret++;
                l--;r++;
            }
        }return ret;
    }
}
