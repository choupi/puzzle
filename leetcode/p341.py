# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.stk = [nestedList]
        self.ind = [0]
    
    def next(self) -> int:
        if not self.hasNext():
            return None
        val = self.stk[-1][self.ind[-1]].getInteger()
        self.ind[-1] += 1
        return val
    
    def hasNext(self) -> bool:
        while self.stk:
            if self.ind[-1] == len(self.stk[-1]):
                self.stk.pop()
                self.ind.pop()
                if self.ind: self.ind[-1] += 1
                continue
            if self.stk[-1][self.ind[-1]].isInteger():
                return True
            v = self.stk[-1][self.ind[-1]].getList()
            self.stk.append(v)
            self.ind.append(0)
        return False

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
