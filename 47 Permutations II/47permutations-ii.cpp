class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<string> visited;
        ans.push_back(vector<int> {nums[0]});
        for(int i = 1; i<nums.size(); i++){
            for(int j = 0; j<ans.size(); j++){
                vector<int> curr = ans[j];
                string temp1 = "";
                for(int t = 0; t< ans[j].size(); t++) temp1 += to_string(ans[j][t]) + " ";
                temp1 += to_string(nums[i])+" ";
                int counter = 0;
                if(visited.find(temp1) == visited.end()){
                    visited.insert(temp1);
                    ans[j].push_back(nums[i]);
                }
                else{
                    counter--;
                    ans.erase(ans.begin()+j);
                }
                for(int k = 0; k<curr.size(); k++){
                    vector<int> temp = curr;
                    temp.insert(temp.begin()+k, nums[i]);
                    string curr1 = "";
                    for(int t = 0; t< temp.size(); t++) curr1 += to_string(temp[t]) + " ";
                    if(visited.find(curr1) == visited.end()){
                        counter++;
                        visited.insert(curr1);
                        ans.insert(ans.begin()+j, temp);
                    }
                }
                j += counter;
            }
        }
        return ans;
    }
};
