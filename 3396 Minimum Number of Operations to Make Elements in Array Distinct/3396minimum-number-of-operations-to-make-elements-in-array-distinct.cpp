class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int rep = -1;
        unordered_map<int, int> seen;
        for(int i = 0; i<nums.size(); i++){
            if(seen.find(nums[i]) != seen.end()){
                rep = max(rep, seen[nums[i]]);
            }
            seen[nums[i]] = i;
        }
        cout<<rep;
        return (rep + 1 + 2)/3;
    }
};