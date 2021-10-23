alphabet = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
line = input()
for alpha in alphabet:
    line = line.replace(alpha, '*')

print(len(line))