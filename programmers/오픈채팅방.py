def solution(record):
    answer = []

    uid_dict = dict()

    for info in record:
        log = info.split(" ")

        command = log[0]
        uid = log[1]

        if command != "Leave":
            nickname = log[2]
            uid_dict[uid] = nickname

    for info in record:
        log = info.split(" ")

        command = log[0]
        uid = log[1]

        if command == "Enter":
            answer.append(uid_dict[uid] + "님이 들어왔습니다.")
        elif command == "Leave":
            answer.append(uid_dict[uid] + "님이 나갔습니다.")

    return answer
