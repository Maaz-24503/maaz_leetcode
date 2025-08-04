func totalFruit(fruits []int) int {
    n := len(fruits)
    if n < 3 {
        return n
    }
    mp := make(map[int]int)
    l, r := 0, -1
    ans := 0
    for r < n {
        for len(mp) <= 2 {
            r++
            if r == n {
                break
            }
            _, ok := mp[fruits[r]]
            if !ok {
                mp[fruits[r]] = 1
            } else {
                mp[fruits[r]]++
            }
        }
        ans = max(ans, r - l)
        for len(mp) > 2 {
            mp[fruits[l]]--
            if mp[fruits[l]] == 0 {
                delete(mp, fruits[l])
            }
            l++
        }
    }
    return ans
}