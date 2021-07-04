def solution(array, commands):
    answer = []
    for command in commands:
        new_array = array
        new_array = new_array[command[0]-1:command[1]]
        new_array = sorted(new_array)
        answer.append(new_array[command[2]-1])
    return answer

# array = list(map(int, input().split(",")))
# commands = []
# for _ in range(3):
#     command = list(map(int, input().split(",")))
#     commands.append(command)
# print(solution(array, commands))