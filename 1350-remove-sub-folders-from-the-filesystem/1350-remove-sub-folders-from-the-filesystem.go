func removeSubfolders(folder []string) []string {
    n := len(folder)
    beginsWith := func(pre, word string) bool {
        m, k := len(pre), len(word)
        if m > k {
            return false
        }
        if m != k && word[m] != '/' {
            return false
        }
        for i:=0; i<m; i++ {
            if pre[i] != word[i] {
                return false
            }
        }
        return true
    }
    sort.Strings(folder)
    ans := make([]string, 0)
    ans = append(ans, folder[0])
    for i := 1; i<n; i++ {
        if !beginsWith(ans[len(ans) - 1], folder[i]) {
            ans = append(ans, folder[i])
        }
    }
    return ans
}