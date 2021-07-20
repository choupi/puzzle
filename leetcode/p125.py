class Solution:
    def isPalindrome(self, s: str) -> bool:
        ss = [c.lower() for c in s if c.isalnum()]
        for i in range(len(ss)//2):
            if ss[i] != ss[len(ss)-i-1]:
                return False
        return True
