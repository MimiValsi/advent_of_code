f = open("input").read().strip()

digits = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
p1 = 0
p2 = 0
for line in f.split('\n'):
    p1_dig = []
    p2_dig = []
    for i, c in enumerate(line):
        if c.isdigit():
            p1_dig.append(c)
            p2_dig.append(c)
        for j, val in enumerate(digits):
            if line[i:].startswith(val):
                p2_dig.append(str(j+1))

    p1 += int(p1_dig[0] + p1_dig[-1])
    p2 += int(p2_dig[0] + p2_dig[-1])

print(p1)
print(p2)

