func largestGoodInteger(num string) string {
    maxi := -1
    for i := 0; i<len(num)-2; i++ {
        if num[i] == num[i + 1] && num[i] == num[i + 2] {
            maxi = max(int(num[i] - '0'), maxi)
        }
    }
    if maxi == -1 {
        return ""
    } else if maxi == 0 {
        return "000"
    }
    return strconv.FormatInt(int64((100*maxi) + (10*maxi) + maxi), 10)
}