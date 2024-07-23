class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> temp;
        for(int i = 0; i<nums.size(); i++){
            temp.insert(nums[i]);
        }
        vector<int> sub;
        for(auto& i:temp){
            sub.push_back(i);
        }
        nums = sub;
        return sub.size();
    }
};