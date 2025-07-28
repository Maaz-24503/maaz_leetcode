/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func allPossibleFBT(n int) []*TreeNode {
    dp := make(map[int][]*TreeNode)
    var helper func(int)[]*TreeNode
    helper = func(i int) []*TreeNode {
        if i == 1 {
            return []*TreeNode{&TreeNode{Val: 0, Left: nil, Right: nil}}
        }
        mem, ok := dp[i]
        if ok {
            return mem 
        }
        ans := make([]*TreeNode, 0)
        for k := 1; k<i-1; k += 2 {
            recLeft, recRight := helper(k), helper(i - k - 1)
            for _, left := range recLeft {
                for _, right := range recRight {
                    root := &TreeNode{Val: 0, Left: left, Right: right}
                    ans = append(ans, root)
                }
            }
        }
        dp[n] = ans
        return ans
    }
    return helper(n)
}