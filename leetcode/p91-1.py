

class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans_table=[0 for i in range(len(s))]
        for i in range(len(s)):
            idx=len(s)-i-1
            if i==0: 
                if s[idx]!='0': ans_table[idx]=1
            elif i==1:
                if s[idx] == '1': ans_table[idx]+=1
                elif s[idx]== '2' and int(s[idx+1])<7: ans_table[idx]+=1
                if s[idx]!= '0': ans_table[idx]+=ans_table[idx+1]
            else:
                if s[idx] == '1': ans_table[idx]+=ans_table[idx+2]
                elif s[idx]== '2' and int(s[idx+1])<7: 
                    ans_table[idx]+=ans_table[idx+2]
                if s[idx]!= '0': ans_table[idx]+=ans_table[idx+1]
        return ans_table[0]
