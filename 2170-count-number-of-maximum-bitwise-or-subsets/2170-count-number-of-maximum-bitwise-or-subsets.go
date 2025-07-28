func countMaxOrSubsets(nums []int) int {
    n := len(nums)
    or := 0
    for _, num := range nums {
        or |= num
    }
    lim := 1 << n
    ans := 0
    for mask := 1; mask < lim; mask++ {
        tempOr := 0
        ind := 0
        for i := 1; i < lim; i <<= 1 {
            if (i & mask) != 0 {
                tempOr |= nums[ind]
            }
            ind++
        }
        if tempOr == or {
            ans++
        }
    }
    return ans
}