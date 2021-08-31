def solution(participant, completion):
    player_list = {}
    for index, player in enumerate(participant):
        if player in player_list.keys():
            player_list[player] += 1
        else:
            player_list[player] = 1

    for index, player in enumerate(completion):
        player_list[player] -= 1
        if player_list[player] == 0:
            del player_list[player]
    answer = [*player_list][0]
    return answer

# participant = input().split(",")
# completion = input().split(",")
# print(solution(participant, completion))