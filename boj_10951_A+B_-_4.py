while True:
    try:
        line = input()
        A, B = map(int, line.split())
        print(A+B)
    except:
        break