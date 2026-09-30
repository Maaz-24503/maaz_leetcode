class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0, n = seq.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            bool opening = seq[i] == '(';
            depth = opening ? depth + 1 : depth - 1;
            if(opening) ans[i] = depth % 2 ? 0 : 1;
            else ans[i] = depth % 2 ? 1 : 0;
        }
        return ans;
    }
};