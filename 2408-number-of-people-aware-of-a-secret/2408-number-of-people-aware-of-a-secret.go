func peopleAwareOfSecret(n int, delay int, forget int) int {
    dp := make([]int, n + 1)
    for i := 0; i < n + 1; i++ {
        dp[i] = -1
    }
    mod := int(1e9 + 7)
    var helper func(int) int
    helper = func(i int) int {
        if i > n {
            return 0
        }
        if dp[i] != -1 {
            return dp[i]
        }
        sum := 1        // The person themself
        for k := delay ; k < forget && i + k <= n; k++ {
            sum = (sum + helper(k + i)) % mod
        }
        dp[i] = sum
        if i + forget <= n {
            dp[i]--
        }
        return dp[i]
    } 
    return helper(1)
}