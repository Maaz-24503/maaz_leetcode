class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> helper(capacity.size());
        for(int i = 0; i<capacity.size(); i++){
            helper[i] = capacity[i] - rocks[i];
        }
        sort(helper.begin(), helper.end());
        int count = 0;
        for(int i = 0; i<helper.size(); i++){
            if(additionalRocks<helper[i]) return count;
            additionalRocks -= helper[i];
            count++;
        }
        return helper.size();
    }
};