type NumMatrix struct {
    matrix [][]int
    preSum [][]int
    n      int
    m      int
}


func Constructor(matrix [][]int) NumMatrix {
    preSum := make([][]int, len(matrix) + 1)
    for i := 0; i <= len(matrix); i++ {
        sum := 0
        preSum[i] = make([]int, len(matrix[0]) + 1)
        if i != 0 {
            for j := 1; j <= len(matrix[0]); j++ {
                sum += matrix[i - 1][j - 1]
                preSum[i][j] = sum + preSum[i - 1][j]
            }
        }
    }
    return NumMatrix{matrix, preSum, len(matrix), len(matrix[0])}
}


func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
    topLeft, bottomRight, topRight, bottomLeft := this.preSum[row1][col1], this.preSum[row2 + 1][col2 + 1], this.preSum[row1][col2 + 1], this.preSum[row2 + 1][col1]
    return topLeft + bottomRight - (topRight + bottomLeft)
}


/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */