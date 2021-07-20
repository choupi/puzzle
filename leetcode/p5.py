class Solution:
    def longestPalindrome(self, s: str) -> str:
        table = [[False] * len(s) for _ in range(len(s))]
        max_len = 1
        ans = s[0]
        for i in range(len(s)):
            table[i][i] = True

        for j in range(1, len(s)):
            for i in range(j):
                #print(i, j)
                if s[i] == s[j]:
                    if j-i<2 or table[i+1][j-1]:
                        table[i][j] = True
                        if j - i + 1 > max_len:
                            max_len = j - i + 1
                            ans = s[i:j+1]
        #print(max_len)
        return ans
        
