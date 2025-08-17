func new21Game(n int, k int, maxPts int) float64 {
    if k == 0 {
        return 1.0
    }
    dp := make([]float64, n + 1)
    for i := k; i<=n; i++ {
        dp[i] = 1.0
    }
    avg := float64(min(n - k + 1, maxPts)) / float64(maxPts)
    dp[k - 1] = avg
    for i := k - 2; i >= 0; i-- {
        avg += (dp[i + 1] / float64(maxPts))
        if i + maxPts + 1 <= n {
            avg -= (dp[i + maxPts + 1] / float64(maxPts))
        }
        dp[i] = avg
    }
    return dp[0]
}