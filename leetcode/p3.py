class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_set = set()
        max_len = 0
        i = 0
        j = 0
        while j<len(s):
            #print(i, j, s[j])
            if s[j] not in char_set:
                char_set.add(s[j])
                if max_len < len(char_set):
                    max_len = len(char_set)
            else:
                while s[i] != s[j]:
                    char_set.remove(s[i])
                    i += 1
                i += 1
            j += 1
        return max_len
