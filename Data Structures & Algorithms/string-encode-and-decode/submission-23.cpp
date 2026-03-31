class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for (int i = 0 ; i < strs.size() ; i++){
            ret += to_string(strs[i].length()) + "#" + strs[i];
        }return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        if (s.size() == 0)  return ret;
        int i = 0; 
        int ele_length = 0 ; 
        while(i < s.size()){
            string temp = "";
            while (s[i] != '#'){
                temp += s[i];
                i++;
            }
            i++; //skip the #
            ele_length = stoi(temp); //store string length
            temp = s.substr(i,ele_length);
            ret.push_back(temp);
            i += ele_length;
        }return ret;
    }
};
