def gcd(max_num, min_num):
    if max_num % min_num == 0:
        return min_num
    else:
        return gcd(min_num, max_num % min_num)

def lcm(num1, num2, gcd):
    return (num1 * num2) // gcd

def solution(arr):
    if len(arr) == 1:
        return arr[0]
    
    while True:
        num1 = arr.pop()
        num2 = arr.pop()
        lcm_res = lcm(num1, num2, gcd(num1, num2))
        if not arr:
            return lcm_res
        else:
            arr.append(lcm_res)