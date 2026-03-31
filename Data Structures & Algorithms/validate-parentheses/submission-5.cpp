class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> match = {     {'}' , '{'},
                                                { ']' , '['},
                                                {')' , '('}
        };
        bool valid = true;
        for (int i = 0 ; i < s.size() ; i++){
            if (s[i] == '(' || s[i] == '{'|| s[i] == '[')  stack.push(s[i]);
            else if (stack.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))  return false;
            else{
                if (stack.top() != match[s[i]]) return false;
                stack.pop();    
            }
        }if (!stack.empty()) return false;
        return valid;
    }
};
