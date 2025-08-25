func lastStoneWeightII(stones []int) int {
    n := len(stones)
    dp := make([]map[int]int, n + 1)
    for i := 0; i <= n; i++ {
        dp[i] = make(map[int]int)
    } 
    var helper func(int, int) int
    helper = func(i, s int) int {
        if i == n {
            if s >= 0 {
                return s
            } else {
                return math.MaxInt
            }
        }
        ans, ok := dp[i][s]
        if ok {
            return ans
        }
        dp[i][s] = min(helper(i + 1, s + stones[i]), helper(i + 1, s - stones[i]))
        return dp[i][s]
    }
    return helper(0, 0)
}