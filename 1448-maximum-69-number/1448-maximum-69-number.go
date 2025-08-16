func maximum69Number(num int) int {
    str := fmt.Sprintf("%d", num)
    bytes := []byte(str)

    for i := 0; i < len(bytes); i++ {
        if bytes[i] == '6' {
            bytes[i] = '9'
            break
        }
    }

    ans, _ := strconv.Atoi(string(bytes))
    return ans
}
