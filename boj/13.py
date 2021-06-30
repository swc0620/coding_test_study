import sys

N = int(sys.stdin.readline())
cardList = sorted(map(int,sys.stdin.readline().split()))

M = int(sys.stdin.readline())
checkList = list(map(int,sys.stdin.readline().split()))

dictList = dict()

for i in cardList:
    try:
        dictList[i] += 1
    except:
        dictList[i] = 1 # 없으면 1로

resultList = []
for i in checkList:
    try:
        resultList.append(dictList[i])
    except:
        resultList.append(0)

for num in resultList:
    print(num,end=" ")