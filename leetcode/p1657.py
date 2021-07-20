class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False
        ns1 = [cnt[1] for cnt in Counter(word1).most_common()]
        ns2 = [cnt[1] for cnt in Counter(word2).most_common()]
        set1 = set([c for c in word1])
        set2 = set([c for c in word2])
        return set1==set2 and ns1==ns2
        if len(ns1) != len(ns2):
            return False
        for i in range(len(ns1)):
            if ns1[i][1] != ns2[i][1]:
                return False
        return True
        
