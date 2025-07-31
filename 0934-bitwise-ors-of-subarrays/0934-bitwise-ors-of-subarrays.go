func subarrayBitwiseORs(arr []int) int {
    ans := make(map[int]bool)
    prev := make(map[int]bool)
    for _, num := range arr {
        temp := make(map[int]bool)
        temp[num] = true
        for entry, _ := range prev {
            temp[entry | num] = true
        }
        prev = temp
        for blah, _ := range prev {
            ans[blah] = true
        }
    }
    return len(ans)
}