func hasAlternatingBits(n int) bool {
    mask := 1
    for mask <= n {
        if ((mask & n) == 0) == (((mask<<1) & n) == 0) {
            return false
        } else {
            mask <<= 1
        }
    }
    return true;
}