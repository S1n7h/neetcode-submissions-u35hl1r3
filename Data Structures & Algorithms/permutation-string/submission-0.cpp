class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())  return false;
        unordered_map<char, int> count1;
        unordered_map<char, int> count2;

        for (int i = 0 ; i < s1.size() ; i++){
            count1[s1[i]]++;
        }
        int windowsize = s1.size();
        for (int i= 0 ; i < s2.size() ; i++){
            count2[s2[i]]++;

            if (i >= windowsize){
                count2[s2[i - windowsize]]--;
            }
            
            if (count2[s2[i - windowsize]] == 0)
                count2.erase(s2[i - windowsize]);

            if (count1 == count2)   return true;
        }return false;
    }
};
