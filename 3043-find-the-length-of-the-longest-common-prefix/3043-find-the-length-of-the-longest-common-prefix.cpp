class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> preSet;
        int n = arr1.size(), m = arr2.size();
        for(int i = 0; i < n; i++){
            string curr = to_string(arr1[i]);
            string pre = "";
            for(int j = 0; j < curr.size(); j++){
                pre += string(1, curr[j]);
                preSet.insert(pre);
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            string curr = to_string(arr2[i]);
            string pre = "";
            for(int j = 0; j < curr.size(); j++){
                pre += string(1, curr[j]);
                if(preSet.find(pre) != preSet.end()) ans = max(ans, (int) pre.size());
            }
        }
        return ans;
    }
};