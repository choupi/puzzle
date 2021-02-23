def convert(s):
    row = 0
    for i in range(7):
        row = row << 1
        if s[i] == 'B':
            row += 1
    col = 0
    for i in range(3):
        col = col << 1
        if s[7+i] == 'R':
            col += 1
    sid = row*8 + col
    #print(row, col, sid)
    return sid

#convert('FBFBBFFRLR')
#convert('BFFFBBFRRR')
#convert('FFFBBBFRRR')
#convert('BBFFBBFRLL')
max_sid = -1
with open('input') as f:
    for l in f:
        sid = convert(l.strip())
        if sid > max_sid:
            max_sid = sid
print(max_sid)
