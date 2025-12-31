class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n){
        this->rank = vector<int>(n, 1);
        this->parent = vector<int>(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry)
            return;

        if (rank[rx] > rank[ry]) {
            int t = rx;
            rx = ry;
            ry = t;
        }

        parent[rx] = ry;
        rank[ry] += rank[rx];
    }
};
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<bool>> mat(row, vector<bool> (col, false));
        function<int(int, int)> conv = [&](int i, int j){
            return (i * col) + j + 1;
        };
        DSU uf(2 + (row * col));
        int top = 0, bottom = 1 + (row*col);
        for(int i = 0; i < col; i++){
            uf.unite(top, i + 1);
            uf.unite(bottom, conv(row - 1, i));
        }
        vector<vector<int>> d{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        function<bool(int, int)> isValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < row && j < col;
        };
        for(int i = cells.size() - 1; i >= 0; i--){
            int x = cells[i][0] - 1, y = cells[i][1] - 1;
            mat[x][y] = true;
            for(int j = 0; j < 4; j++){
                int dx = x + d[j][0], dy = y + d[j][1];
                if(isValid(dx, dy) && mat[dx][dy]){
                    uf.unite(conv(dx, dy), conv(x, y));
                }
            }
            if(uf.find(top) == uf.find(bottom)) return i;
        }
        return -1;
    }
};