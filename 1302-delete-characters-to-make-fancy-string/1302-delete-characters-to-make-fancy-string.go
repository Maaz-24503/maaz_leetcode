func makeFancyString(s string) string {
    var builder strings.Builder
    run := 0
    curr := ' '
    for _, c := range s {
        if c == curr {
            run++
        } else {
            curr = c
            run = 1
        }
        if run < 3 {
            builder.WriteRune(c)
        }
    }
    return builder.String()
}