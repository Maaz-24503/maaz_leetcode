class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int m = (n + k - 1)/k;
        vector<string> ans(m, "");
        for(int i = 0; i<m; i++){
            ans[i].reserve(k);
            for(int j = 0; j<k; j++){
                if(k*i + j < n) ans[i] += s[k*i + j];
                else ans[i] += string(1, fill);
            }
        }
        return ans;
    }
};