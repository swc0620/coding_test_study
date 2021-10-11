import sys

given_number = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]
zero_pos = [(i, j) for i in range(9) for j in range(9) if given_number[i][j] == 0]
blocks_to_check = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)]
mid_of_sq = [1, 1, 1, 4, 4, 4, 7, 7, 7]
solved = False

def available_left_nums(i, j):
    nums = list(range(1,10))
    for k in range(9):
        if given_number[k][j] in nums:
            nums.remove(given_number[k][j])
        if given_number[i][k] in nums:
            nums.remove(given_number[i][k])
    for surrounding_block in blocks_to_check:
        dx = mid_of_sq[i] + surrounding_block[0]
        dy = mid_of_sq[j] + surrounding_block[1]
        if given_number[dx][dy] in nums:
            nums.remove(given_number[dx][dy])
    return nums

def dfs(num_of_zeros_filled):
    global solved
    if solved == True:
        return
    if num_of_zeros_filled == len(zero_pos):
        for block in given_number:
            print(*block)
        solved = True
        return
    else:
        (i, j) = zero_pos[num_of_zeros_filled]
        for num in available_left_nums(i, j):
            given_number[i][j] = num
            dfs(num_of_zeros_filled+1)
            given_number[i][j] = 0

dfs(0)