N = int(input())

members = []

for i in range(N):
    age, name = input().split()
    members.append((int(age), name, i))

members = list(set(members))

members.sort(key=lambda member: (member[0], member[2]))

for member in members:
    print(member[0], member[1])