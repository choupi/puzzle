class Solution:
    def count(self, L):
        L_dict = {}
        for x in L:
            L_dict[x] = L_dict.get(x, 0) + 1
        return L_dict
    
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        if not A or not B or not C or not D:
            return 0
        A_dict = self.count(A)
        B_dict = self.count(B)
        C_dict = self.count(C)
        D_dict = self.count(D)
        self.AB_dict = {}
        for a in A_dict:
            for b in B_dict:
                t = a + b
                self.AB_dict[t] = self.AB_dict.get(t, 0) + A_dict[a]*B_dict[b]
        cnt = 0
        for c in C_dict:
            for d in D_dict:
                t = -1 * (c + d)
                if t in self.AB_dict:
                    cnt += C_dict[c]*D_dict[d]*self.AB_dict[t]
        return cnt
