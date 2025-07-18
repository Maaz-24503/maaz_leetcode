func numRollsToTarget(n int, k int, target int) int {
    mod := 1000000007
    var helper func(int,int) int
    memo := make([][]int, n + 1)
    for i:=0; i<=n; i++ {
        memo[i] = make([]int, target + 1)
        for j:=0; j<=target; j++ {
            memo[i][j] = -1
        }
    }
    helper = func(i int, j int) int {
        if i == 0 {
            if j == 0 {
                return 1
            } else {
                return 0
            }
        }
        if j <= 0 {
            return 0
        }
        if memo[i][j] != -1 {
            return memo[i][j]
        }
        ans := 0
        for m := 1; m <= k; m++ {
            ans = (ans + helper(i - 1, j - m)) % mod
        }
        memo[i][j] = ans
        return memo[i][j]
    }
    return helper(n, target)
}