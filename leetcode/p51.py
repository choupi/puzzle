# 51. N-Queens
# https://leetcode.com/problems/n-queens/

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        nq_list = self.nq(n)
        return self.gen(n, nq_list)

    def nq(self, n):
        nq_list = []
        for ns in itertools.permutations(range(n)):
            if self.check_queen(ns):
                nq_list.append(ns)
        #print(len(nq_list))
        return nq_list

    def check_queen(self, ns):
        n = len(ns)
        for i, q in enumerate(ns):
            for ii in range(n - i -1):
                if q == (ns[i+ii+1] + ii + 1) or q == (ns[i+ii+1] - ii -1):
                    return False
        return True

    def gen(self, n, nq_list):
        full_nq_list = []
        for ns in nq_list:
            s = []
            for v in ns:
                a = ['.'] * n
                a[v] = 'Q'
                s.append(''.join(a))
            full_nq_list.append(s)
        return full_nq_list

