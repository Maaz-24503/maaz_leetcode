func minFlipsMonoIncr(s string) int {
    n := len(s)
    suffSum := make([]int, n)
    suffSum[n - 1] = int(s[n - 1] - '0')
    for i := n - 2; i>=0; i-- {
        suffSum[i] = suffSum[i + 1] + int(s[i] - '0')
    }
    preSum := 0
    ans := n - suffSum[0]
    for i := 0; i < n-1; i++ {
        preSum += int(s[i] - '0')
        ans = min(ans, preSum + (n - i - 1 - suffSum[i + 1]))
    }
    ans = min(ans, preSum + int(s[n - 1] - '0'))
    return ans
}