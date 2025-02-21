class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> trk;
        for(int i = 0; i<nums.size(); i++) trk.push(nums[i]);
        for(int i = 0; i<k-1; i++) trk.pop();
        return trk.top();
    }
};