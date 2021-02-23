nums = []
with open('input') as f:
#with open('inp1') as f:
#with open('inp2') as f:
    for l in f:
        n = int(l.strip())
        nums.append(n)
max_n = max(nums)
nums = sorted(nums)
table = []
for i in range(len(nums)):
    #print(nums[i], jolt)
    cnt = 0
    if nums[i] <= 3:
        cnt = 1
    for j in range(max(0,i-3), i):
        #print(j, i)
        #print(nums[j], nums[i])
        if nums[i] <= nums[j]+3:
            cnt += table[j]
    table.append(cnt)
print(len(table))
print(table)
print(table[-1])
