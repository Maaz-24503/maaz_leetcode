class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> mt;
        int maxi = 0;
        int lastPopped = 1;
        for(int i = 0; i<n; i++){
            if(i == 0){
                mt.push({heights[i], i});
                maxi = heights[i];
            }
            else {
                while(!mt.empty() && mt.top().first >= heights[i]){
                    auto [val, ind] = mt.top();
                    maxi = max(val * (i - ind), maxi);
                    lastPopped = ind;
                    mt.pop();
                }
                // cout<<heights[i]<<" "<<(lastPopped)<<endl;
                mt.push({heights[i], lastPopped});
                lastPopped = i+1;
            }
        }
        while(!mt.empty()){
            maxi = max(mt.top().first * (n - mt.top().second), maxi);
            mt.pop();
        }
        return maxi;
    }
};