n = int(input())
d = []
while n > 0:
    n -= 1
    s = input()
    
    duplicated = False
    for words in d:
        if s in words:
            duplicated = True
            break
    
    if duplicated == False:
        d.append(set())
        for i in range(len(s)):
            d[-1].add(s)
            s = s[1:] + s[0]
print(len(d))
