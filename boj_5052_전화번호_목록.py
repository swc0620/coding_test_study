t = int(input())

for _ in range(t):
    n = int(input())
    numbers = []
    for _ in range(n):
        numbers.append(input())
    
    numbers.sort()
    print(numbers)
    for i in range(len(numbers)-1):
        trimmed_num = numbers[i+1][:len(numbers[i])]
        if numbers[i] == trimmed_num:
            print("NO")
            break
    else:
        print("YES")