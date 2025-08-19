func zeroFilledSubarray(nums []int) int64 {
    n := len(nums)
    var ans int64 = 0
    l, r := 0, 0
    for l < n {
        for l < n && nums[l] != 0 {
            l++
        }
        if l == n {
            break
        }
        r = l
        for r < n && nums[r] == 0 {
            r++
        }
        ans += (int64(r - l + 1)*int64(r - l)) / 2
        l = r + 1
    }
    return ans
}