class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange){
            int full = 0;
            while(numBottles >= numExchange){
                full++;
                numBottles -= numExchange;
                numExchange++;
            }
            ans += full;
            numBottles += full;
        }
        return ans;
    }
};