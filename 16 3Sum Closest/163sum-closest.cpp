class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        unordered_map<int,bool> check;
        int closest = INT_MAX;
        int actual_value = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++){

            int checking = nums[i] ;
            if(check.find(checking) == check.end()){
                check[checking] = true;
                int first = 0;
                int second = nums.size()-1;
                int diff = 0;
                while(first<second){
                    int diff= target - (nums[i]+nums[first]+nums[second]);
                    if(first==i||second==i){
                        if(first==i) first++;
                        else second--;
                    }
                    else{
                        if(abs(diff)<closest){
                            closest = abs(diff);
                            actual_value = target - diff;
                        } 
                        if(diff>0) first++;
                        else if(diff<0) second--;
                        else{
                            return target;
                        }
                    }
                }
            }
            
        }
        return actual_value;
    }
};