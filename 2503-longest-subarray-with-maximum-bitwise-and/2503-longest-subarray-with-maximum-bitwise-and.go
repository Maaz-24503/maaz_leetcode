func longestSubarray(nums []int) int {
    maxAnd := 0
    for _, num := range nums {
        maxAnd = max(num, maxAnd)
    }
    count, maxi := 0, 0
    for _, num := range nums {
        if num == maxAnd {
            count++
            maxi = max(maxi, count)
        } else {
            count = 0
        }
    }
    return maxi
}