class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); cost.insert(cost.begin(), 0);
        int n = cost.size();
        int a0 = 0, a1 = cost[n - 2];
        for(int i = n - 3; i>=0; i--){
            int temp = a1;
            a1 = cost[i] + min(a1, a0);
            a0 = temp;
        }
        return a1;
    }
};