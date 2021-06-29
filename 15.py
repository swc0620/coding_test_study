import sys


class Heap:
    def __init__(self, max_size):
        self.size = 0
        self.data = [0 for i in range(0, max_size)]

    def push(self, item):
        self.size += 1
        self.data[self.size] = item;
        self.swap();

    def swap(self):
        index = self.size
        while index != 1:
            parentItem = self.data[int(index / 2)]
            currentItem = self.data[index]
            if parentItem < currentItem:
                tmp = currentItem
                self.data[index] = parentItem
                self.data[int(index / 2)] = tmp
                index = int(index / 2)
            else:
                break
        
    def delete(self):
        if self.size == 0:
            print(0);
            return

        print(self.data[1]);
        self.data[1] = self.data[self.size]
        self.data[self.size] = 0
        self.size -= 1
        parent = 1
        child = 2
        while child <= self.size:
            if (child + 1 <= self.size) and (self.data[child + 1] > self.data[child]):
                child = child + 1
            if self.data[child] > self.data[parent]:
                tmp = self.data[child]
                self.data[child] = self.data[parent]
                self.data[parent] = tmp
                parent = child
                child = parent * 2
            else:
                break

N = int(input())
heap = Heap(N);
for i in range(0, N):
    num = int(sys.stdin.readline())
    if num == 0:
        heap.delete()
    else:
        heap.push(num)