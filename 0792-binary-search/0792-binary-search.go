func search(nums []int, target int) int {
    n := len(nums)
    l, r := 0, n-1
    for l <= r {
        mid := (l + r) / 2
        if nums[mid] < target {
            l = mid + 1
        } else if nums[mid] > target {
            r = mid - 1
        } else {
            return mid
        }
    }
    return -1
}