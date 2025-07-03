func kthCharacter(k int) byte {
    var arr []byte
    arr = append(arr, 'a')
    for len(arr) < k {
        for _, c := range arr{
            if c == 'z'{
                arr = append(arr, 'a')
            } else {
                arr = append(arr, c + 1)
            }
        }
    }
    return arr[k - 1]
}