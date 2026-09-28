class Solution {
public:
    int maxDepth(string s) {
        int curr = 0, maxi = 0;
        for(char &c : s){
            if(c == '(') curr++;
            else if(c == ')') curr--;
            maxi = max(curr, maxi);
        }
        return maxi;
    }
};