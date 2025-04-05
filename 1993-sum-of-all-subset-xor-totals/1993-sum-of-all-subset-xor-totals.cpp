class Solution {
    int n;
    vector<int> nums;

    vector<int> perm(){
        vector<int> res{0};
        for(int i = 0; i<n; i++){
            int k = res.size();
            for(int j = 0; j<k; j++) res.push_back(res[j]^nums[i]);
        }
        return res;
    }

    int sum(vector<int>& xors){
        int sum = 0;
        for(auto &num: xors) sum += num;
        return sum;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        vector<int> xors = perm();
        return sum(xors);
    }
};