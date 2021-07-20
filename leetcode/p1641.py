class Solution:
    def countVowelStrings(self, n: int) -> int:
        vowels = ['a', 'e', 'i', 'o', 'u']
        counts = []
        counts.append({'a':0, 'e':0, 'i':0, 'o':0, 'u':0})
        counts.append({'a':1, 'e':1, 'i':1, 'o':1, 'u':1})
        for i in range(2, n+1):
            vd = {}
            for v in vowels:
                vd[v] = sum([c for k, c in counts[i-1].items() if k >= v])
            counts.append(vd)
        #print(counts)
        return sum(counts[n].values())
        
