def solution(clothes):
    answer = 1
    wardrobe = {}
    for cloth in clothes:
        name, style = cloth
        if style in wardrobe.keys():
            wardrobe[style].add(name)
        else:
            wardrobe[style] = {name}
                
    for key, value in wardrobe.items():
        answer *= (len(value) + 1)
    return answer - 1