func generate(numRows int) [][]int {
    ans := make([][]int, numRows)
    for i := 1; i <= numRows; i++ {
        row := i - 1
        ans[row] = make([]int, i)
        for j := 0; j < i; j++ {
            if j == 0 || j == i - 1 {
                ans[row][j] = 1
            } else {
                ans[row][j] = ans[row - 1][j - 1] + ans[row - 1][j]
            }
        }
    }
    return ans
}