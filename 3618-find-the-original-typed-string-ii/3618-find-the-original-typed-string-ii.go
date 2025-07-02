func possibleStringCount(word string, k int) int {
	const MOD int = 1e9 + 7
	n := len(word)

	run := 1
	runs := []int{}

	for i := 1; i < n; i++ {
		if word[i] == word[i-1] {
			run++
		} else {
			runs = append(runs, run)
			run = 1
		}
	}
	runs = append(runs, run)

	total := 1
	for _, r := range runs {
		total = (total * r) % MOD
	}

	if len(runs) >= k {
		return total
	}
	if k > n {
		return 0
	}

	ways := make([]int, k)
	prefixSum := make([]int, k)
	ways[0] = 1
	for i := range prefixSum {
		prefixSum[i] = 1
	}

	for i := 0; i < len(runs); i++ {
		nextWays := make([]int, k)
		for j := 1; j < k; j++ {
			nextWays[j] = prefixSum[j-1]
			if j - runs[i] - 1 >= 0 {
				nextWays[j] = (nextWays[j] - prefixSum[j-runs[i]-1] + MOD) % MOD
			}
		}

		newPrefix := make([]int, k)
		newPrefix[0] = nextWays[0]
		for j := 1; j < k; j++ {
			newPrefix[j] = (newPrefix[j-1] + nextWays[j]) % MOD
		}

		ways, prefixSum = nextWays, newPrefix
	}

	return (total - prefixSum[k-1] + MOD) % MOD
}
