func kthCharacter(k int) byte {
    str := "a"
    for len(str) < k {
        n := len(str)
        for i:=0; i<n; i++ {
            if str[i] == 'z' {
                str += "a"
            } else {
                str += string(str[i] + 1)
            }
        }
    }
    return str[k - 1]
}