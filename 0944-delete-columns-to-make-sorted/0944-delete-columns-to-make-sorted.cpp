class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        function<bool(int)> isValid = [&](int j){
            for(int i = 0; i < n - 1; i++) 
                if(strs[i][j] > strs[i + 1][j]) 
                    return false;
            return true;
        };
        int ans = 0;
        for(int j = 0; j<m; j++) if(!isValid(j)) ans++;
        return ans;
    }
};