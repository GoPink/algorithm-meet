def find(n, m, x, y, r, c):
    if r < x or r > x + 2 ** n - 1:
        return 0
    if c < y or c > y + 2 ** n - 1:
        return 0
    if r == x and c == y:
        return m
    if n < 0:
        return 0
    return find(n - 1, m, x, y, r, c)\
        + find(n - 1, m + 2 ** ((n - 1) * 2), x, y + 2 ** (n - 1), r, c)\
        + find(n - 1, m + (2 ** ((n - 1) * 2)) * 2, x + 2 ** (n - 1), y, r, c)\
        + find(n - 1, m + (2 ** ((n - 1) * 2)) * 3, x + 2 ** (n - 1), y + 2 ** (n - 1), r, c)


n, r, c = map(int, input().split())
print(find(n, 0, 0, 0, r, c))
