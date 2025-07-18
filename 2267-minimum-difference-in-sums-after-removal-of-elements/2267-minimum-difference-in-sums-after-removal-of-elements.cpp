class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n /= 3;
        vector<long long> lineLeft(n + 1), lineRight(n + 1);
        priority_queue<long long> pq;
        long long sum = 0LL;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            pq.push(nums[i]);
        }
        lineLeft[0] = sum;
        for(int i = n; i<2*n; i++){
            if(pq.top() > nums[i]){
                sum -= pq.top();
                pq.pop();
                pq.push(nums[i]);
                sum += nums[i];
            }
            lineLeft[i - n + 1] = sum;
        }
        sum = 0;
        priority_queue<long long, vector<long long>, greater<>> minPq;
        for(int i = (3*n) - 1; i >= 2*n; i--){
            sum += nums[i];
            minPq.push(nums[i]);
        }
        lineRight[n] = sum;
        for(int i = 2*n - 1; i>=n; i--){
            if(minPq.top() < nums[i]){
                sum -= minPq.top();
                minPq.pop();
                minPq.push(nums[i]);
                sum += nums[i];
            }
            lineRight[i - n] = sum;
        }
        long long ans = LLONG_MAX;
        for(int i = 0; i<=n; i++) 
            ans = min(ans, lineLeft[i] - lineRight[i]);
        return ans;
    }
};