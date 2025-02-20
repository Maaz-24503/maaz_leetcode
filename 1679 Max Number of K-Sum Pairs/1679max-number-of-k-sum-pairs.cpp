class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i< nums.size(); i++){
            freq[nums[i]]++;
        }
        int selfSum = 0;
        int sum = 0;
        for(auto [item, fr] : freq){
            if(k - item == item){
                selfSum += fr/2;
            }
            else{
                if(freq.find(k - item) != freq.end()){ 
                    sum += min(freq[k - item], fr);
                }
            }
        }
        return (sum/2) + selfSum;
    }
};