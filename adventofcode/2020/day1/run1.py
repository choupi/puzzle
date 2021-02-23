nums = []
with open('input') as f:
    for l in f:
        nums.append(int(l.strip()))
nums = sorted(nums)

i = 0
j = len(nums) - 1
while i < j:
    #print(i, j)
    if nums[i] + nums[j] == 2020:
        print(nums[i], nums[j], nums[i]*nums[j])
        break
    elif nums[i] + nums[j] < 2020:
        i += 1
    else:
        j -= 1
