class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs(n+1, 0);
        stairs[n] = 1;
        stairs[n-1] = 1;
        for(int i = n-2; i>=0; i--) stairs[i] = stairs[i+1] + stairs[i+2];
        return stairs[0];
    }
};