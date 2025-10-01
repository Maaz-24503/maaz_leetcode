class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange){
            int left = numBottles % numExchange;
            numBottles /= numExchange;
            ans += numBottles;
            numBottles += left;
        }
        return ans;
    }
};