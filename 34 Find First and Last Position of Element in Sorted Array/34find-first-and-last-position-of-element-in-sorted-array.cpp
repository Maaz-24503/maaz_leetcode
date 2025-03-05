class Solution {
private:
    vector<int> nums;
    int n, target;

    int lBs(){
        int l = 0;
        int r = n-1;
        while(l<r){
            if(nums[l] == target) return l;
            int mid = (l + r) / 2;
            if(nums[mid] < target) l = mid+1;
            else if(nums[mid] > target) r = mid-1;
            else r = mid;
        }
        if(nums[l] != target) return -1;
        return l;
    }

    int rBs(){
        int l = 0;
        int r = n-1;
        while(l<r){
            if(nums[r] == target) return r;
            if(r - l == 1) return nums[r] == target ? r : nums[l] == target ? l : -1;
            int mid = (l + r) / 2;
            // cout<<mid<<endl;
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] > target) r = mid-1;
            else l = mid;
        }
        if(nums[l] != target) return -1;
        return l;
    }

public:

    vector<int> searchRange(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        this->n = nums.size();
        if(n == 0) return vector<int> {-1, -1};
        return vector<int>{lBs(), rBs()};
    }
};