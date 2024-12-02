from collections import Counter

def day01(filename):
    l1, l2 = list(), list()
    with open(filename, "r") as f:
        for l in f:
            a, b = map(int, l.split())
            l1.append(a)
            l2.append(b)
    diff = sum(abs(x - y) for x, y in zip(sorted(l1), sorted(l2)))
    ctr = Counter(l2)
    similarity = sum(x * ctr[x] for x in l1)
    return diff, similarity


print(day01("./input.txt"))
