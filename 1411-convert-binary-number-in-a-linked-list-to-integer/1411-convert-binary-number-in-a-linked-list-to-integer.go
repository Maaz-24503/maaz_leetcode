/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) int {
    ans := 0
    iter := head
    for iter != nil {
        ans <<= 1
        if (*iter).Val == 1 {
            ans += 1
        } 
        iter = (*iter).Next
    }
    return ans
}