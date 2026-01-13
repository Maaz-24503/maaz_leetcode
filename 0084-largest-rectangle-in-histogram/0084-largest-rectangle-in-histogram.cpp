class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;   // {height, ind}
        int n = heights.size(), ans = 0;
        for(int i = 0; i<n; i++){
            int currInd = i, maxArea = 0;
            while(!st.empty() && st.top().first > heights[i]){
                auto [h, ind] = st.top();
                st.pop();
                ans = max(ans, (i - ind) * h);
                currInd = ind;
            } 
            st.push({heights[i], currInd});
        }
        while(!st.empty()){
            auto [h, i] = st.top();
            st.pop();
            ans = max(ans, (n - i) * h);
        }
        return ans;
    }
};