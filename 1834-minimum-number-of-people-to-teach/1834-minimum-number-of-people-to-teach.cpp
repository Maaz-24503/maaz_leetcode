class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langs(m);
        for(int i = 0; i<m; i++) langs[i] = unordered_set<int>(languages[i].begin(), languages[i].end());
        unordered_set<int> problems;
        function<bool(int,int)> canCommunicate = [&](int u, int v) {
            for(auto &lang : langs[u]){
                if(langs[v].find(lang) != langs[v].end()) return true;
            }
            return false;
        };
        for(int i = 0; i<friendships.size(); i++){
            int u = friendships[i][0] - 1, v = friendships[i][1] - 1;
            if(!canCommunicate(u, v)){
                problems.insert(u);
                problems.insert(v);
            }
        }
        unordered_map<int, int> count;
        int maxi = 0;
        for(auto &u : problems){
            for(auto &l : languages[u]) {
                count[l]++;
                maxi = max(count[l], maxi);
            }
        }
        return problems.size() - maxi;
    }
};