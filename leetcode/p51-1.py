
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.nq_list = []
        self.nq(n, 0, [], set(range(n)))
        return self.gen(n)

    def nq(self, n, i, ns, num_set):
        if n == i:
            self.nq_list.append(ns)
            return
        for num in num_set:
            tmp_ns = ns + [num]
            if self.check_queen(tmp_ns):
                tmp_num_set = num_set.copy()
                tmp_num_set.remove(num)
                self.nq(n, i+1, tmp_ns, tmp_num_set)

    def check_queen(self, ns):
        n = len(ns)
        q = ns[n-1]
        #print(n, q, ns)
        for ii in range(n - 2, -1, -1):
            #print(q, ii, ns[ii], ns[ii] + (n - ii))
            if q == (ns[ii] + (n - ii -1)) or q == (ns[ii] - (n - ii -1)):
                return False
        return True

    def gen(self, n):
        full_nq_list = []
        for ns in self.nq_list:
            s = []
            for v in ns:
                a = ['.'] * n
                a[v] = 'Q'
                s.append(''.join(a))
            full_nq_list.append(s)
        return full_nq_list
