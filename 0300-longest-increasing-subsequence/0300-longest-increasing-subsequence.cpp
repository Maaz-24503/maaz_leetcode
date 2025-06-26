class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> curr;
        int n = nums.size();

        function<void(int)> bs = [&](int num){
            int l = 0, r = curr.size() - 1;
            while(l < r){
                int mid = (l + r) / 2;
                if(curr[mid] < num) l = mid + 1;
                else r = mid;
            }
            curr[r] = num;
        };

        for(int i = 0; i<n; i++){
            if(!curr.size() || curr.back() < nums[i]) curr.push_back(nums[i]);
            else bs(nums[i]);
        }

        return curr.size();
    }
};