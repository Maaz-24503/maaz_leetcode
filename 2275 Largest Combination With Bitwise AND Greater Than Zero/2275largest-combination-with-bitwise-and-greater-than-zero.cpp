class Solution {
public:
    
    int largestCombination(vector<int>& candidates) {
        int maxi = 0;
        int lim = *max_element(candidates.begin(), candidates.end());
        for(int mask = 1; mask<=lim; mask = mask<<1){
            int count = 0;
            for(int i = 0; i<candidates.size(); i++){
                if((mask & candidates[i]) != 0) count++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};