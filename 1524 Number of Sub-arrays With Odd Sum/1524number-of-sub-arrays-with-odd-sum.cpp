class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> preSum(n+1, 0);
        vector<int> odd(n + 1, 0);
        vector<int> even(n + 1, 0);
        even[0] = 1;
        int ans = 0;
        for(int i = 0; i<n; i++) preSum[i + 1] = arr[i] + preSum[i];
        for(int i = 1; i<=n; i++){
            if(preSum[i] % 2 == 0){
                even[i] = even[i-1] + 1;
                odd[i] = odd[i-1];
            }
            else{
                even[i] = even[i - 1];
                odd[i] = odd[i - 1] + 1;
            }
        }
        int sum = 0;
        for(int i = 0; i<n + 1; i++) sum = preSum[i] % 2 == 0 ? (sum + odd[i]) % 1000000007 : (sum + even[i]) % 1000000007;
        return sum;
    }
};