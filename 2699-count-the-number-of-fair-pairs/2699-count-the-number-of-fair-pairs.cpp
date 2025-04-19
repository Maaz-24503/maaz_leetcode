class Solution {
public:

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if(n == 1) return 0;
        sort(nums.begin(), nums.end());
        int l = 1, r = 0;
        int i = 0;
        while(i<n-1 && nums[i] + nums[n-1] < lower) i++;
        if(i >= n-1) return 0;
        l = i+1;
        while(l<n && (nums[l] + nums[i] < lower)) l++;
        if(l == n) return 0;
        r = l;
        while(r<n && (nums[r] + nums[i]) <= upper) r++;
        r--;
        long long sum = r-l+1;
        // cout<<i<<": "<<l<<" "<<r<<" "<<sum<<endl;
        i++;
        for(; i<n; i++){
            while(i<l && (nums[l] + nums[i] >= lower)) l--;
            l++;
            if(l<=i) l = i+1;
            // cout<<i<<" ";
            while(i<r && (nums[r] + nums[i] > upper)) r--;
            if(r<=i) break;
            // if(done) r++;
            sum += r-l+1;
            // cout<<l<<" "<<r<<endl;
        }
        return sum;
    }
};