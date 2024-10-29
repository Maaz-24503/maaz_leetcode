class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int height = 0;
        int score = 0;
        bool opening = true;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                stk.push(height++);
                opening = true;
            }
            else if(opening){
                score += 1<<stk.top();
                stk.pop();
                height--;
                opening = false;
            }
            else {stk.pop(); height--;}
        }
        return score;
    }
};