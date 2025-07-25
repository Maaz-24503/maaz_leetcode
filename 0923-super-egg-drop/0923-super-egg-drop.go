func superEggDrop(k int, n int) int {
    dp := make([][]int, n + 1)
    for i := 0; i<=n; i++ {
        dp[i] = make([]int, k + 1)
        for j := 0; j<=k; j++ {
            dp[i][j] = -1
        }
    }
    var helper func(int,int)int
    helper = func(i, j int) int {
        if i <= 1 {
            return i
        }
        if j == 1 {
            return i
        }
        if dp[i][j] != -1 {
            return dp[i][j]
        }
        l, r, ans := 0, i, math.MaxInt
        for l <= r {
            mid := (l + r) / 2
            recLeft, recRight := helper(mid - 1, j - 1), helper(i - mid, j)
            ans = min(1 + max(recLeft, recRight), ans)
            if recLeft < recRight {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
        dp[i][j] = ans
        return ans
    }
    return helper(n, k)
}