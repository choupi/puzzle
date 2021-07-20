class Solution:
    
    def find(self, ch):
        t = self.vd[ch]
        a = []
        while t != self.vd[t]:
            a.append(t)
            t = self.vd[t]
        for tt in a:
            self.vd[tt] = t
        return t
    
    def join(self, a, b):
        ta = self.find(a)
        tb = self.find(b)
        self.vd[ta] = max(ta, tb)
        self.vd[tb] = max(ta, tb)
        
    def add(self, ch):
        if ch not in self.vd:
            self.vd[ch] = ch

    def equationsPossible(self, equations: List[str]) -> bool:
        self.vd = {}
        ineq = []
        for i, eq in enumerate(equations):
            if '!=' in eq:
                ineq.append(i)
                continue
            a, b = eq.split('==', 1)
            self.add(a)
            self.add(b)
            self.join(a, b)
        for i in ineq:
            a, b = equations[i].split('!=', 1)
            self.add(a)
            self.add(b)
            if self.find(a) == self.find(b):
                return False
        return True
