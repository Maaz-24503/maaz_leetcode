func profitableSchemes(n int, minProfit int, group []int, profit []int) int {
    mod := 1000000007
    dp := make([][][]int, len(group))
    for i := 0; i<len(group); i++ {
        dp[i] = make([][]int, minProfit + 1)
        for j := 0; j<minProfit + 1; j++ {
            dp[i][j] = make([]int, n + 1)
            for k := 0; k < n + 1; k++ {
                dp[i][j][k] = -1
            }
        }
    }
    var helper func(int,int,int) int
    helper = func(i, j, k int) int {
        if k < 0 {
            return 0
        }
        if j <= 0 {
            j = 0
            if i >= 0 {
                if dp[i][j][k] != -1 {
                    return dp[i][j][k]
                }
                dp[i][0][k] = (helper(i - 1, 0, k - group[i]) + helper(i - 1, 0, k)) % mod
                return dp[i][0][k]
            } else {
                return 1
            }
        }
        if i < 0 {
            return 0
        }
        if dp[i][j][k] != -1 {
            return dp[i][j][k]
        }
        dp[i][j][k] = (helper(i - 1, j - profit[i], k - group[i]) + helper(i - 1, j, k)) % mod
        return dp[i][j][k]
    }
    return helper(len(group) - 1, minProfit, n)
}