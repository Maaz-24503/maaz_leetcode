class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries.size(), m = dictionary.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int off = 0;
                for(int k = 0; k < queries[i].size(); k++){
                    if(queries[i][k] != dictionary[j][k]) off++;
                    if(off > 2) break;
                }
                if(off <= 2) {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};