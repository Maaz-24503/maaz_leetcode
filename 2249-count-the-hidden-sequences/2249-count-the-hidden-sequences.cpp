class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> arr(n+1, 0);
        for(int i = 1; i<n+1; i++) arr[i] = arr[i-1] + (differences[i-1] + 0LL);
        int maxi = *max_element(arr.begin(), arr.end()), mini = *min_element(arr.begin(), arr.end());
        return maxi - mini <= upper - lower ? upper - lower - maxi + mini + 1 : 0;
    }
};