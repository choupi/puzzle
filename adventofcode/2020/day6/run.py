total = 0
questions = set()
with open('input') as f:
    for l in f:
        if l.strip() == '':
            total += len(questions)
            questions = set()
            continue
        for c in l.strip():
            questions.add(c)
total += len(questions)
print(total)
