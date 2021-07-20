class Solution:
    def find(self, num, p0, p1, first=False):
        if len(num)==0:
            return not first
        for i in range(len(num)):
            if num[0] == '0' and i > 0:
                return False
            x = int(num[:i+1])
            if x > p0 + p1:
                return False
            if x == p0 + p1:
                if self.find(num[i+1:], p1, x):
                    return True
        return False
    
    def init(self, num):
        for i in range(len(num)):
            if num[0] == '0' and i>0:
                return False
            for j in range(i+1, len(num)):
                if num[i+1] == '0' and j-i>1:
                    break
                #print(i, j)
                #print(num[:i+1], num[i+1:j+1])
                if self.find(num[j+1:], int(num[:i+1]), int(num[i+1:j+1]), True):
                    return True
        return False
    
    def isAdditiveNumber(self, num: str) -> bool:
        return self.init(num)
