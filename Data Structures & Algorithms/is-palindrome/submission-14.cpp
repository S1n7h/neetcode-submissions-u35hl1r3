class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            // Skip non-alphanumeric characters, with boundary checks
            while(l < r && !(isalpha(s[l]) || isdigit(s[l]))){
                l++;
            }
            while(l < r && !(isalpha(s[r]) || isdigit(s[r]))){
                r--;
            }if (tolower(s[r]) != tolower(s[l]))  return false;
            l++;r--;
        }return true;
    }
};
