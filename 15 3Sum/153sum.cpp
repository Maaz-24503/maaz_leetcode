class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> numbersUsed;
        for(int i = 0; i<nums.size(); i++){
            numbersUsed.insert(nums[i]);
        }
        vector<vector<int>> ans;
        if(numbersUsed.size() == 1 && nums[0] == 0){
            if(nums.size()>2) ans.push_back(vector<int>{0,0,0});
            return ans;
        }
        unordered_set<string> used;
        
        for(int i = 1; i<nums.size()-1; i++){
            int left = 0; 
            int right = nums.size()-1;
            while(left<i && right>i){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum>0) right--;
                else if(sum<0) left++;
                else{ 
                    string currAns = to_string(nums[left]) + " "+ to_string(nums[i]) + " "+ to_string(nums[right]);
                    if(used.find(currAns) == used.end()){
                        ans.push_back(vector<int>{nums[left], nums[i], nums[right]});
                        used.insert(currAns);
                    }
                    left++;
                }
            }
        }
        return ans;
    }
};