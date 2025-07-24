func shortestCommonSupersequence(str1 string, str2 string) string {
    n, m := len(str1), len(str2)
    dp := make([][]int, n + 1)
    for i := 0; i < n + 1; i++ {
        dp[i] = make([]int, m + 1)
        for j := 0; j < m + 1; j++ {
            if i == n {
                dp[i][j] = m - j
            } else if j == m {
                dp[i][j] = n - i
            }
        }
    }

    for i := n - 1; i >= 0; i-- {
        for j := m - 1; j >= 0; j-- {
            if str1[i] == str2[j] {
                dp[i][j] = 1 + dp[i + 1][j + 1]
            } else {
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1])
            }
        }
    }

    ans := ""
    i, j := 0, 0

    for i < n || j < m {
        if i == n {
            ans += str2[j : m]
            break
        }
        if j == m {
            ans += str1[i : n]
            break
        }
        if str1[i] == str2[j] {
            ans += string(str1[i])
            i++
            j++
        } else {
            if dp[i + 1][j] < dp[i][j + 1] {
                ans += string(str1[i])
                i++
            } else {
                ans += string(str2[j])
                j++
            }
        }
    }
    
    return ans
}