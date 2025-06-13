class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        auto canFormPairs = [&](int mid) -> bool {
            int count = 0;
            for (int i = 0; i < n - 1;) {
                if (nums[i+1] - nums[i] <= mid) {
                    count++;
                    i += 2; 
                } else {
                    i++;
                }
            }
            return count >= p;
        };
        
        int left = 0, right = nums[n - 1] - nums[0], answer = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFormPairs(mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return answer;
    }
};
