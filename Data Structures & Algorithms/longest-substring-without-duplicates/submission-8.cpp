class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int length = 0;
        int l = 0;
        for (int i =  0 ; i < s.size() ; i++){
            while (hash.find(s[i]) != hash.end()){
                hash.erase(s[l]);
                l++;
            }
            hash.insert(s[i]);
            length = max(length, i - l + 1); //last check when the last alphabet is not duplicate
        }return length;
    }
};
