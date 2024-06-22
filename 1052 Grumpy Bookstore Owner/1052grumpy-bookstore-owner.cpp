class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int total = 0;
        int free = 0;
        vector<int> loss(n, 0);
        int curr = 0;
        for(int i = 0; i<n; i++) {
            loss[i] = grumpy[i]*customers[i];
            if(i<minutes) curr += loss[i];
            free += grumpy[i]==1?0:customers[i];
            total += customers[i];
        }
        int maxi = curr;
        for(int i = minutes; i<n; i++){
            curr += loss[i];
            curr -= loss[i-minutes];
            maxi = max(maxi, curr);
        }
        return free + maxi;
    }
};