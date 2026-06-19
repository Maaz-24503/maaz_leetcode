class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0, ans = 0;
        for(int &g : gain){
            curr += g;
            ans = max(curr, ans);
        }
        return ans;
    }
};