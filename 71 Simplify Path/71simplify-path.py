class Solution:
    def simplifyPath(self, path: str) -> str:
        words = path.split('/')
        stck = []
        for word in words:
            if word == '..':
                if len(stck) > 0:
                    stck.pop()
            elif word != '.' and word != '':
                stck.append(word)
        ans = ""
        for word in stck:
            ans += "/"+word
        if ans == "":
            return '/'
        return ans
        