class Solution {
public:
    string conv(vector<int>& temp){
        string s = "";
        for(int i = 0; i<temp.size(); i++){
            s += to_string(temp[i]) + " ";
        }
        return s;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> dup = nums;
        sort(dup.begin(), dup.end());
        long long limit = (1<<nums.size()) - 1;
        unordered_map<string, vector<int>> subsets;
        for(long long mask = 0; mask<=limit; mask++){
            vector<int> temp(0);
            for(int i = 0; i<dup.size(); i++){
                long long mask2 = 1<<(dup.size() - i - 1);
                if((mask & mask2) != 0) temp.push_back(dup[i]);
            }
            string s = conv(temp);
            subsets[s] = temp;
        }
        vector<vector<int>> ans;
        for(auto &i:subsets){
            ans.push_back(i.second);
        }
        return ans;
    }
};