class Solution {
private:
    vector<int> memo;
    vector<vector<bool>> isPalindrome;
    string s;
    int n;
    bool isValid(int i, int j){
        for(int k = 0; k<(j - i + 1)/2; k++){
            if(s[i + k] != s[j - k]) return false;
        }
        return true;
    }

    void preComp(){
        isPalindrome.resize(n, vector<bool> (n, false));
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++) isPalindrome[i][j] = isValid(i, j);
        }
    }

    int helper(int i){
        if(i >= n-1) return 0;
        if(memo[i] != -1) return memo[i];
        int ans = INT_MAX;
        for(int k = i; k<n; k++){
            if(isPalindrome[i][k]){
                if(k == n-1) ans = 0;
                // cout<<i<<" "<<k<<endl;
                ans = min(ans, 1 + helper(k+1));
            }
        }
        return memo[i] = ans;
    }

public:
    int minCut(string s) {
        this->s = s;
        n = s.size();
        memo.resize(n+1, -1);
        preComp();
        return helper(0);
    }
};