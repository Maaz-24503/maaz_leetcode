class Solution {
public:
    void helper(int left, int right, int n, string curr, vector<string>& ans){
        if(left == right && left == n) ans.push_back(curr);
        else{
            if(left < n) helper(left + 1, right, n, curr + "(", ans);
            if(right < left) helper(left, right + 1, n, curr + ")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0, 0, n, "", ans);
        return ans;
    }
};