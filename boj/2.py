import sys
n = int(sys.stdin.readline().rstrip())

def solution(ps):

  dic = {')': '('}
  stack = []
  for char in ps:
    if char in dic:
      top_element = stack.pop() if stack else '#' # stack이 비어있으면 에러가 발생하기 때문에 더미 문자인 '#' 추가

      if dic[char] != top_element:
        return 'NO'

    else:
      stack.append(char)

  if not stack: # stack에 원소가 남아 있지 않은 경우
    return 'YES'
  else:
    return 'NO'

for _ in range(n):
  ps = sys.stdin.readline().rstrip()
  print(solution(ps))