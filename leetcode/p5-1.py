class Solution:
    def check(self, s, i, j):
        h1 = (i+j+1)//2
        h2 = (i+j)//2
        #print(i, h1, h2, j)
        #print(s[i:h1], s[h2:j][::-1])
        return s[i:h1] == s[h2:j][::-1]

    def longestPalindrome(self, s: str) -> str:
        for l in range(len(s), 0, -1):
            #print(l)
            for k in range(len(s)-l+1):
                #print(l, k, k+l)
                if self.check(s, k, k+l):
                    return s[k:k+l]
        return ""
        
