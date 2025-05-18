class Solution {
private:
    vector<unordered_map<string, int>> dp;
    vector<string> validCols;
    int n, m;
    int MOD = 1e9 + 7;

    int helper(int i, string prev){
        if(i == n) return 1;
        if(dp[i].find(prev) != dp[i].end()) return dp[i][prev];
        dp[i][prev] = 0;
        if(i == 0){
            for(int k = 0; k<validCols.size(); k++){
                dp[i][prev] = (dp[i][prev] + helper(i + 1, validCols[k])) % MOD;
            }
            return dp[i][prev];
        }
        for(int k = 0; k<validCols.size(); k++){
            bool isValid = true;
            for(int j = 0; j<m; j++){
                if(prev[j] == validCols[k][j]){
                    isValid = false;
                    break;
                }
            }
            if(!isValid) continue;
            dp[i][prev] = (dp[i][prev] + helper(i + 1, validCols[k])) % MOD;
        }
        return dp[i][prev];
    }

public:
    int colorTheGrid(int m, int n) {
        this->m = m;
        this->n = n;
        dp.resize(n + 1);
        stack<string> t1, t2;
        t1.push("r");
        t1.push("g");
        t1.push("b");
        for(int i = 1; i<m; i++){
            if(t1.empty()){
                while(!t2.empty()){
                    string temp = t2.top();
                    t2.pop();
                    if(temp[temp.size() - 1] != 'r')
                        t1.push(temp + "r");
                    if(temp[temp.size() - 1] != 'g')
                        t1.push(temp + "g");
                    if(temp[temp.size() - 1] != 'b')
                        t1.push(temp + "b");
                }
            }
            else{
                while(!t1.empty()){
                    string temp = t1.top();
                    t1.pop();
                    if(temp[temp.size() - 1] != 'r')
                        t2.push(temp + "r");
                    if(temp[temp.size() - 1] != 'g')
                        t2.push(temp + "g");
                    if(temp[temp.size() - 1] != 'b')
                        t2.push(temp + "b");
                }
            }
        }
        stack<string>& source = t1.empty() ? t2 : t1;
        while (!source.empty()) {
            validCols.push_back(source.top());
            source.pop();
        }
        return helper(0, "");
    }
};