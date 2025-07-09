func longestOnes(nums []int, k int) int {
    n := len(nums)
    l, r := 0, -1
    z, ans := 0, 0
    for r < n {
        for z > k {
            if nums[l] == 0 {
                z--
            }
            l++
        }
        for r < n && z < k+1 {
            r++
            if r == n {
                break
            }
            if nums[r] == 0 {
                z++
            }
        }
        ans = max(r - l, ans)
    }
    return ans
}