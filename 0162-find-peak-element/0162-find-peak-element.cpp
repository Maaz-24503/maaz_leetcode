class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + ((r - l)/2);
            long long left = mid == 0 ? LLONG_MIN : nums[mid - 1], right = mid == n - 1 ? LLONG_MIN : nums[mid + 1];
            int midVal = nums[mid];
            if(midVal > left && midVal > right) return mid;
            else if(midVal < left) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};