class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++) 
            for(int j = i; j < n; j++) 
                st.insert(nums[i] ^ nums[j]);
        vector<int> pairs(st.begin(), st.end());
        st.clear();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < pairs.size(); j++)
                st.insert(nums[i] ^ pairs[j]);
        return st.size();
    }
};