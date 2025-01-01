class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int med = arr[(arr.size()-1)/2];
        stable_sort(arr.begin(), arr.end(), [med](const int &a, const int &b) {
            if(abs(a - med) != abs(b - med)) return abs(a - med) > abs(b - med);
            return a>b;
        });
        vector<int> ans(k);
        for(int i = 0; i<k; i++) ans[i] = arr[k - i - 1];
        return ans;
    }
};