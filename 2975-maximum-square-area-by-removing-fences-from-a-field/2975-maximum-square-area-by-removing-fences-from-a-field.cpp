class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.insert(hFences.begin(), 1);
        vFences.insert(vFences.begin(), 1);
        hFences.push_back(m);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<int> vComb;
        priority_queue<int> hComb;
        for(int i = 0; i < vFences.size() - 1; i++){
            for(int j = i + 1; j < vFences.size(); j++) {
                vComb.insert(vFences[j] - vFences[i]);
            }
        }
        for(int i = 0; i < hFences.size() - 1; i++){
            for(int j = i + 1; j < hFences.size(); j++) {
                hComb.push(hFences[j] - hFences[i]);
            }
        }
        int MOD = 1e9 + 7;
        while(!hComb.empty()){
            int curr = hComb.top();
            cout<<curr<<" ";
            hComb.pop();
            if(vComb.find(curr) != vComb.end()) return ((curr + 0LL) * curr) % MOD;
        }
        return -1;
    }
};