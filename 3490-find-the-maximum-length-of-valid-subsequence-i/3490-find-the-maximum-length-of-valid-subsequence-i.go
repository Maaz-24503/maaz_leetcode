func maximumLength(nums []int) int {
    mono, n := 0, len(nums)
    for _, num := range nums {
        if num % 2 == 1 {
            mono++
        }
    }
    // subsequence with the same parity throughout
    mono = max(mono, n - mono)
    // Now we check alternating
    alt := 1
    var isOdd bool
    if nums[0] % 2 == 1 {
        isOdd = true
    } else {
        isOdd = false
    }
    for i := 1; i<n; i++ {
        if isOdd != (nums[i] % 2 == 1) {
            isOdd = !isOdd
            alt++
        }
    }
    return max(alt, mono)
}