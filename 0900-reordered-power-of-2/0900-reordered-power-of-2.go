func reorderedPowerOf2(n int) bool {
	countDigits := func(x int) [10]int {
		var count [10]int
		for x > 0 {
			count[x%10]++
			x /= 10
		}
		return count
	}
	targetCount := countDigits(n)
	for i := 1; i <= 1e9; i <<= 1 {
		if countDigits(i) == targetCount {
			return true
		}
	}
	return false
}