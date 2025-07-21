func maxScoreSightseeingPair(values []int) int {
    ans, n, currLargest := 0, len(values), values[0]
    for i:=1; i<n; i++ {
        currLargest--
        ans = max(ans, currLargest + values[i])
        currLargest = max(currLargest, values[i])
    }
    return ans
}