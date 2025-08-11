func productQueries(n int, queries [][]int) []int {
    mod := int64(1e9 + 7)
    arr := make([]int, 0)
    for i := 1; i<=n; i<<=1 {
        if (i & n) != 0 {
            arr = append(arr, i)
        }
        if int64(i) >= mod {
            break
        }
    }
    preComp := make([][]int, len(arr))
    for i := 0; i<len(arr); i++ {
        preComp[i] = make([]int, len(arr))
        var prod int64 = 1
        for j := i; j<len(arr); j++ {
            prod = (prod * int64(arr[j])) % mod
            preComp[i][j] = int(prod)
        }
    }
    ans := make([]int, len(queries))
    for i := 0; i<len(queries); i++ {
        ans[i] = preComp[queries[i][0]][queries[i][1]]
    }
    return ans
}