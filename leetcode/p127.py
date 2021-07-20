class Solution:
    def diff(self, w1, w2):
        return sum([1 for i in range(len(w1)) if w1[i] != w2[i]])
    
    def diff1(self, w1):
        res_set = set()
        for i in range(len(w1)):
            s = w1[:i] + '-' + w1[i+1:]
            if s in self.str_dict:
                res_set = res_set | self.str_dict[s]
                self.str_dict[s].add(w1)
            else:
                self.str_dict[s] = set([w1])
        return res_set
    
    def bfs(self, beginWord, endWord):
        word_set = set()
        word_queue = [beginWord]
        word_set.add(beginWord)
        h = 1
        while word_queue:
            h += 1
            new_queue = []
            for w1 in word_queue:
                for w2 in self.word_dict[w1]:
                    if w2 == endWord:
                        return h
                    if w2 not in word_set:
                        new_queue.append(w2)
                        word_set.add(w2)
            word_queue = new_queue
        return 0

    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList += [beginWord]
        self.word_dict = {}
        self.str_dict = {}
        for i in range(len(wordList)):
            w1 = wordList[i]
            self.word_dict[w1] = set()
            diff_words = self.diff1(w1)
            self.word_dict[w1] = diff_words
            for w2 in diff_words:
                self.word_dict[w2].add(w1)
            #for j in range(i):
            #    w2 = wordList[j]
            #    if self.diff(w1, w2) <2:
            #        self.word_dict[w1].add(w2)
            #        self.word_dict[w2].add(w1)
        return self.bfs(beginWord, endWord)
