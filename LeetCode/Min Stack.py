class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.__stack = []

    def push(self, val: int) -> None:
        self.__stack.append(val)

    def pop(self) -> None:
        self.__stack.pop()

    def top(self) -> int:
        if self.__stack:
            return self.__stack[-1]

    def getMin(self) -> int:
        return min(self.__stack)

# Discuss에 공유된 코드(훨씬 빠름)
class MinStack:
    def __init__(self):
        self.A = []
        self.M = []
    def push(self, x):
        self.A.append(x)
        M = self.M
        if not M:
            M.append(x)
        else:
            M.append(min(x, M[-1]))
        
    def pop(self):
        self.A.pop()
        self.M.pop()
        
    def top(self):
        return self.A[-1]
    
    def getMin(self):
        return self.M[-1]
