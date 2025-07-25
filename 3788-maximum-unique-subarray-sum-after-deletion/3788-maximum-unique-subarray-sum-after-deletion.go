func maxSum(nums []int) int {
    ans := 0
    maxi := math.MinInt
    mp := make(map[int]bool)
    for _, num := range nums {
        _, ok := mp[num]
        if !ok && num > 0 {
            mp[num] = true
            ans += num
        }
        maxi = max(num, maxi)
    }
    if maxi <= 0 {
        return maxi
    }
    return ans
}