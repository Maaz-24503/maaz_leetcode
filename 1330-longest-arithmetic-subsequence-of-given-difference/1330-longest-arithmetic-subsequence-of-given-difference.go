func longestSubsequence(arr []int, difference int) int {
    mp := make(map[int]int)
    n := len(arr)
    ans := 0
    max := func(a, b int) int {
        if a > b { 
            return a
        } else {
            return b
        }
    }
    for i:=0; i<n; i++ {
        f, pres := mp[arr[i] - difference]
        curr, currPres := mp[arr[i]]
        if pres {
            if currPres {
                mp[arr[i]] = max(curr, f + 1)
            } else {
                mp[arr[i]] = f + 1
            }
        } else {
            mp[arr[i]] = 1
        }
        ans = max(ans, mp[arr[i]])
    }
    return ans
}