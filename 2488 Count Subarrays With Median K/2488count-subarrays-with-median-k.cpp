class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> preSums;
        int occ;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < k) nums[i] = -1;
            else if(nums[i] > k) nums[i] = 1;
            else{
                occ = i;
                nums[i] = 0;
            }
        }
        // for(int i = 0; i<nums.size(); i++) cout<<nums[i]<<" ";
        // cout<<endl;
        int sum = 0;
        preSums[0] = 1;
        for(int i = 0; i<occ; i++){
            sum += nums[i];
            // cout<<sum<<" ";
            preSums[sum]++;
        }
        // for(auto& s: preSums){
        //     cout<<s.first<<": "<<s.second<<endl;
        // }
        int ans = 0;
        // if(occ>0 && nums[occ-1] == 1) ans++;
        for(int i = occ; i<nums.size(); i++){
            sum += nums[i];
            // cout<<sum<<" ";
            // cout<<i<<endl;
            if(preSums.find(sum) != preSums.end()){
                ans += preSums[sum];
                // cout<<i<<": "<<sum<<" "<<preSums[sum]<<endl;
            }
            if(preSums.find(sum - 1) != preSums.end()){ 
                ans += preSums[sum - 1];
                // cout<<i<<": "<<sum - 1<<" "<<preSums[sum-1]<<endl;
            }
        }
        return ans;
    }
};