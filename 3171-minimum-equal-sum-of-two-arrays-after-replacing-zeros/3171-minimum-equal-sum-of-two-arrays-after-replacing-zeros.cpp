class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = 0, zero2 = 0;
        int n = nums1.size(), m = nums2.size();
        long long sum1 = 0LL, sum2 = 0LL; 
        for(int i = 0; i<n; i++) if(!nums1[i]) zero1++; else sum1 += nums1[i];
        for(int i = 0; i<m; i++) if(!nums2[i]) zero2++; else sum2 += nums2[i];
        if(sum1 < sum2 + zero2 && zero1 == 0) return -1;
        if(sum2 < sum1 + zero1 && zero2 == 0) return -1;
        return max(sum1 + zero1, sum2 + zero2); 
    }
};