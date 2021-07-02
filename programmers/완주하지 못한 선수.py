def solution(participant, completion):
    par_dic = dict(zip([i for i in range(len(participant))], sorted(participant)))
    com_dic = dict(zip([i for i in range(len(completion))], sorted(completion)))
    for i in range(len(completion)):
        if par_dic[i] != com_dic[i]:
            return par_dic[i]

    return par_dic[i+1]
