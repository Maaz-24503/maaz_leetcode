class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> lMin(n, (INT_MAX+0LL) *20);
        priority_queue<int> maxHeap;
        long long sum = 0LL;
        for(int i = 0; i<2*(nums.size()/3); i++){
            if(i<n/3){ 
                maxHeap.push(nums[i]);
                sum += nums[i];
                if(i+1 == n/3) lMin[i] = sum;
            }
            else{
                if(maxHeap.top()>nums[i]){
                    sum -= maxHeap.top();
                    sum += nums[i];
                    maxHeap.pop();
                    maxHeap.push(nums[i]);
                }
                lMin[i] = sum;
            }
        }
        sum = 0LL;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long ans = INT_MAX;
        for(int i = n-1; i>=n/3; i--){
            if(i>=2*n/3){ 
                minHeap.push(nums[i]);
                sum += nums[i];
                if(i == 2*n/3) ans = lMin[i-1] - sum;
            }
            else{
                if(minHeap.top()<nums[i]){
                    sum -= minHeap.top();
                    sum += nums[i];
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
                ans = min(ans, lMin[i-1] - sum);
            }
        }
        return ans;
    }
};