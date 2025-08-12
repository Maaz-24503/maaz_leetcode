func numberOfWays(n int, x int) int {
    root, num := 1, 1
    for num <= n {
        root++
        num = root
        for i := 0; i < x - 1; i++ {
            num *= root
        }
    }
    root--
    mod := int(1e9 + 7)
    dp := make([][]int, root + 1)
    for i := 0; i < root + 1; i++ {
        dp[i] = make([]int, n + 1)
        for j := 0; j < n + 1; j++ {
            dp[i][j] = -1
        }
    }
    var helper func(int,int) int
    helper = func(i int, left int) int {
        if left == 0 {
            return 1
        }
        if left < 0 {
            return 0
        }
        if i > root {
            return 0
        }
        if dp[i][left] != -1 {
            return dp[i][left]
        }
        val := 1
        for k := 0; k < x; k++ {
            val *= i
        }
        dp[i][left] = (helper(i + 1, left - val) + helper(i + 1, left)) % mod
        return dp[i][left]
    }
    return helper(1, n)
}