class Solution {
public:

    int countOnes(int n){
        long long mask = 1;
        int count = 0;
        while(mask<=n){
            if((mask & n) != 0) count++;
            mask <<= 1;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> countBits(n, 0);
        for(int i = 0; i<n; i++) countBits[i] = countOnes(nums[i]);
        // for(int i = 0; i<n; i++) cout<<countBits[i]<<" ";
        vector<int> check = nums;
        for(int i = 0; i<n; i++){
            int k = i;
            while(k<n && countBits[k] == countBits[i]) k++;
            // cout<<i<<": "<<k<<endl;
            sort(check.begin()+i, check.begin()+ k);
            i = k-1;
        }
        // cout<<endl;
        // for(int i = 0; i<n; i++) cout<<check[i]<<" ";
        for(int i = 0; i<n-1; i++) if(check[i] > check[i+1]) return false;
        return true;
    }
};