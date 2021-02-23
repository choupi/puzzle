total = 0
questions = {}
cnt = 0
with open('input') as f:
    for l in f:
        if l.strip() == '':
            total += sum([1 if v==cnt else 0 for v in questions.values()])
            questions = {}
            cnt = 0
            continue
        for c in l.strip():
            questions[c] = questions.get(c, 0) + 1
        cnt += 1
total += sum([1 if v==cnt else 0 for v in questions.values()])
print(total)
