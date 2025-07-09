func longestArithSeqLength(nums []int) int {
    n, ans := len(nums), 1
    max := func(a, b int) int {
        if a > b {
            return a
        } else {
            return b
        }
    }
    for i:=-500; i<501; i++ {
        mp := make(map[int]int)
        tempAns := 1
        for j := 0; j<n; j++ {
            f, valid := mp[nums[j] - i]
            thisNum, thisValid := mp[nums[j]]
            if valid {
                if thisValid {
                    mp[nums[j]] = max(thisNum, f + 1)
                } else {
                    mp[nums[j]] = f + 1
                }
            } else {
                mp[nums[j]] = 1
            }
            tempAns = max(tempAns, mp[nums[j]])
        }
        ans = max(tempAns, ans)
    }
    return ans
}