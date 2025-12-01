class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        function<bool(int)> check = [&](int k) -> bool {
            long long carry = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] - k > carry) {
                    // if(k >= 9) cout<<k<<" "<<i<<" "<<carry<<endl; 
                    return false;
                }
                long long curr = nums[i] - carry;
                carry = k - curr;
            }
            return true;
        };
        function<int()> bs = [&]() -> int {
            int r = *max_element(nums.begin(), nums.end()), l = 0;
            int ans = r;
            while(l <= r){
                int mid = r - ((r - l) / 2);
                if(check(mid)) {
                    ans = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            return ans;
        };
        return bs();
    }
};