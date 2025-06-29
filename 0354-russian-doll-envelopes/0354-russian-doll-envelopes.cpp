class Solution {
private:
    int LIS(vector<vector<int>>& envelopes){
        int n = envelopes.size();
        vector<int> temp;
        for(int i = 0; i<n; i++){
            if(!temp.size() || temp.back() < envelopes[i][1]) temp.push_back(envelopes[i][1]);
            else {
                auto target = lower_bound(temp.begin(), temp.end(), envelopes[i][1]);
                *target = envelopes[i][1];
            }
        }
        return temp.size();
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        return LIS(envelopes);
    }
};