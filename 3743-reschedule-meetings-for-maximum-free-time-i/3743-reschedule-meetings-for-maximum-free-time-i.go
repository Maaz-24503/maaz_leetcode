func maxFreeTime(eventTime int, k int, startTime []int, endTime []int) int {
    n := len(startTime)
    gap := make([]int, n+1)
    gap[0] = startTime[0]
    gap[n] = eventTime - endTime[n - 1]
    for i:=1; i<n; i++ {
        gap[i] = startTime[i] - endTime[i - 1]
    }
    ans, sum := 0, 0
    for i:=0; i < n + 1; i++ {
        sum += gap[i]
        if i > k {
            sum -= gap[i - k - 1]
        }
        ans = max(ans, sum)
    }
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}