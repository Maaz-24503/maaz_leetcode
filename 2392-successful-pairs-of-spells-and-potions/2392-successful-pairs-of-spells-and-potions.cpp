class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        function<int(int)> lowerBound = [&](int spell) -> int {
            int l = 0, r = m - 1, ans = m;
            while(l <= r){
                int mid = (l + r) / 2;
                if((spell + 0LL) * potions[mid] < success) l = mid + 1;
                else {
                    r = mid - 1;
                    ans = mid;
                }
            }
            return ans;
        };
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = m - lowerBound(spells[i]);
        }
        return ans;
    }
};