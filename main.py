class Node:
    def __init__(self, name):
        self.name = name
        self.left = None
        self.right = None

    def __repr__(self):
        return self.name


class LinkedList:

    def __init__(self):
        self.head = Node('head')
        self.tail = Node('tail')
        self.head.right = self.tail
        self.tail.left = self.head

    def push_back(self, node):
        node.right = self.tail
        node.left = self.tail.left
        self.tail.left.right = node
        self.tail.left = node

    def delete(self, name):
        name.left.right = name.right
        name.right.left = name.left


d = dict()
l = LinkedList()

while True:
    s = input()
    if s == '0':
        elem = l.tail.left
        while elem != l.head:
            print(elem.name)
            elem = elem.left
        continue

    if s not in d:
        elem = Node(s)
        l.push_back(elem)
        d[s] = elem
    else:
        elem = d[s]
        l.delete(elem)
        l.push_back(elem)
