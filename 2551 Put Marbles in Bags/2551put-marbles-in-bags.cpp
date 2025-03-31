class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i<n-1; i++){
            maxHeap.push(weights[i] + weights[i+1]);
            minHeap.push(weights[i] + weights[i+1]);
        }
        long long maxi = 0, mini = 0;
        for(int i = 0; i<k-1; i++){
            maxi += maxHeap.top();
            mini += minHeap.top();
            maxHeap.pop();
            minHeap.pop();
        }
        return maxi - mini;
    }
};