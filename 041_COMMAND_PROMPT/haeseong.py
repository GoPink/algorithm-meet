n = int(input())
d = []
for i in range(50):
    d.append({})

for i in range(n):
    s = input()
    for j in range(len(s)):
        if s[j] in d[j]:
            d[j][s[j]] += 1
        else:
            d[j].update({s[j]: 1})

buf = ''
for i in range(50):
    if len(d[i]) == 0:
        break
    elif len(d[i]) == 1:
        buf += list(d[i].keys())[0]
    else:
        buf += '?'

print(''.join(buf))
