class Solution {
private:
    vector<int> nums;
    int k, n;

    bool isValid(int x){
        int count = 0;
        for(int i = 0; i<n; i++) if(nums[i] <= x) {count++; i++;}
        return count>=k;
    }

    int binarySearch(){
        int l = 0, r = *max_element(nums.begin(), nums.end());
        int ans = r;
        while(l<=r){
            if(l == r){
                return isValid(l) ? l : l+1;
            }
            int mid = (l+r)/2;
            if(isValid(mid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return l;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
        n = nums.size();
        return binarySearch();
    }
};