class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        rows = [set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')]
        res = []
        for w in words:
            ws = set(w.lower())
            for r in rows:
                if len(ws&r) == len(ws):
                    res.append(w)
                    break
        return res
