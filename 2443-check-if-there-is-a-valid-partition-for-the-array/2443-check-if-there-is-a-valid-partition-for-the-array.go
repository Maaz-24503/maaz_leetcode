func validPartition(nums []int) bool {
    n := len(nums)
    dp := make([]int, n)
    for i := 0; i < n; i++ {
        dp[i] = -1
    }
    var helper func(int)int
    helper = func(i int) int {
        if i == n {
            return 1
        }
        if dp[i] != -1 {
            return dp[i]
        }
        if n - i < 2 {
            return 0
        }
        if n - i == 2 {
            if nums[i] == nums[i + 1] {
                return 1
            } else {
                return 0
            }
        }
        ans := 0
        if nums[i] == nums[i + 1] {
            ans += helper(i + 2)
        }
        if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2]) || (nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2]) {
            ans += helper(i + 3)
        }
        dp[i] = ans
        if dp[i] > 0 {
            dp[i] = 1
        }
        return dp[i]
    }
    ans := helper(0)
    if ans == 0 {
        return false
    } else {
        return true
    }
}