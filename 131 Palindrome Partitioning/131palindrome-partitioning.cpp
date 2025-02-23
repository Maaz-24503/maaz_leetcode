class Solution {
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        n = s.size();
        memo.resize(n+1);
        seen.resize(n+1, false);
        vector<vector<string>> ans = helper(0);
        for(int i = 0; i<ans.size(); i++) reverse(ans[i].begin(), ans[i].end());
        return ans;
    }

private:
    string s;
    int n;
    vector<vector<vector<string>>> memo;
    vector<bool> seen;

    bool isPalindrome(string str){
        for(int i = 0; i<str.size()/2; i++) if(str[i] != str[str.size() - i - 1]) return false;
        return true;
    }

    vector<vector<string>> helper(int i){
        if(i == n - 1) return vector<vector<string>> {{string(1, s[n-1])}};
        if(seen[i]) return memo[i];
        vector<vector<string>> ans;
        string temp = s.substr(i, n - i);
        if(isPalindrome(temp)) ans.push_back({s.substr(i, n - i)});
        for(int j = 1; j<n - i; j++){
            string curr = s.substr(i, j);
            if(isPalindrome(curr)){
                vector<vector<string>> recur = helper(i+j);
                for(int t = 0; t<recur.size(); t++) recur[t].push_back(curr);
                for(int t = 0; t<recur.size(); t++) ans.push_back(recur[t]);
            }
        }
        seen[i] = true;
        return memo[i] = ans;
    }
};