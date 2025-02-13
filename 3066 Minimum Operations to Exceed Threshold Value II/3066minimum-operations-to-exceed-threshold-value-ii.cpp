class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long long, vector<long long>, greater<long long> > pq;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            pq.push(nums[i]);
        }
        int moves = 0;
        while(true){
            if(pq.size() < 2) return moves;
            long long currMin = pq.top();
            if(currMin>=k) return moves;
            pq.pop();
            long long secondMin = pq.top();
            pq.pop();
            pq.push((currMin * 2LL) + secondMin);
            moves++;
        }
        return -1;
    }
};