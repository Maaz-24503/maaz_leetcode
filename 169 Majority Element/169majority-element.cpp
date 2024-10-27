class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem = -1;
        int count = 1;
        for(int i = 0; i<nums.size(); i++){
            if(elem == nums[i]) count++;
            else{
                if(count <= 1) elem = nums[i];
                else count--;
            }
        }
        return elem;
    }
};