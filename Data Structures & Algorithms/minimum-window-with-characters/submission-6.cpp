class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())    return "";

        string ret = "";

        unordered_map<char, int> counts;
        unordered_map<char, int> countt;

        for (int i = 0 ; i < t.size() ; i++)    countt[t[i]]++;
        
        int l = 0, shortest_l = 0 , shortest_i = 0, shortest_length = s.size() + 1, have = 0, need = countt.size();

        for (int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            if (countt.count(c) == 0)   continue;

            counts[c]++;

            if (counts[s[i]] == countt[s[i]]) have++;

            while (have == need){
                while (countt.count(s[l]) == 0) l++;
                if (shortest_length > i - l + 1){
                    shortest_l = l;
                    shortest_i = i;
                    shortest_length = i - l + 1;
                }counts[s[l]]--;
                l++;
                if (countt.count(s[l-1]) != 0 && counts[s[l-1]] < countt[s[l-1]]){
                    have--;break;
                }
            }
            //remember to update the value of have
        }if (shortest_length == s.size() + 1) return "";
        for (int i = shortest_l; i <= shortest_i ; i++)    ret += s[i];
        return ret;
    }
};
