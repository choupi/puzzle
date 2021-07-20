class Solution:
    def BFS(self, q):
        new_q = []
        while q:
            i = q.pop(0)
            for j in self.num_dict.get(self.arr[i], []):
                if j not in self.index_set:
                    self.index_set.add(j)
                    new_q.append(j)
            if self.arr[i] in self.num_dict:
                del self.num_dict[self.arr[i]]
            if i > 0 and (i - 1) not in self.index_set:
                self.index_set.add(i-1)
                new_q.append(i-1)
            if i < self.target and (i + 1) not in self.index_set:
                self.index_set.add(i+1)
                new_q.append(i+1)
        return new_q

    def minJumps(self, arr: List[int]) -> int:
        self.arr = arr
        self.num_dict = {}
        self.target = len(arr) - 1
        for i, n in enumerate(arr):
            #print(i, n)
            if n not in self.num_dict:
                self.num_dict[n] = []
            self.num_dict[n].append(i)
        #print(self.num_dict)
        self.index_set = set()
        num_queue = [0]
        self.index_set.add(0)
        hop = 0
        done = False
        while self.target not in num_queue:
            num_queue = self.BFS(num_queue)
            hop += 1
        return hop
