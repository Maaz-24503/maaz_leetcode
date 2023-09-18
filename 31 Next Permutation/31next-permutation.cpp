class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      bool possible = true;
      int curr = INT_MIN;
      int ind = -1;
      for(int i = nums.size()-1;i>=0; i--){
        if(curr>nums[i]){
          ind = i;
          curr = nums[i];
          break;
        }
        curr = nums[i];
      }
      
      if(ind==-1) sort(nums.begin(), nums.end());
      else{
        int next = INT_MAX;
        int ind2 = 0;
        for(int i = nums.size()-1; i>ind; i--){
          if(nums[i]>curr && nums[i]<next) {
            next = nums[i];
            ind2 = i;
          }
        }
        nums[ind] = nums[ind2];
        nums[ind2] = curr;
      
        sort(nums.begin()+ind+1, nums.end());
      }
    }
};