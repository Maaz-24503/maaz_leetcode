class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> l(arr.size(), 0);
        vector<int> r(arr.size(), 0);
        stack<pair<int, int>> nextMin;
        for(int i = 0; i<arr.size(); i++){
            while(!nextMin.empty() && nextMin.top().first >= arr[i]) nextMin.pop();
            if(nextMin.empty()) l[i] = i+1;
            else l[i] = i - nextMin.top().second;
            nextMin.push({arr[i], i});
        }
        while(!nextMin.empty()) nextMin.pop();
        for(int i = arr.size()-1; i>=0; i--){
            while(!nextMin.empty() && nextMin.top().first > arr[i]) nextMin.pop();
            if(nextMin.empty()) r[i] = arr.size() - i;
            else r[i] = nextMin.top().second - i;
            nextMin.push({arr[i], i});
            // cout<<r[i]<<endl;
        }
        long long ans = 0;
        // for(int i = 0; i<arr.size(); i++) cout<<l[i]<<" "<<r[i]<<endl;
        for(int i = 0; i<arr.size(); i++) ans = (ans + (l[i] * r[i])*(arr[i] + 0LL))%1000000007;
        return ans;
    }
};