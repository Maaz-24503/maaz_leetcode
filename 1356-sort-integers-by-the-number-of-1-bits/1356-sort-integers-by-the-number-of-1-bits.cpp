class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        function<int(int)> countBits = [](const int &k) -> int {
            int mask = 1, ans = 0;
            while(mask <= k) {
                if((mask & k) != 0) ans++;
                mask <<= 1;
            }
            return ans;
        };
        vector<int> ans(arr.begin(), arr.end());
        sort(ans.begin(), ans.end(), [countBits](const int &a, const int &b) {
            int countA = countBits(a), countB = countBits(b);
            if(countA == countB) return a < b;
            else return countA < countB;
        });
        return ans;
    }
};