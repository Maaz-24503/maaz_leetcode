class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        function<bool(int)> possible = [&](int guess) -> bool {
            if(guess > n) return false; 
            if(guess <= 1) return true; 
            for(int i = 0; i + guess - 1 < n; i++) 
                if((nums[i] + 0LL) * k >= nums[i + guess - 1]) return true;
            return false;
        };
        int l = 0, r = n, ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(possible(mid)) {
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        }
        return n - ans;
    }
};