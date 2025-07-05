func findLucky(arr []int) int {
    freq := make(map[int]int)
    for _, num := range arr {
        freq[num]++
    }
    ans := -1
    for k, v := range freq {
        if k == v {
            if k > ans {
                ans = k
            }
        }
    }
    return ans
}