class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n<=3) return stones[n-1] - stones[0];
        int mini = 0;
        for(int i = 0; i<n-2; i++) mini = max(mini, stones[i+2] - stones[i]);
        return mini;
    }
};