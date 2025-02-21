class Solution {
public:
    vector<int> nums;
    int n;
    int k;
    int target;

    int conv(int i){
        return (i+k)%n;
    }

    int bs(int l, int r){
        if(l == r){
            return target == nums[conv(l)] ? conv(l) : -1;
        }
        // cout<<l<<" "<<r<<endl;
        if(r<l) return -1;
        int l1 = conv(l);
        int r1 = conv(r);
        int mid = (l+r)/2;
        int m1 = conv(mid);
        if(nums[m1] > target) return bs(l, mid-1);
        if(nums[m1] < target) return bs(mid + 1, r);
        return m1;
    }

    int bs1(int l, int r){
        if(nums[l] <= nums[r]) return l;
        int mid = (l + r)/2;
        if(nums[mid] < nums[l]) return bs1(l, mid);
        return bs1(mid + 1, r);
    }

    int search(vector<int>& nums, int target) {
        this->target = target;
        n = nums.size();
        this->nums = nums;
        this->k = bs1(0, n-1);
        return bs(0, n-1);
    }
};