class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> val;
        for(auto& num: nums)
            if(num >= k) val.insert(num);
            else return -1;
        if(!val.count(k)) return val.size();
        return val.size() - 1;
    }
};