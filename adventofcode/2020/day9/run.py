nums = []
num_dict = {}
with open('input') as f:
    for l in f:
        n = int(l.strip())
        nums.append(n)
for n in nums[:25]:
    num_dict[n] = num_dict.get(n, 0) + 1
for i in range(25, len(nums)):
    n = nums[i]
    valid = False
    for v in num_dict:
        if n - v in num_dict and v!=n-v:
            valid = True
            break
    if not valid:
        print(i, nums[i], num_dict)
        break
    num_dict[nums[i-25]] -= 1
    if num_dict[nums[i-25]] == 0:
        del num_dict[nums[i-25]]
    num_dict[n] = num_dict.get(n, 0) + 1
