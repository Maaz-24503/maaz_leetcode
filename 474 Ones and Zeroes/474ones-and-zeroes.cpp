
class Solution {
public:
    vector<pair<int, int>> nums;
    int n1;

    pair<int, int> counter(string k){
        int ones = 0;
        int zeros = 0;
        for(int i = 0; i<k.size(); i++){
            if(k[i] == '0') zeros++;
            else ones++;
        }
        return {zeros, ones};
    }

    // int helper(int i, int j, int ind){
    //     if(i < 0 || j < 0) return 0;
    //     string key = to_string(i) + " " + to_string(j) + " " + to_string(ind);
    //     // cout<<key<<"\n";
    //     if(ind >= n1) return 0;
    //     // cout<<i<<" "<<j<<endl;
    //     if(memo.find(key) != memo.end()) return memo[key];
    //     // cout<<i<<" "<<j<<endl;
    //     if(i>=nums[ind].first && j>=nums[ind].second) return memo[key] = max(1 + helper(i-nums[ind].first, j-nums[ind].second, ind+1), helper(i, j, ind+1));
    //     return memo[key] = helper(i, j, ind+1);
    // }

    int findMaxForm(vector<string>& strs, int m, int n) {
        n1 = strs.size();
        nums.resize(n1);
        for(int i = 0; i<n1; i++) nums[i] = counter(strs[i]);
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        for (int k = 0; k < n1; k++) {
            int zeroCount = nums[k].first;
            int oneCount = nums[k].second;
            for (int i = m; i >= zeroCount; i--) {
                for (int j = n; j >= oneCount; j--) {
                    memo[i][j] = max(memo[i][j], 1 + memo[i - zeroCount][j - oneCount]);
                }
            }
        }
        return memo[m][n];
    }
};