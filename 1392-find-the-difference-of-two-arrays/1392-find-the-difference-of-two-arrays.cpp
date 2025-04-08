class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> com1, com2, dup;
        for(auto &num : nums1) com1.insert(num);
        for(auto &num : nums2) com2.insert(num);
        for(auto &num : com1) if(com2.find(num) != com2.end()) dup.insert(num);
        vector<vector<int>> ans(2);
        for(auto &num : com1) 
            if(dup.find(num) == dup.end())
                ans[0].push_back(num);
        for(auto &num : com2) 
            if(dup.find(num) == dup.end())
                ans[1].push_back(num);
        return ans;
    }
};