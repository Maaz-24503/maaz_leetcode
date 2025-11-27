class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long n = arr.size(), preSum = 0, postSum = 0, maxPreSum = 0, maxPostSum = 0;
        for(int i = 0; i < n; i++){
            preSum += arr[i];
            postSum += arr[n - i - 1];
            maxPostSum = max(maxPostSum, postSum);
            maxPreSum = max(maxPreSum, preSum);
        }
        long long sum = postSum;
        long long ans = max(maxPostSum + maxPreSum, (k - 2) * (sum) + (maxPostSum + maxPreSum));
        long long curr = 0, maxi = 0;
        for(int num : arr){
            curr = max(0LL, curr + num);
            maxi = max(curr, maxi);
        }
        return static_cast<int>((k == 1 ? maxi : max(maxi, ans)) % (long long)(1e9 + 7));
    }
};