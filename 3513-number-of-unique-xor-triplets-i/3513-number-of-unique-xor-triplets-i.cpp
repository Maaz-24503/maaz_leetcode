class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size(), mask = 1;
        if(n <= 2) return n;
        while(mask <= n){
            mask <<= 1;
        }
        return mask;
    }
};