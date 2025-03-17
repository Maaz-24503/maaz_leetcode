class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n == 1) return gas[0] >= cost[0] ? 0 : -1;
        int sum = gas[0] - cost[0];
        int l = 0, r = 0;
        while(l - r != 1 && r != n-1){
            if(sum <= 0){
                l--;
                l = (l + n) % n;
                sum += gas[l] - cost[l];
            }
            else{
                r++;
                r %= n;
                sum += gas[r] - cost[r];
            }
        }
        return sum >= 0 ? l : -1;
    }
};