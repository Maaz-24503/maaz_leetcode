func smallestSubarrays(nums []int) []int {
    n := len(nums)
    ans := make([]int, n)
    lastBitOcc := make([]int, 31)
    for i := 0; i<31; i++ {
        lastBitOcc[i] = -1
    }
    for i := n - 1; i>=0; i-- {
        maxi := i
        for j:=0; j < 31; j++ {
            if ((1<<j) & nums[i]) != 0 {
                lastBitOcc[j] = i
            } else {
                if lastBitOcc[j] != -1 {
                    maxi = max(maxi, lastBitOcc[j])
                }
            }
        }
        ans[i] = maxi - i + 1
    }
    return ans
}