class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<int> diff(n - 1);
        for(int i = 0; i < n - 1; i++) diff[i] = prices[i] - prices[i + 1];
        long long ans = 0LL;
        int r = 0, l = 0;
        while(r < n - 1){
            while(r < n - 1 && diff[r] == 1) r++;
            ans += ((r - l + 0LL) * (r - l + 1LL)) / 2;
            if(r > l) l = r;
            else{
                l++;
                r++;
            }
        }
        return ans + n;
    }
};