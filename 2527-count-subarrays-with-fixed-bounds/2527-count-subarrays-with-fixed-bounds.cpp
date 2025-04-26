class Solution {
private:
    vector<int> nums;
    int minK, maxK;

    long long helper(int i, int j){
        if(j - i == 0 && nums[i] == minK && minK == maxK) return 1LL;
        if(j - i <= 0) return 0LL; 
        
        long long ans = 0;
        int countMin = 0, countMax = 0;
        int l = i, r = i;  
        
        while(l <= j){
            while(r <= j && (countMin == 0 || countMax == 0)){
                if(nums[r] == minK) countMin++;
                if(nums[r] == maxK) countMax++;
                r++;
            }
            if(countMin == 0 || countMax == 0) break;
            ans += j - (r - 1) + 1;
            if(nums[l] == minK) countMin--;
            if(nums[l] == maxK) countMax--;
            l++;
        }
        
        return ans;
    }

public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        this->minK = minK;
        this->maxK = maxK;
        this->nums = nums;
        vector<int> occ;
        for(int i = 0; i<n; i++)
            if(nums[i] > maxK || nums[i] < minK) occ.push_back(i);
        if(occ.size() == 0) return helper(0, n-1);
        long long ans = helper(0, occ[0] - 1);
        for(int i = 0; i<occ.size()-1; i++){
            ans += helper(occ[i] + 1, occ[i + 1] - 1);
        }
        return ans + helper(occ[occ.size() - 1] + 1, n-1);
    }
};