import sys
input = sys.stdin.readline

ipv6 = input().rstrip().split(":")

if len(ipv6) == 8:
    for idx in range(8):
        ipv6[idx] = ipv6[idx].rjust(4, '0')
elif len(ipv6) < 8:
    idx = ipv6.index("")
    while len(ipv6) < 8:
        ipv6.insert(idx, "")
    for idx in range(8):
        ipv6[idx] = ipv6[idx].rjust(4, '0')
else:
    if ipv6[0] == "":
        ipv6 = ipv6[1:]
    elif ipv6[-1] == "":
        ipv6.pop()
    for idx in range(8):
        ipv6[idx] = ipv6[idx].rjust(4, '0')
print(":".join(ipv6))
