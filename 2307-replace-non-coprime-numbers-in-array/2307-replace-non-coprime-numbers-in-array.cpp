class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        function<int(int,int)> gcd = [&](int a, int b) -> int {
            if (b == 0) {
                return a;
            }
            return gcd(b, a % b);
        };
        int n = nums.size();
        vector<int> ans(1, nums[0]);
        for(int i = 1; i < n; i++){
            int a = ans[ans.size() - 1], b = nums[i];
            while(ans.size() >= 1 && gcd(a, b) > 1){
                b = lcm(a, b);
                ans.pop_back();
                if(ans.size() == 0) break;
                a = ans.back();
            } 
            ans.push_back(b);
        }
        return ans;
    }
};