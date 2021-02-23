
def card_string(player1, player2):
    return ','.join([str(p) for p in player1]) + '|||' + ','.join([str(p) for p in player2])

card_dict = {}

def play(player1, player2):
    cs0 = card_string(player1, player2)
    print(cs0)
    if cs0 in card_dict:
        return card_dict[cs0], player1, player2
    card_set = set()
    while len(player1) > 0 and len(player2) > 0:
        c1 = player1.pop(0)
        c2 = player2.pop(0)
        cs = card_string(player1, player2)
        #print(c1, c2, cs)
        if cs in card_set:
            card_dict[cs0] = 1
            return 1, player1, player2
        card_set.add(cs)
        if len(player1) >= c1 and len(player2) >= c2:
            print('sub-game')
            r, _, _ = play(player1[:c1:], player2[:c2:])
            #print(r)
            if r == 1:
                player1 += [c1, c2]
            else:
                player2 += [c2, c1]
            continue
        #print(c1, c2)
        if c1 > c2:
            player1 += [c1, c2]
        else:
            player2 += [c2, c1]
        #print(player1)
        #print(player2)
    if len(player1) > len(player2):
        card_dict[cs0] = 1
        return 1, player1, player2
    else:
        card_dict[cs0] = 2
        return 2, player1, player2

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
r, player1, player2 = play(player1, player2)
print(player1)
print(player2)
if r == 1:
    winner = player1
else:
    winner = player2
total = 0
for i in range(len(winner)):
    total += (len(winner) - i) * winner[i]
print(total)
