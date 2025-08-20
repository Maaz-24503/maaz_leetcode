func countSquares(matrix [][]int) int {
    n, m := len(matrix), len(matrix[0])
    dp := make([][]int, n)
    for i := 0; i < n; i++ {
        dp[i] = make([]int, m)
        for j := 0; j < m; j++ {
            dp[i][j] = -1
        }
    }
    var helper func(int,int)int
    helper = func(i, j int) int {
        if i < 0 || j < 0 || matrix[i][j] == 0 {
            return 0
        }
        if dp[i][j] != -1 {
            return dp[i][j]
        }
        dp[i][j] = 1 + min(min(helper(i, j - 1), helper(i - 1, j)), helper(i - 1, j - 1))
        return dp[i][j]
    }
    ans := 0
    for i := 0; i<n; i++ {
        for j := 0; j<m; j++ {
            ans += helper(i, j)
        }
    }
    return ans
}