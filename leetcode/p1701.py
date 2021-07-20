class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        schedule = 0
        total_wait = 0
        for a, t in customers:
            schedule = max(a, schedule) + t
            total_wait += schedule - a
        return total_wait / len(customers)
