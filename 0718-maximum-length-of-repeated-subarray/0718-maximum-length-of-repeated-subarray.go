func findLength(nums1 []int, nums2 []int) int {
    n1, n2 := len(nums1), len(nums2)
    dp := make([][]int, n1)
    for i, _ := range dp {
        dp[i] = make([]int, n2)
    }
    ans := 0
    for i := 0; i<n1; i++ {
        for j := 0; j<n2; j++ {
            if i == 0 || j == 0 {
                if nums1[i] == nums2[j] {
                    dp[i][j] = 1
                }
            } else if nums1[i] == nums2[j] {
                dp[i][j] = 1 + dp[i-1][j-1]
            }
            ans = max(ans, dp[i][j])
        }
    }
    return ans;
}

func max(a int, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}