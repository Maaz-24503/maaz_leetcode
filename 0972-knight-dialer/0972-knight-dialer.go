func knightDialer(n int) int {
    adjList := make([][]int, 10)
    adjList[0] = []int{4, 6}
    adjList[1] = []int{8, 6}
    adjList[2] = []int{7, 9}
    adjList[3] = []int{8, 4}
    adjList[4] = []int{3, 9, 0}
    adjList[5] = []int{}
    adjList[6] = []int{1, 7, 0}
    adjList[7] = []int{2, 6}
    adjList[8] = []int{1, 3}
    adjList[9] = []int{2, 4}
    dp := make([][]int, n)
    mod := 1000000007
    for i := 0; i < n; i++ {
        dp[i] = make([]int, 10)
        for j := 0; j<10; j++ {
            dp[i][j] = -1
        }
    }
    var helper func(int,int) int
    helper = func(i, j int) int {
        if i == 0 {
            return 1
        }
        if dp[i][j] != -1 {
            return dp[i][j]
        }
        ans := 0
        for _, v := range adjList[j] {
            ans = (ans + helper(i - 1, v)) % mod
        }
        dp[i][j] = ans
        return ans
    }
    ans := 0
    for i := 0; i<10; i++ {
        ans = (ans + helper(n - 1, i)) % mod
    }
    return ans
}