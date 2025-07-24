func longestMountain(arr []int) int {
    n := len(arr)
    l, r := 0, 0
    for l < n - 1 && arr[l] >= arr[l + 1] {
        l++
    }
    if n - l < 3 {
        return 0
    }
    r = l + 1
    ans := 0
    for l < n - 2 {
        for r < n - 1 && arr[r] <= arr[r + 1] {
            if arr[r] == arr[r + 1] {
                l = r + 1
            }
            r++
        }
        if r == n - 1 {
            break
        }
        if l == r {
            l++
            r++
            continue
        }
        for r < n - 1 && arr[r] > arr[r + 1] {
            r++
        }
        ans = max(ans, r - l + 1)
        l = r
    }
    return ans
}