class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int n = nums.size();
        unordered_set<int> ind;
        for(int i = 0; i<n; i++) ind.insert(nums[i]);
        int maxi = 1;
        for(auto &item: ind){
            // cout<<nums[i]<<endl;
            if(ind.find(item - 1) == ind.end()){
                int curr = item;
                int count = 1;
                while(ind.find(curr+1) != ind.end()){
                    curr++;
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};