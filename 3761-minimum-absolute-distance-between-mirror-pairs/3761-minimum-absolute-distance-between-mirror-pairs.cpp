class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        unordered_map<string, int> ind;
        
        function<string(string)> rev = [&](string k) -> string {
            reverse(k.begin(), k.end());
            while(k[0] == '0') k = k.substr(1);
            return k;
        };

        for(int i = 0; i < n; i++){
            string curr = to_string(nums[i]);
            if(ind.find(curr) != ind.end()) ans = min(ans, i - ind[curr]);
            ind[rev(curr)] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};