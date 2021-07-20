class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        cur_len = 0
        for i in range(len(S)):
            if str(S[i]).isalpha():
                cur_len += 1
                if cur_len == K: return S[i]
            else:
                if cur_len * int(S[i]) >= K:
                    if K % cur_len == 0:
                        kk = cur_len
                    else:
                        kk = K%cur_len
                    return self.decodeAtIndex(S, kk)
                cur_len *= int(S[i])
