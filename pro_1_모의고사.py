def solution(answers):
    answer = []
    count1 = 0
    count2 = 0
    count3 = 0
    for i in range(len(answers)):
        if i % 5 == 0 and answers[i] == 1:
            count1 += 1
        elif i % 5 == 1 and answers[i] == 2:
            count1 += 1
        elif i % 5 == 2 and answers[i] == 3:
            count1 += 1
        elif i % 5 == 3 and answers[i] == 4:
            count1 += 1
        elif i % 5 == 4 and answers[i] == 5:
            count1 += 1
        
        if i % 2 == 0 and answers[i] == 2:
            count2 += 1
        else:
            if i % 8 == 1 and answers[i] == 1:
                count2 += 1
            elif i % 8 == 3 and answers[i] == 3:
                count2 += 1
            elif i % 8 == 5 and answers[i] == 4:
                count2 += 1
            elif i % 8 == 7 and answers[i] == 5:
                count2 += 1
                
        if (i % 10 == 0 or i % 10 == 1) and answers[i] == 3:
            count3 += 1
        elif (i % 10 == 2 or i % 10 == 3) and answers[i] == 1:
            count3 += 1
        elif (i % 10 == 4 or i % 10 == 5) and answers[i] == 2:
            count3 += 1
        elif (i % 10 == 6 or i % 10 == 7) and answers[i] == 4:
            count3 += 1
        elif (i % 10 == 8 or i % 10 == 9) and answers[i] == 5:
            count3 += 1
    count = [count1, count2, count3]
    max_count = max(count)
    for i in range(3):
        if count[i] == max_count:
            answer.append(i+1)
    return answer