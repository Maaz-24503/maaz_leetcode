class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int elems = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] != 0 && elems != i){
                swap(nums[i], nums[elems]);
                while(elems<i && nums[elems] != 0) elems++;
            }
            else if(nums[i] != 0) elems++;
        }
    }
};