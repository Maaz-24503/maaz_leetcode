class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        // set<int> ans;
        // for(int i = 0; i<n; i++){
        //     if(nums[i] == key){
        //         ans.insert(i);
        //         continue;
        //     }
        //     for(int j = 1; j<=k; j++){
        //         if(i - j >= 0) 
        //             if(nums[i - j] == key) ans.insert(i);
        //         if(i + j < n)
        //             if(nums[i + j] == key) ans.insert(i);
        //     }
        // } 
        // return vector<int> (ans.begin(), ans.end());

        // O(n) approach

        set<int> ans;

        for(int i = 0; i<n; i++) 
            if(nums[i] == key){
                ans.insert(i);
                for(int j = 1; j<=k; j++){
                    if(i+j >= n) break;
                    ans.insert(i + j);
                }
                for(int j = 1; j<=k; j++){
                    if(i-j < 0 || ans.find(i-j) != ans.end()) break;
                    ans.insert(i - j);
                }
            }
        return vector<int> (ans.begin(), ans.end());
    }
};