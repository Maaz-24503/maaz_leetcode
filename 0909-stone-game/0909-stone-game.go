func stoneGame(piles []int) bool {
    n := len(piles)
    var helper func(int,int,bool) int
    dp := make([][][]int, 2)
    for i:=0; i<2; i++ {
        dp[i] = make([][]int, n)
        for j := 0; j<n; j++ {
            dp[i][j] = make([]int, n)
            for k := 0; k<n; k++ {
                dp[i][j][k] = -1
            }
        }
    }
    helper = func(i, j int, isAlice bool) int {
        k := -1
        if isAlice {
            k = 1
        } else {
            k = 0
        }
        if i == j {
            if isAlice {
                return piles[i]
            } else {
                return -piles[i]
            }
        }
        if dp[k][i][j] != -1 {
            return dp[k][i][j]
        }
        if isAlice {
            dp[k][i][j] = max(piles[i] + helper(i + 1, j, !isAlice), piles[j] + helper(i, j - 1, !isAlice))
        } else {
            dp[k][i][j] = min( -piles[i] + helper(i + 1, j, !isAlice), -piles[j] + helper(i, j - 1, !isAlice))
        }
        return dp[k][i][j]
    }
    return helper(0, n - 1, true) > 0
}