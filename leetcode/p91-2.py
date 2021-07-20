class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0
        table = [0] * (len(s)+1)
        table[0]=1
        for i in range(len(s)):
            x = int(s[i])
            if x>0:
                table[i+1]+=table[i]
            if i>0 and int(s[i-1:i+1])>9 and int(s[i-1:i+1])<27:
                table[i+1]+=table[i-1]
        #print(table)
        return table[-1]
