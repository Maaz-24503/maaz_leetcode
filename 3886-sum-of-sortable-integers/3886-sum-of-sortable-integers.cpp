class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        
        auto check = [&](int k, int i) -> bool {
            int ind = i;      
            int drops = 0;

            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    drops++;
                    if (drops > 1) return false;   
                    ind = j + 1;                   
                }
            }

            int diff = ind - i;
            for (int j = 0; j < k; j++) {
                int curr = (j + diff) % k;
                if (sorted[i + j] != nums[i + curr]) return false;
            }
            return true;
        };

        int ans = 0;

        for(int p = 1; p <= n; p++){
            if(n % p) continue;
            bool isValid = true;
            for(int i = 0; i < n; i += p){
                if(!check(p, i)) {
                    isValid = false;
                    break;
                }
            }
            if(isValid) ans += p;
        }

        return ans;
    }
};