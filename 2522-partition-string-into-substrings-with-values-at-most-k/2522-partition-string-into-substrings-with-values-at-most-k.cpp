class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        int ans = 1;
        long long curr = 0LL;
        for(int i = 0; i<n; i++){
            if(s[i] - '0' > k) return -1;
            curr = (curr*10) + (s[i] - '0');
            if(curr > k) {
                ans++;
                curr = s[i] - '0';
            }
        }
        return ans;
    }
};