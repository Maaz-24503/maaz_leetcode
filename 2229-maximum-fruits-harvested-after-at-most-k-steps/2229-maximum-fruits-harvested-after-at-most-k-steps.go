func maxTotalFruits(baskets [][]int, pos int, limit int) int {
    abs := func(x int) int {
        if x < 0 {
            return -x
        }
        return x
    }
    
    helper := func(a, b, s int) int {
        return min(
            abs(s-a)+(b-a),
            abs(s-b)+(b-a),
        )
    }

    l, current, answer := 0, 0, 0

    for r := 0; r < len(baskets); r++ {
        current += baskets[r][1]
        for l <= r && helper(baskets[l][0], baskets[r][0], pos) > limit {
            current -= baskets[l][1]
            l++
        }
        if current > answer {
            answer = current
        }
    }

    return answer
}