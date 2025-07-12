func earliestAndLatest(n int, firstPlayer int, secondPlayer int) []int {
    mask := (1<<n) - 1
    firstMask := 1<<(firstPlayer-1)
    secondMask := 1<<(secondPlayer-1)
    memo := make(map[int]int)
    var maxFinder func(int) int
    maxFinder = func(m int) int {
        res, ok := memo[m]
        if ok {
            return res
        }
        matches := make([][]int, 0)
        l, r := 1, 1<<(n-1)
        for l<r {
            for (l & m) == 0 && l < r {
                l <<= 1
            }
            if l >= r {
                break
            }
            for (r & m) == 0 && r > l {
                r >>= 1
            }
            if l >= r {
                break
            }
            app := []int{l, r}
            matches = append(matches, app)
            l <<= 1
            r >>= 1
        }
        comb := make([]int, 0)
        comb = append(comb, m)
        for i:=0; i<len(matches); i++ {
            temp := make([]int, 0)
            for _, num := range comb {
                isEnd := (matches[i][0] == firstMask && matches[i][1] == secondMask) || 
                        (matches[i][1] == firstMask && matches[i][0] == secondMask)
                if isEnd {
                    return 1
                }
                if matches[i][0] != firstMask && matches[i][0] != secondMask {
                    temp = append(temp, num - matches[i][0])
                }
                if matches[i][1] != firstMask && matches[i][1] != secondMask {
                    temp = append(temp, num - matches[i][1])
                }
            }
            comb = temp
        } 
        ans := 0
        for _, iter := range comb {
            ans = max(ans, maxFinder(iter))
        }
        memo[m] = 1 + ans
        return memo[m]
    }
    dp := make(map[int]int)
    var minFinder func(int) int
    minFinder = func(m int) int {
        res, ok := dp[m]
        if ok {
            return res
        }
        matches := make([][]int, 0)
        l, r := 1, 1<<(n-1)
        for l<r {
            for (l & m) == 0 && l < r {
                l <<= 1
            }
            if l >= r {
                break
            }
            for (r & m) == 0 && r > l {
                r >>= 1
            }
            if l >= r {
                break
            }
            app := []int{l, r}
            matches = append(matches, app)
            l <<= 1
            r >>= 1
        }
        comb := make([]int, 0)
        comb = append(comb, m)
        for i:=0; i<len(matches); i++ {
            temp := make([]int, 0)
            for _, num := range comb {
                isEnd := (matches[i][0] == firstMask && matches[i][1] == secondMask) || 
                        (matches[i][1] == firstMask && matches[i][0] == secondMask)
                if isEnd {
                    return 1
                }
                if matches[i][0] != firstMask && matches[i][0] != secondMask {
                    temp = append(temp, num - matches[i][0])
                }
                if matches[i][1] != firstMask && matches[i][1] != secondMask {
                    temp = append(temp, num - matches[i][1])
                }
            }
            comb = temp
        } 
        ans := math.MaxInt32
        for _, iter := range comb {
            ans = min(ans, minFinder(iter))
        }
        dp[m] = 1 + ans
        return dp[m]
    }
    return []int{minFinder(mask), maxFinder(mask)}
}