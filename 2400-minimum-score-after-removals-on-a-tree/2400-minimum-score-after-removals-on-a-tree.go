func minimumScore(nums []int, edges [][]int) int {
	n := len(nums)
	graph := buildGraph(n, edges)
	children, xorVal, total := bfs(nums, graph)

	return findMinScore(edges, children, xorVal, total)
}

func buildGraph(n int, edges [][]int) [][]int {
	graph := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		graph[u] = append(graph[u], v)
		graph[v] = append(graph[v], u)
	}
	return graph
}

func bfs(nums []int, graph [][]int) ([]map[int]struct{}, []int, int) {
	n := len(nums)
	children := make([]map[int]struct{}, n)
	for i := range children {
		children[i] = make(map[int]struct{})
	}
	xorVal := make([]int, n)
	copy(xorVal, nums)

	degree := make([]int, n)
	for u := 0; u < n; u++ {
		for _, v := range graph[u] {
			degree[v]++
		}
	}

	total := 0
	for _, val := range nums {
		total ^= val
	}

	seen := make([]bool, n)
	queue := []int{}
	for i := 0; i < n; i++ {
		if degree[i] == 1 {
			queue = append(queue, i)
			seen[i] = true
		}
	}

	for len(queue) > 0 {
		cur := queue[0]
		queue = queue[1:]

		for _, next := range graph[cur] {
			if !seen[next] {
				children[next][cur] = struct{}{}
				for ch := range children[cur] {
					children[next][ch] = struct{}{}
				}
				xorVal[next] ^= xorVal[cur]
			}
			degree[next]--
			if degree[next] == 1 && !seen[next] {
				seen[next] = true
				queue = append(queue, next)
			}
		}
	}

	return children, xorVal, total
}

func findMinScore(edges [][]int, children []map[int]struct{}, xorVal []int, total int) int {
	res := math.MaxInt32
	m := len(edges)

	for i := 0; i < m-1; i++ {
		for j := i + 1; j < m; j++ {
			a, b := edges[i][0], edges[i][1]
			if _, ok := children[a][b]; ok {
				a, b = b, a
			}
			c, d := edges[j][0], edges[j][1]
			if _, ok := children[c][d]; ok {
				c, d = d, c
			}

			var vals []int
			if _, ok := children[a][c]; ok {
				vals = []int{xorVal[c], xorVal[a] ^ xorVal[c], total ^ xorVal[a]}
			} else if _, ok := children[c][a]; ok {
				vals = []int{xorVal[a], xorVal[c] ^ xorVal[a], total ^ xorVal[c]}
			} else {
				vals = []int{xorVal[a], xorVal[c], total ^ xorVal[a] ^ xorVal[c]}
			}

			maxVal, minVal := vals[0], vals[0]
			for _, v := range vals {
				if v > maxVal {
					maxVal = v
				}
				if v < minVal {
					minVal = v
				}
			}
			if maxVal-minVal < res {
				res = maxVal - minVal
			}
		}
	}
	return res
}
