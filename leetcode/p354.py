class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        if len(envelopes) == 0:
            return 0
        #self.envelopes_sorted = sorted(sorted(envelopes, key=itemgetter(1), reverse=True), key=itemgetter(0))
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        table = []
        table.append(envelopes[0][1])
        for d in envelopes:
            if d[1] > table[-1]:
                table.append(d[1])
            else:
                di = bisect.bisect_left(table, d[1])
                table[di] = d[1]
        return len(table)
