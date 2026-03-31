class Solution {
public:
    bool isPalindrome(string s) {
        string t_s = "";
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i] != ' ' && (isalpha(s[i]) || isdigit(s[i])))    t_s += tolower(s[i]);
        }for(int i = 0 ; i < t_s.size() ; i++){
            std::cout << t_s[i];
        }
        int l = 0 , r = t_s.size() - 1;
        while (l < r){
            if (t_s[r] != t_s[l])   return false;
            l++;r--;
        }return true;
    }
};
