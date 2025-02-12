class Solution {
public:
    int getSum(int k) {
        int ans = 0; 
        while (k > 0) {
            ans += k % 10; 
            k /= 10;       
        }
        return ans; 
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> digSums(n);
        for (int i = 0; i < n; i++) digSums[i] = getSum(nums[i]);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[digSums[i]].push_back(nums[i]);
        }
        int ans = -1;
        for(auto &item : mp){
            if(item.second.size()>1){
                vector<int> temp = item.second;
                sort(temp.begin(), temp.end());
                ans = max(ans, temp[temp.size()-1] + temp[temp.size()-2]);
            }
        }
        return ans;
    }
};