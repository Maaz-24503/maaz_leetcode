func maxValue(events [][]int, k int) int {
    slices.SortFunc(events, func(a, b []int) int {
        return a[0] - b[0]
    })
    n := len(events)
    bs := func (target int) int {
        l, r := 0, n
        for l < r {
            mid := l + (r - l) / 2
            if events[mid][0] <= target {
                l = mid + 1
            } else {
                r = mid
            }
        }
        return l
    }
    next := make([]int, n)
    for i := 0; i<n; i++ {
        next[i] = bs(events[i][1])
    }
    dp := make([][]int, n + 1)
    for i := 0; i<=n; i++ {
        dp[i] = make([]int, k + 1)
    }
    for i := n - 1; i>=0; i-- {
        for j := k - 1; j>=0; j-- {
            dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[next[i]][j+1]);
        }
    }
    return dp[0][0]
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}