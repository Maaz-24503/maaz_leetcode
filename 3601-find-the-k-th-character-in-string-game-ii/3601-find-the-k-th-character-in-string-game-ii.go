func kthCharacter(k int64, operations []int) byte {
    var helper func(int64) byte
    helper = func(curr int64) byte {
        if curr == 1 {
            return 'a'
        }
        turn := -1
        var p int64 = 1
        for p < curr {
            p <<= 1
            turn++
        }
        p >>= 1
        if operations[turn] == 1 {
            c := helper(curr - p)
            if c == 'z' {
                return 'a';
            } else {
                return c + 1
            }
        } else {
            return helper(curr - p)
        }
    }
    return helper(k)
}

