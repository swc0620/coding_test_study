def replace_notes(m):
    return m.replace('C#', 'c').replace('D#', 'd').replace('F#', 'f').replace('G#', 'g').replace('A#', 'a')

def solution(m, musicinfos):
    answer = '(None)'
    ans_playtime = 0

    m = replace_notes(m)
    for musicinfo in musicinfos:
        start_time, end_time, music_name, scales = musicinfo.split(",")
        start_hour, start_min = map(int, start_time.split(":"))
        end_hour, end_min = map(int, end_time.split(":"))
        playtime = (end_hour * 60 + end_min) - (start_hour * 60 + start_min)
        
        scales = replace_notes(scales)
        q, r = divmod(playtime, len(scales))
        played_scales = scales * q + scales[:r]

        if m in played_scales and len(played_scales) > ans_playtime:
            answer = music_name
            ans_playtime = len(played_scales)
    
    return answer

# m = input()
# musicinfos = input().split()
# print(solution(m, musicinfos))