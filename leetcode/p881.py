class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        #print(people)
        cnt = 0
        i = 0
        j = len(people) - 1
        while i<=j:
            cnt += 1
            if i == j:
                break
            elif people[i] + people[j] > limit:
                j -= 1
            else:
                i += 1
                j -= 1
        return cnt
