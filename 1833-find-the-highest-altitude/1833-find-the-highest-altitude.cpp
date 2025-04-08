class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0, sum = 0, n = gain.size();
        for(int i = 0; i<n; i++){
            sum += gain[i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};