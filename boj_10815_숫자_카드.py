def binary_search(cards, low, high, target):
    if low <= high:
        mid = (low + high) // 2
        if cards[mid] == target:
            return 1
        elif cards[mid] > target:
            return binary_search(cards, low, mid-1, target)
        else:
            return binary_search(cards, mid+1, high, target)
    else:
        return 0

N = int(input())
cards = list(map(int, input().split()))

M = int(input())
candidates = list(map(int, input().split()))

cards.sort()

res = []

for candi in candidates:
    res.append(str(binary_search(cards, 0, len(cards)-1, candi)))

print(" ".join(res))
