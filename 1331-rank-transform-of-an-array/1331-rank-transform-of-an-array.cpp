class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> temp;
        for(int i = 0; i < n; i++){
            temp.push_back({arr[i], i});
        }
        sort(temp.begin(), temp.end());
        vector<int> ans(n);
        int i = 0, prev = INT_MIN;
        for(auto [num, ind] : temp){
            if(num > prev) i++;
            prev = num;
            ans[ind] = i;
        }
        return ans;
    }
};