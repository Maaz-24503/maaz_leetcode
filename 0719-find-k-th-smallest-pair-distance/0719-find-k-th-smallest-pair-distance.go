func smallestDistancePair(nums []int, k int) int {
    n := len(nums)
    slices.Sort(nums)
    lessThanEq := func(guess int) int {
        // Imagine matrix[n][n], matrix[i][j] holds nums[j] - nums[j]
        // Now we are gonna keep counting for each row how many diffs are <= guess
        // Start at 0, 0
        ans, j := 0, 1
        for i := 0; i < n; i++  {
            for j < n && nums[j] - nums[i] <= guess {
                j++
            }
            ans += j - i - 1
        }
        return ans
    }
    // Diff can be from 0 to 1e6, binary search this range
    l, r := 0, 1000001
    for l < r {
        guess := l + ((r - l)/2)
        res := lessThanEq(guess)
        if res >= k {
            r = guess
        } else {
            l = guess + 1
        }
    }
    return l
}