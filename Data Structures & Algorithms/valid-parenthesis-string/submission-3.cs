public class Solution {
    public bool CheckValidString(string s) {
        Stack<int> open = new Stack<int>();
        Stack<int> star = new Stack<int>();
        
        for (int i = 0 ; i < s.Count() ; i++){
            if (s[i] == '(')   open.Push(i);
            else if (s[i] == '*')  star.Push(i);
            else{
                if (open.Count == 0 && star.Count() == 0)    return false;
                else if (open.Count != 0)  open.Pop();
                else if (star.Count != 0)  star.Pop();
                else return false;
            }
        }while(open.Count > 0){
            if (star.Count == 0)    return false;
            else if (star.Peek() > open.Peek()){
                star.Pop();
                open.Pop();
            }else return false;
        }return true;
    }
}
