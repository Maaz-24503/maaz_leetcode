func matchPlayersAndTrainers(players []int, trainers []int) int {
    slices.Sort(players)
    slices.Sort(trainers)
    ans := 0
    i, j, n, m := 0, 0, len(players), len(trainers)
    for i < n && j < m {
        if players[i] <= trainers[j] {
            ans++
            i++
            j++
        } else {
            j++
        }
    }
    return ans
}