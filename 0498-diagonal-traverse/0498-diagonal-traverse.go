func findDiagonalOrder(mat [][]int) []int {
    n, m := len(mat), len(mat[0])
    ans := make([]int, n*m)
    count := 0
    diags := n + m - 1
    currX, currY := 0, 0
    for i := 0; i<diags; i++ {
        if i % 2 == 0 {
            for currX < m && currY >= 0 {
                ans[count] = mat[currY][currX]
                count++
                currY--
                currX++
            }
            if i < m - 1 {
                currY = 0
                currX = i + 1
            } else {
                currY = i - m + 2
                currX = m - 1
            }
        } else {
            for currX >= 0 && currY < n {
                ans[count] = mat[currY][currX]
                count++
                currY++
                currX--
            }
            if i < n - 1 {
                currX = 0
                currY = i + 1
            } else {
                currY = n - 1
                currX = i - n + 2
            }
        }
    }
    return ans
}