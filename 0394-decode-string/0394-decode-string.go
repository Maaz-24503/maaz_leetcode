func isDigit(c byte) bool {
    if c >= '0' && c <= '9' {
        return true
    } else {
        return false
    }
}
func isBase(s string) bool {
    for i := range s {
        if isDigit(s[i]) {
            return false
        }
    }
    return true
}
func decodeString(s string) string {
    // unicode.IsDigit()
    if isBase(s) {
        return s
    }
    ans := ""
    for i:=0; i<len(s); i++ {
        if isDigit(s[i]) {
            j := i + 1
            for isDigit(s[j]) {
                j++
            }
            freq, _ := strconv.ParseInt(s[i : j], 10, 0)
            i = j + 1
            curr, brack := 0, 1
            for brack != 0 {
                curr++
                if s[i + curr] == '[' {
                    brack++
                } else if s[i + curr] == ']' {
                    brack--
                }
            }
            sub := s[i : i + curr]
            i = i + curr
            sub = decodeString(sub)
            substr := ""
            var k int64
            for k = 0; k < freq; k++ {
                substr += sub
            }
            ans += substr
        } else {
            ans += string(s[i])
        }
    }
    return ans
}