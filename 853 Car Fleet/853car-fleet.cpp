class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> time(n);
        for(int i = 0; i<n; i++) time[i] = {position[i], (target - position[i])*1.0/speed[i]};
        sort(time.begin(), time.end());
        int fleets = 0;
        float maxi = -0.1;
        for(int i = n-1; i>=0; i--){
            if(maxi < time[i].second){
                maxi = time[i].second;
                fleets++;
            }
        }
        return fleets;
    }
};