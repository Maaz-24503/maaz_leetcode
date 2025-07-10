/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
    ans := math.MinInt32
    var helper func(*TreeNode) int
    helper = func(node *TreeNode) int {
        if node == nil {
            return 0
        }
        r, l := helper(node.Right), helper(node.Left)
        ans = max(ans, r + l + node.Val)
        return max(node.Val + max(r, l), 0)
    }
    helper(root)
    return ans
}