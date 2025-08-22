func minimumArea(grid [][]int) int {
    minX, minY, maxX, maxY := 10000, 10000, 0, 0
    for i, row := range grid {
        for j, cell := range row {
            if cell == 1 {
                minX = min(minX, j)
                minY = min(minY, i)
                maxX = max(maxX, j)
                maxY = max(maxY, i)
            }
        }
    }
    return (maxX - minX + 1) * (maxY - minY + 1)
}