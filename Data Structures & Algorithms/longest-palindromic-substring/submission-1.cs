public class Solution {
    public string LongestPalindrome(string s) {
        string ret = "";
        for (int i = 0 ; i < s.Length ; i++){
            int l = i, r = i;
            while(l >= 0 && r < s.Length && s[l] == s[r]){
                if (ret.Length < r - l + 1){
                    ret = s.Substring(l, r - l + 1);
                }r++;l--;
            }l = i ;
            r = i + 1;
            while(l >= 0 && r < s.Length && s[l] == s[r]){
                if (ret.Length < r - l + 1){
                    ret = s.Substring(l , r - l + 1);
                }r++;l--;
            }
        }return ret;
    }
}