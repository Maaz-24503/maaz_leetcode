class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        auto minSum = [](vector<vector<int>>& g, int top, int bottom, int left, int right) -> int {
            int minRow = g.size(), maxRow = 0, minCol = g[0].size(), maxCol = 0;
            for (int i = top; i <= bottom; i++) {
                for (int j = left; j <= right; j++) {
                    if (g[i][j] == 1) {
                        minRow = min(minRow, i);
                        maxRow = max(maxRow, i);
                        minCol = min(minCol, j);
                        maxCol = max(maxCol, j);
                    }
                }
            }
            return minRow <= maxRow ? (maxRow - minRow + 1) * (maxCol - minCol + 1) : INT_MAX / 3;
        };

        auto rotateGrid = [](vector<vector<int>>& g) -> vector<vector<int>> {
            int rows = g.size(), cols = g[0].size();
            vector<vector<int>> rotated(cols, vector<int>(rows));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    rotated[cols - j - 1][i] = g[i][j];
                }
            }
            return rotated;
        };

        auto solveGrid = [&](vector<vector<int>>& g) -> int {
            int rows = g.size(), cols = g[0].size();
            int result = rows * cols;
            for (int i = 0; i + 1 < rows; i++) {
                for (int j = 0; j + 1 < cols; j++) {
                    result = min(result, minSum(g, 0, i, 0, cols - 1) + minSum(g, i + 1, rows - 1, 0, j) + minSum(g, i + 1, rows - 1, j + 1, cols - 1));
                    result = min(result, minSum(g, 0, i, 0, j) + minSum(g, 0, i, j + 1, cols - 1) + minSum(g, i + 1, rows - 1, 0, cols - 1));
                }
            }
            for (int i = 0; i + 2 < rows; i++) {
                for (int j = i + 1; j + 1 < rows; j++) {
                    result = min(result, minSum(g, 0, i, 0, cols - 1) + minSum(g, i + 1, j, 0, cols - 1) + minSum(g, j + 1, rows - 1, 0, cols - 1));
                }
            }
            return result;
        };

        vector<vector<int>> rotatedGrid = rotateGrid(grid);
        return min(solveGrid(grid), solveGrid(rotatedGrid));
    }
};
