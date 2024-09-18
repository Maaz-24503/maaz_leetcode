class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int> {nums[0]});
        for(int i = 1; i<nums.size(); i++){
            for(int j = 0; j<ans.size(); j++){
                vector<int> curr = ans[j];
                ans[j].push_back(nums[i]);
                for(int k = 0; k<curr.size(); k++){
                    vector<int> temp = curr;
                    temp.insert(temp.begin()+k, nums[i]);
                    ans.insert(ans.begin()+j, temp);
                }
                j += curr.size();
            }
        }
        return ans;
    }
};