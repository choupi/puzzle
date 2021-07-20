class Solution:
    def count(self, L):
        L_dict = {}
        for x in L:
            L_dict[x] = L_dict.get(x, 0)+1
        return L_dict

    def check(self, a, num_dict):
        for i, v in self.count(a).items():
            if v > num_dict[i]:
                return False
        return True

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        num_dict = self.count(nums)
        sum_dict = {}
        result = set()
        result_list = []
        for n1 in num_dict:
            for n2 in num_dict:
                if n1 == n2 and num_dict[n1]<2:
                    continue
                if n1 < n2:
                    continue
                t = n1 + n2
                if t not in sum_dict:
                    sum_dict[t] = set()
                sum_dict[t].add((n1, n2))
        for s in sum_dict:
            t = target - s
            if t not in sum_dict:
                continue
            for a1 in sum_dict[s]:
                for a2 in sum_dict[t]:
                    a = tuple(sorted(list(a1) + list(a2)))
                    result.add(a)
        for r in result:
            if self.check(r, num_dict):
                result_list.append(r)
        return result_list
