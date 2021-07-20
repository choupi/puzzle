class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        kk = 0
        n = 1
        for i in range(len(arr)):
            while n<arr[i]:
                kk +=1
                #print(i, arr[i], n, kk)
                if kk == k:
                    return n
                n += 1
            n += 1
        return n +(k-kk-1)
