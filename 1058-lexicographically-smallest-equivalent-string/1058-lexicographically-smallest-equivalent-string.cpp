class UnionFind{
private:
    vector<int> rank, par;
public:
    UnionFind(){
        rank.resize(26, 1);
        par.resize(26, 1);
        for(int i = 0; i<26; i++) par[i] = i;
    }

    int find(int u){
        if(u == par[u]) return u;
        int temp = find(par[u]);
        return par[u] = temp;
    }

    void join(int a, int b){
        a = find(a);
        b = find(b);
        if(rank[a] == rank[b]){
            rank[a]++;
            par[b] = a;
        }
        else if(rank[a] < rank[b]) par[a] = b;
        else par[b] = a;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> mini(26);
        int n = s1.size();
        for(int i = 0; i<26; i++) mini[i] = i;
        UnionFind dsu;
        for(int i = 0; i<n; i++){
            dsu.join(s1[i] - 'a', s2[i] - 'a');
            int id1 = dsu.find(s1[i] - 'a');
            mini[id1] = min({s1[i] - 'a', s2[i] - 'a', mini[id1]});
        }
        string ans = "";
        int m = baseStr.size();
        for(int i = 0; i<m; i++){
            char append = 'a' + mini[dsu.find(baseStr[i] - 'a')];
            ans += string(1, append);
        }
        return ans;
    }
};