class Solution {
public:
    vector<int> store;

    void bs(int num){
        int l = 0, r = store.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(store[mid] >= num) r = mid;
            else l = mid+1;
        }
        store[l] = num;
    }

    int lengthOfLIS(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(store.size() == 0 || store[store.size()-1] < nums[i]) store.push_back(nums[i]);
            else bs(nums[i]);
        }
        return store.size();
    }
};