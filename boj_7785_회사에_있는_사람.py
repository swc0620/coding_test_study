import sys
input = sys.stdin.readline

n = int(input())
people = []
for _ in range(n):
    person, do = input().split()
    if do == "enter":
        people.append(person)
    else:
        people.remove(person)

people.sort(reverse=True)
for person in people:
    print(person)