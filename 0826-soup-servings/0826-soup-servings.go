func soupServings(n int) float64 {
    if n > 5000 {
        return 1.0
    }
    dp := make([][]float64, n + 1);
    for i := 0; i < n + 1; i++ {
        dp[i] = make([]float64, n + 1);
        for j := 0; j < n + 1; j++ {
            dp[i][j] = -1.0;
        }
    }
    var helper func(int,int) float64;
    helper = func(i, j int) float64 {
        if i == 0 && j == 0 {
            return 0.5;
        }
        if j == 0 {
            return 0.0;
        }
        if i == 0 {
            return 1.0;
        }
        if dp[i][j] > -0.5 {
            return dp[i][j]
        }
        dp[i][j] = (helper(max(i - 100, 0), j) + helper(max(i - 75, 0), max(j - 25, 0)) + helper(max(i - 50, 0), max(j - 50, 0)) + helper(max(i - 25, 0), max(j - 75, 0))) / 4.0
        return dp[i][j]
    }
    return helper(n, n);
}