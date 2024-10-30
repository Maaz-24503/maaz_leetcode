class Solution {
public:

    pair<int, int> maxim(pair<int, int> a, pair<int, int> b){
        return a.first>=b.first? a:b;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<pair<int, int>> LIS(nums.size(), {1, -1});
        vector<pair<int, int>> LDS(nums.size(), {1, -1});
        
        LIS[0] = {1, 0};
        LDS[nums.size()-1] = {1,nums.size()-1};

        for(int i = 1; i<nums.size(); i++){
            LIS[i].second = i;
            LDS[nums.size() - i - 1].second = nums.size() - i - 1;
            // cout<<i<<" LIS: "<<LIS[i].second<<" LDS: "<<LDS[i].second<<endl;
        }

        for(int i = 1; i<nums.size(); i++){
            for(int j = 0; j<i; j++){
                if(nums[j]<nums[i]){
                    // cout<<j<<" "<<i<<endl;
                     LIS[i] = maxim({LIS[i].first, i}, {1+LIS[j].first, i});
                }
            }
        }

        for(int i = nums.size()-2; i>=0; i--){
            for(int j = nums.size()-1; j>i; j--){
                if(nums[j]<nums[i]) LDS[i] = maxim({LDS[i].first, i}, {1+LDS[j].first, i});
            }
        }

        int maxi = 0;
        
        // for(int i = 0; i<nums.size(); i++) cout<<i<<" "<<LIS[i].first<<", "<<LIS[i].second<<endl;

        // for(int i = 1; i<nums.size(); i++){
        //     cout<<i<<" LIS: "<<LIS[i].first<<", "<<LIS[i].second<<" LDS: "<<LDS[i].first<<", "<<LDS[i].second<<endl;
        // }

        for(int i = 1; i<nums.size()-1; i++){
            int currScore = LIS[i].first + LDS[i].first;
            if(nums[LIS[i].second] == nums[LDS[i].second]){
                if(LIS[i].first == 1 || LDS[i].first == 1) continue;
                else currScore--;
            }
            maxi = max(currScore, maxi);
        }
        return nums.size() - maxi;
    }
};