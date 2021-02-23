nums = []
with open('input') as f:
#with open('inp2') as f:
    for l in f:
        n = int(l.strip())
        nums.append(n)
nums = sorted(nums)
df_dict = {1:0, 2:0, 3:1}
jolt = 0
for i in range(len(nums)):
    #print(nums[i], jolt)
    if nums[i] <= jolt+3:
        df = nums[i] - jolt
        df_dict[df] += 1
        jolt = nums[i]
    else:
        print('???')
print(df_dict)
print(df_dict[1] * df_dict[3])
