nums = []
num_set = set()
with open('input') as f:
    for l in f:
        nums.append(int(l.strip()))
        num_set.add(int(l.strip()))

for i in range(len(nums)):
    for j in range(i+1, len(nums)):
        x = 2020 - nums[i] - nums[j]
        if x in num_set:
            print(nums[i], nums[j], x, x*nums[i]*nums[j])
            exit()
