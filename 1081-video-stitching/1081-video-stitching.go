func videoStitching(clips [][]int, time int) int {
    n := len(clips)
    dp := make([][]int, n)
    for i:=0; i<n; i++ {
        dp[i] = make([]int, time + 1)
        for j:=0; j<time + 1; j++ {
            dp[i][j] = -1
        }
    }
    sort.Slice(clips, func(i, j int) bool {
		return clips[i][0] < clips[j][0]
	})
    var helper func(int,int) int
    helper = func(i, j int) int {
        if i == n {
            if j < time {
                return math.MaxInt
            } else {
                return 0
            }
        }
        if j >= time {
            return 0
        }
        if j < clips[i][0] {
            return math.MaxInt
        }
        if dp[i][j] != -1 {
            return dp[i][j]
        }
        recTake, recNotTake := helper(i + 1, clips[i][1]), helper(i + 1, j)
        dp[i][j] = math.MaxInt
        if recTake != math.MaxInt {
            dp[i][j] = recTake + 1
        }
        if recNotTake != math.MaxInt {
            dp[i][j] = min(dp[i][j], recNotTake)
        }
        return dp[i][j]
    }
    ans := helper(0, 0)
    if ans == math.MaxInt {
        return -1
    } else {
        return ans
    }
}