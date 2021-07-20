class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        if num>8:
            return []
        res = []
        for bs in itertools.combinations(range(10), num):
            #b = '{0:010b}'.format(i)
            #if b.count('1') == num:
            b = ['0']*10
            for i in bs:
                b[i] = '1'
            hh = int(''.join(b[:4]), 2)
            if hh > 11:
                continue
            mm = int(''.join(b[4:]), 2)
            if mm > 59:
                continue
            t = '%d:%02d'%(hh, mm)
            res.append(t)
        #return sorted(res)
        return res
