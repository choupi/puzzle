class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        max_total = 1
        i = 0
        j = 1
        char_dict = {tree[0]:1}
        while j<len(tree):
            char_dict[tree[j]] = char_dict.get(tree[j], 0) + 1
            while len(char_dict) > 2:
                char_dict[tree[i]] -= 1
                if char_dict[tree[i]] == 0:
                    del char_dict[tree[i]]
                i += 1
            t = sum([v for k,v in char_dict.items()])
            #print(char_dict)
            if t > max_total:
                max_total = t
            j += 1
        return max_total
