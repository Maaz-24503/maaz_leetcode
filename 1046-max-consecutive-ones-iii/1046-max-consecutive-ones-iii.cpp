class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, count = 0, n = nums.size();
        while(r<n && count<=k){
            if(nums[r] == 0) count++;
            r++;
        }
        if(count<=k) return n;
        int maxi = r - l - 1;
        while(r<n){
            if(count > k){
                while(count>k){
                    if(nums[l] == 0) count--;
                    l++;
                }
                maxi = max(maxi, r - l);
            }
            else{
                while(r<n && count<=k){
                    if(nums[r] == 0) count++;
                    r++;
                }
                cout<<r<<" "<<l<<endl;
                maxi = max(maxi, r - l - 1);
            }
        }
        if(count <= k) maxi = max(maxi, r - l);
        return maxi;
    }
};
