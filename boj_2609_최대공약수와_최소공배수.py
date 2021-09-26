def get_gcd(x, y):
    q, r = divmod(x, y)
    if r == 0:
        return y
    return get_gcd(y, r)

x, y = map(int, input().split())
gcd = get_gcd(max(x, y), min(x, y))
lcm = x * y // gcd
print(gcd)
print(lcm)