class Solution {
private:
    void invert(vector<int>& nums, int i, int j){
        for(int ii = i; ii<=((i + j)/2); ii++) swap(nums[ii], nums[j - ii + i]);
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(nums.size() < 2) return;
        k = k % n;  
        int temp = (n - k);
        invert(nums, 0, temp - 1);   
        invert(nums, temp, n - 1);   
        invert(nums, 0, n - 1);      
    }
};