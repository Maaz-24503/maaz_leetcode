func numOfUnplacedFruits(fruits []int, baskets []int) int {
    n := len(fruits)
    done := 0
    for _, fruitCount := range fruits {
        for i := 0; i<n; i++ {
            if baskets[i] >= fruitCount {
                baskets[i] = 0
                done++
                break
            }
        }
    }
    return n - done
}