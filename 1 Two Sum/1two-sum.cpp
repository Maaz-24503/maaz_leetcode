class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> cpy;
        for(int i = 0; i<nums.size(); i++) cpy.push_back({nums[i], i});
        sort(cpy.begin(), cpy.end());
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            int sum = cpy[left].first + cpy[right].first;
            if(sum>target) right--;
            else if(sum<target) left++;
            else return vector<int> {cpy[left].second, cpy[right].second};
        }
        return vector<int>{0,0};
    }
};