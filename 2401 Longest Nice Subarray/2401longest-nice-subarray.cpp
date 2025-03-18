class Solution {
private:
    void clean(vector<int>& taken, int curr){
        long long mask = 1;
        int ind = 0;
        while(mask <= curr){
            if((mask & curr) != 0) taken[ind] = -1;
            mask <<= 1;
            ind++;
        }
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> taken(32, -1);
        int l = 0, r = -1, ans = 1;
        if(n == 0) return 0;
        while(l<n && r<n){
            r++;
            if(r == n) break;
            int curr = nums[r];
            long long mask = 1;
            bool isValid = true;
            int prob = -1;
            int ind = 0;
            while(mask <= curr){
                if((mask & curr) != 0 && taken[ind] != -1){
                    isValid = false;
                    prob = max(taken[ind], prob);
                }
                ind++;
                mask <<= 1;
            }
            if(isValid){
                mask = 1, ind = 0;
                while(mask <= curr){
                    if((mask & curr) != 0) taken[ind] = r;
                    ind++;
                    mask <<= 1;
                }
                ans = max(ans, r - l + 1);
            }
            else{
                while(l <= prob){
                    clean(taken, nums[l++]);
                }
                mask = 1, ind = 0;
                while(mask <= curr){
                    if((mask & curr) != 0) taken[ind] = r;
                    ind++;
                    mask <<= 1;
                }
                // ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};