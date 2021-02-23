
player1 = []
player2 = []

#with open('inp') as f:
with open('input') as f:
    while True:
        l = f.readline()
        if l.strip() == 'Player 1:':
            continue
        if l.strip() == '':
            break
        player1.append(int(l.strip()))
    while True:
        l = f.readline()
        if l.strip() == 'Player 2:':
            continue
        if l.strip() == '':
            break
        player2.append(int(l.strip()))
print(player1)
print(player2)

while len(player1) > 0 and len(player2) > 0:
    c1 = player1.pop(0)
    c2 = player2.pop(0)
    #print(c1, c2)
    if c1 > c2:
        player1 += [c1, c2]
    else:
        player2 += [c2, c1]
    #print(player1)
    #print(player2)
print(player1)
print(player2)
if len(player1) > len(player2):
    winner = player1
else:
    winner = player2
total = 0
for i in range(len(winner)):
    total += (len(winner) - i) * winner[i]
print(total)
