class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i = 0
        j = 0
        while i < len(name) and j < len(typed):
            if name[i] != typed[j]:
                return False
            elif (i < len(name)-1 and name[i] != name[i+1]) or i == len(name)-1:
                while j<len(typed) and name[i] == typed[j]:
                    j += 1
                i += 1
            else:
                i += 1
                j += 1
        return i == len(name) and j == len(typed)
