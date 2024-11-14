class Solution {
public:
    int maxBit;

    int invert(int n){
        int mask = 1;
        while(mask <= maxBit){
            if((mask & n) == 0) n |= mask;
            else{
                int temp = ~mask;
                n = n & temp;
            }
            mask <<= 1;
        }   
        return n;
    }

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        maxBit = 1<<(maximumBit-1);
        vector<int> xors(n, nums[0]);
        for(int i = 1; i<n; i++) xors[i] = nums[i] ^ xors[i-1];
        vector<int> ans(n, 0);
        for(int i = 0; i<n; i++) ans[i] = invert(xors[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};