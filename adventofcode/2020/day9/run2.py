# 257342611
nums = []
with open('input') as f:
    for l in f:
        n = int(l.strip())
        nums.append(n)
i = 0
j = 1
s = nums[i] + nums[j]
target = 257342611
while i<len(nums) and j<len(nums):
    if s < target:
        j += 1
        s += nums[j]
    elif s > target:
        s -= nums[i]
        i += 1
    elif s == target:
        print(i, j)
        max_n = max(nums[i:j+1])
        min_n = min(nums[i:j+1])
        print(min_n, max_n)
        print(min_n+max_n)
        break
