# !/usr/bin/env python3
# Author: C.K
# Email: theck17@163.com
# DateTime:2021-12-14 21:08:42
# Description:
class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.dq = collections.deque()
        self.valueMap = {}

    def get(self, key: int) -> int:
        if key not in self.valueMap:
            return -1
        self.dq.remove(key)
        self.dq.append(key)

        return self.valueMap[key]

    def put(self, key: int, value: int) -> None:
        if key not in self.valueMap:
            if len(self.dq) == self.cap:
                del self.valueMap[self.dq.popleft()]
        else:
            self.dq.remove(key)

        self.dq.append(key)
        self.valueMap[key] = value


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

if __name__ == "__main__":
    pass
