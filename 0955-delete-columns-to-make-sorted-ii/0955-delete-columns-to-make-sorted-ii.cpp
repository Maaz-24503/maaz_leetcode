class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<bool> done(n, false);
        function<bool(int)> isValid = [&](int j){
            vector<int> tempDone;
            for(int i = 0; i < n - 1; i++) 
                if(strs[i][j] > strs[i + 1][j] && !done[i]) 
                    return false;
                else if(strs[i][j] < strs[i + 1][j])
                    tempDone.push_back(i);
            for(int i = 0; i<tempDone.size(); i++) done[tempDone[i]] = true;
            return true;
        };
        int ans = 0;
        for(int j = 0; j<m; j++){
            if(!isValid(j)) ans++;
        }
        return ans;
    }
};