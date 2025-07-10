func maxUncrossedLines(nums1 []int, nums2 []int) int {
    n, m := len(nums1), len(nums2)
    dp := make([][]int, n + 1)
    for i:=0; i<=n; i++ {
        dp[i] = make([]int, m + 1)
        for j:=0; j<=m; j++ {
            dp[i][j] = -1
        }
    }
    var helper func (int,int) int
    helper = func(i, j int) int {
        if i == n || j == m {
            return 0
        }
        if dp[i][j] != -1 {
            return dp[i][j]
        }
        if nums1[i] == nums2[j] {
            dp[i][j] = 1 + helper(i + 1, j + 1)
            return dp[i][j]
        }
        dp[i][j] = max(helper(i + 1, j), helper(i, j + 1))
        return dp[i][j]
    }
    return helper(0, 0)
}