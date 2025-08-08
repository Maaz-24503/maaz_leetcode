func twoEggDrop(n int) int {
    dp := make([][]int, n + 1)
    for i := 0; i < n + 1; i++ {
        dp[i] = make([]int, 2)
        for j := 0; j<2; j++ {
            dp[i][j] = -1
        }
    }
    var helper func(int,int)int
    helper = func(i, j int) int {
        if i <= 0 {
            return 0
        }
        if j == 0 {
            return i
        }
        if dp[i][j] != -1 {
            return dp[i][j]
        }
        dp[i][j] = 2000    // inf
        for k := 1; k <= n; k++ {
            recLeft, recRight := helper(k - 1, j - 1), helper(i - k, j)
            dp[i][j] = min(1 + max(recLeft, recRight), dp[i][j])
        }
        return dp[i][j]
    }
    return helper(n, 1)
}