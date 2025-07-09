func findMaxLength(nums []int) int {
    n := len(nums)
    pre := make([]int, n)
    if nums[0] == 1 {
        pre[0] = 1
    } else {
        pre[0] = -1
    }
    for i:=1; i<n; i++ {
        if nums[i] == 1 {
            pre[i] = 1 + pre[i - 1]
        } else {
            pre[i] = -1 + pre[i - 1]
        }
    }
    max := func(a, b int) int {
        if a > b {
            return a
        } else {
            return b
        }
    }
    mp := make(map[int]int)
    mp[0] = -1
    ans := 0
    for i:=0; i<n; i++ {
        ind, ok := mp[pre[i]]
        if ok{
            ans = max(ans, i - ind)
        } else {
            mp[pre[i]] = i
        }
    }
    return ans
}