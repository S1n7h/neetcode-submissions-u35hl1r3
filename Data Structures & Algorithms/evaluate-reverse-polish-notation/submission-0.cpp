class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        int ret = 0;
        for (int i = 0 ; i < tokens.size() ; i++){
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")  { // and operation
                int val1 = stack.top();
                stack.pop();
                int val2 = stack.top();
                stack.pop();
                if (tokens[i] == "+")    stack.push(val2 + val1);
                else if (tokens[i] == "-")    stack.push(val2 - val1);
                else if (tokens[i] == "/")    stack.push(val2 / val1);
                else stack.push(val2 * val1);
            }
            else {
                stack.push(stoi(tokens[i]));
            }
        }ret = stack.top();
        return ret;
    }
};
