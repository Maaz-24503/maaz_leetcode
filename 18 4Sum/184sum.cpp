class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        unordered_map<int, bool> unique;
        unordered_map<string, bool> check;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            if(unique.find(nums[i]) == unique.end()){
                unique[nums[i]] = true;
                for(int j = i+1; j<nums.size(); j++){
                    long long sum = nums[i] + nums[j];
                    int first = 0; 
                    int second = nums.size()-1;
                    while(first<second){
                        
                        long long newsum = sum+ nums[first]+ nums[second];
                        if(first==i || first==j || second==i || second==j){
                            if(second==i || second==j){
                            second--;
                            }
                        else
                            first++;
                        }
                        else{  
                            if(newsum<target)  first++;
                            else if(newsum>target) second--;
                            else{
                                
                                vector<int> curr;
                                curr.push_back(nums[i]);
                                curr.push_back(nums[j]);
                                curr.push_back(nums[first]);
                                curr.push_back(nums[second]);
                                sort(curr.begin(),curr.end());
                                string entry = to_string(curr[0]) +","+ to_string(curr[1])+","+ to_string(curr[2]);
                                // cout<<"("<<entry<<")";
                                if(check.find(entry)==check.end()){
                                    check[entry] = true;
                                    ans.push_back(curr);
                                }
                            
                                first++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};