class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7, n = s.size();
        long long ans = 0;
        for(int i = 0; i<n; i++){
            int count = 0;
            while(i < n && s[i] == '1'){
                count++;
                i++;
            } 
            ans += ((count + 0LL) * (count + 1LL)) / 2;
            ans %= mod;
        }
        return ans;
    }
};