class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        function<int(int, int)> gcd = [&](int a, int b) -> int {
            if(a % b == 0) return b;
            return gcd(b, a % b);
        };
        int mx = INT_MIN;
        vector<int> preGcd(n);
        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            preGcd[i] = gcd(mx, nums[i]);
        }
        sort(preGcd.begin(), preGcd.end());
        long long ans = 0;
        for(int i = 0; i < n / 2; i++){
            ans += gcd(preGcd[i], preGcd[n - i - 1]);
        }
        return ans;
    }
};