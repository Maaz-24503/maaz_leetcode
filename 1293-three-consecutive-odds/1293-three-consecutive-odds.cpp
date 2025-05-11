class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        size_t n = arr.size();
        for(size_t i = 0; i + 2 < n; i++){
            if(arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2) return true;
        }
        return false;
    }
};