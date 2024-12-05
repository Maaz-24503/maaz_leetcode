class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int curr = 0;
        vector<int> st;
        unordered_map<int, int> iterVis;
        for(int i = 0; i<edges.size(); i++){
            if(iterVis.find(i) == iterVis.end()){
                iterVis[i] = i;
                curr = i;
                while(edges[curr] != -1){
                    if(iterVis.find(edges[curr]) != iterVis.end()){
                        if(iterVis[edges[curr]] == i) st.push_back(edges[curr]);
                        break;
                    }
                    iterVis[curr] = i;
                    curr = edges[curr];
                }
            }
        }
        if(st.size() == 0) return -1;
        int maxi = -1;
        for(int i = 0; i<st.size(); i++){
            int ans = 1;
            int curr = st[i];
            while(edges[curr] != st[i]){
                ans++;
                curr = edges[curr];
            }
            maxi = max(ans, maxi);
        }
        return maxi;
    }
};