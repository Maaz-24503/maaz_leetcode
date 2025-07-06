type FindSumPairs struct {
    mp      map[int]int
    nums1   []int
    nums2   []int
}


func Constructor(nums1 []int, nums2 []int) FindSumPairs {
    mp := make(map[int]int)
    for _, num := range nums2 {
        _, valid := mp[num]
        if valid {
            mp[num]++
        } else {
            mp[num] = 1
        }
    }
    return FindSumPairs{mp, nums1, nums2}
}


func (this *FindSumPairs) Add(index int, val int)  {
    prev := this.nums2[index]
    this.mp[prev]--
    this.mp[prev + val]++
    this.nums2[index] = prev + val
}


func (this *FindSumPairs) Count(tot int) int {
    ans := 0
    for _, num := range this.nums1 {
        f, present := this.mp[tot - num]
        if present {
            ans += f
        }
    }
    return ans
}


/**
 * Your FindSumPairs object will be instantiated and called as such:
 * obj := Constructor(nums1, nums2);
 * obj.Add(index,val);
 * param_2 := obj.Count(tot);
 */