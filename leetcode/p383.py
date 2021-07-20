class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransom_cnt = Counter(ransomNote)
        magazine_cnt = Counter(magazine)
        for c in ransom_cnt:
            if ransom_cnt[c] > magazine_cnt[c]:
                return False
        return True
