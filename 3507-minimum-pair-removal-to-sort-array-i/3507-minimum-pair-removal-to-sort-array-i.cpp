class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        function<bool(int)> isSorted = [&](int i) -> bool {
            int sum = nums[i] + nums[i + 1];
            nums[i] = sum;
            nums.erase(nums.begin() + i + 1);
            for(int k = 0; k + 1 < nums.size(); k++)
                if(nums[k] > nums[k + 1]) return false;
            return true;
        };
        bool sorted = true;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                sorted = false;
                break;
            }
        }
        if(sorted) return 0;
        int i = -1, ans = 0;
        do {
            ans++;
            int mini = INT_MAX;
            for(int k = 0; k + 1 < nums.size(); k++){
                if(nums[k] + nums[k + 1] < mini) {
                    i = k;
                    mini = nums[k] + nums[k + 1];
                }
            }
        } while(!isSorted(i));
        return ans;
    }
};