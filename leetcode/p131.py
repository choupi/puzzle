class Solution:
    def check_palindrome(self, s):
        #print(s[::] == s[::-1], s[::], s[::-1])
        return s[::] == s[::-1]
    
    def part(self, s, part_list):
        #print(s+"@@")
        if not s:
            self.result.append(part_list)
            return
        for i in range(1, len(s)+1):
            if self.check_palindrome(s[:i]):
                self.part(s[i:], part_list+[s[:i]])

    def partition(self, s: str) -> List[List[str]]:
        self.result = []
        self.part(s, [])
        return self.result
