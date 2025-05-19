class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);
        for(int i = n - 1; i>=0; i--){
            int curr = temperatures[i];
            while(!st.empty() && st.top().first <= curr) st.pop();
            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top().second - i;
            st.push({curr, i});
        }
        return ans;
    }
};