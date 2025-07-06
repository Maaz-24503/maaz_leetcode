class FindSumPairs {
private:
    unordered_map<int, int> mp;
    vector<int> nums1, nums2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int &num : nums2) this->mp[num]++;
    }
    
    void add(int index, int val) {
        int prev = nums2[index];
        mp[prev]--;
        mp[prev + val]++;
        nums2[index] = prev + val;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int &num : nums1) if(mp.count(tot - num)) ans += mp[tot - num];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */