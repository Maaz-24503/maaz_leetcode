class Solution {
public:
    vector<int> nums;
    int maxOperations;

    bool isValid(int n){
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            count += ((nums[i] + n - 1) / n) - 1;
        }
        return count<=maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        this->nums = nums;
        this->maxOperations = maxOperations;
        long long l = 1, r = *max_element(nums.begin(), nums.end());
        while(l<r){
            int mid = l + ((r - l) / 2);
            if(isValid(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};