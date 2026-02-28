class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size(), zeros = 0;
        vector<set<int>> trees(2);
        for(int i = 0; i <= n; i++){
            trees[i%2].insert(i);
            if(i < n && s[i] == '0') zeros++;
        }
        vector<int> moves(n + 1, INT_MAX);
        queue<int> bfs;
        bfs.push(zeros);
        moves[zeros] = 0;
        trees[zeros%2].erase(zeros);
        while(!bfs.empty()){
            zeros = bfs.front(); bfs.pop();
            int c1 = max(k - n + zeros, 0), c2 = min(zeros, k);
            int lnode = zeros + k - 2 * c2, rnode = zeros + k - 2 * c1; 
            for(auto iter = trees[lnode%2].lower_bound(lnode); iter != trees[lnode%2].end() && *iter <= rnode; ){
                int curr = *iter;
                moves[curr] = moves[zeros] + 1;
                bfs.push(curr);
                iter = next(iter);
                trees[curr%2].erase(curr);
            }
        }
        return moves[0] == INT_MAX ? -1 : moves[0];  
    }
};
// int lnode = m + k - 2 * c2, rnode = m + k - 2 * c1;      