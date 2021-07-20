class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        ok = True
        for i in range(len(flowerbed)):
            if flowerbed[i] == 0:
                if ok and (i==len(flowerbed)-1 or flowerbed[i+1]==0):
                    n-=1
                    ok = False
                else:
                    ok = True
            else:
                ok = False
        if n > 0:
            return False
        return True
