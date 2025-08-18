func judgePoint24(cards []int) bool {
    const eps = 1e-6
    
    nums := make([]float64, len(cards))
    for i := 0; i < len(cards); i++ {
        nums[i] = float64(cards[i])
    }
    
    var helper func([]float64) bool
    helper = func(arr []float64) bool {
        if len(arr) == 1 {
            return abs(arr[0] - 24.0) < eps
        }
        
        for i := 0; i < len(arr); i++ {
            for j := i + 1; j < len(arr); j++ {
                a, b := arr[i], arr[j]
                
                next := make([]float64, 0, len(arr)-1)
                for k := 0; k < len(arr); k++ {
                    if k != i && k != j {
                        next = append(next, arr[k])
                    }
                }
                
                operations := []float64{
                    a + b,
                    a - b,
                    b - a,
                    a * b,
                }
                
                if abs(b) > eps {
                    operations = append(operations, a/b)
                }
                if abs(a) > eps {
                    operations = append(operations, b/a)
                }
                
                for _, result := range operations {
                    if helper(append(next, result)) {
                        return true
                    }
                }
            }
        }
        return false
    }
    
    return helper(nums)
}

func abs(x float64) float64 {
    if x < 0 {
        return -x
    }
    return x
}