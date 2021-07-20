class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) < 3:
            return False
        if arr[1] < arr[0]:
            return False
        down_flag = False
        for i in range(1, len(arr)):
            if arr[i] == arr[i-1]:
                return False
            if down_flag and arr[i] > arr[i-1]:
                return False
            elif not down_flag and arr[i] < arr[i-1]:
                down_flag = True
        return down_flag
            
