class Solution:
    def frequencySort(self, s: str) -> str:
        char_dict = {}
        for c in s:
            char_dict[c] = char_dict.get(c, 0) + 1
        return ''.join([k*v for k, v in sorted(char_dict.items(), key=lambda x: x[1], reverse=True)])
