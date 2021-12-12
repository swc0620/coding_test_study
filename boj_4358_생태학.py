import sys
input = sys.stdin.readline

tree_dict = {}
trees = set()
cnt = 0
while True:
    tree = input().rstrip()
    if not tree:
        break
    if tree in tree_dict:
        tree_dict[tree] += 1
    else:
        tree_dict[tree] = 1
    cnt += 1
    trees.add(tree)

trees = sorted(list(trees))

for tree in trees:
    print(f'{tree} {(tree_dict[tree]*100 / cnt):.4f}')