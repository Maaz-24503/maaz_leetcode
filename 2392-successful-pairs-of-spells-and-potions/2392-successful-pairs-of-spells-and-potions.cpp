class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        function<int(long long)> bs = [&](long long target){
            int l = 0, r = m-1;
            int ans = m;
            while(l<=r){
                int mid = l + (r - l)/2;
                if(potions[mid] < target) l = mid+1;
                else{
                    r = mid - 1;
                    ans = mid;
                }
            }
            return m - ans;
        };
        for(int i = 0; i<n; i++){
            long long target = (success + spells[i] - 1LL) / spells[i];
            ans[i] = bs(target);
        }
        return ans;
    }
};