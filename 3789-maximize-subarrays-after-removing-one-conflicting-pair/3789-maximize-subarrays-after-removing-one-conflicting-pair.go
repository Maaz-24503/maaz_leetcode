func maxSubarrays(n int, conflictingPairs [][]int) int64 {
    right := make([][]int, n+1)
    for _, pair := range conflictingPairs {
        a, b := pair[0], pair[1]
        maxVal := a
        minVal := b
        if b > a {
            maxVal, minVal = b, a
        }
        right[maxVal] = append(right[maxVal], minVal)
    }

    ans := int64(0)
    left := []int64{0, 0}
    bonus := make([]int64, n+1)

    for r := 1; r <= n; r++ {
        for _, lVal := range right[r] {
            l := int64(lVal)
            if l > left[0] {
                left = []int64{l, left[0]}
            } else if l > left[1] {
                left = []int64{left[0], l}
            }
        }
        ans += int64(r) - left[0]

        if left[0] > 0 {
            bonus[left[0]] += left[0] - left[1]
        }
    }

    maxBonus := int64(0)
    for _, b := range bonus {
        if b > maxBonus {
            maxBonus = b
        }
    }

    return ans + maxBonus
}
