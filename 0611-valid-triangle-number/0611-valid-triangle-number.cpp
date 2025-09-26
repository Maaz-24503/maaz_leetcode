class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        function<int(int)> bs = [&](int num){
            int left = 0, right = n - 1, ans = -1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] < num) {
                    left = mid + 1;
                    ans = mid;
                }
                else right = mid - 1;
            }
            return ans;
        };
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int sum = nums[i] + nums[j];
                int res = bs(sum);
                if(res > j) ans += res - j;
            }
        }
        return ans;
    }
};