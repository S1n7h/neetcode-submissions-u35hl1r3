class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hash;
        int max_count = 0;
        int l = 0;
        int max_length = 0;
        for (int  r = 0 ; r < s.size() ; r++){
            hash[s[r]]++;
            max_count = max(max_count, hash[s[r]]);
            int substring_length = r - l + 1;
            if (substring_length - max_count > k){
                hash[s[l]]--;
                l++;
            }
            max_length = max(max_length, r - l + 1);
        }return max_length;
    }
};
