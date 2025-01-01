class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        unordered_set<double> seen;
        for(int i = 2; i<=n; i++){
            for(int j = 1; j<i; j++){
                double curr = (j*1.0) / (i*1.0);
                curr = round(curr * 100000.0) / 100000.0;
                if(seen.find(curr) == seen.end()){
                    ans.push_back(to_string(j) + '/' + to_string(i));
                    seen.insert(curr);
                }
            }
        }
        return ans;
    }
};