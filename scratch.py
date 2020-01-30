from problems.xorlist import Node, XorLinkedList

lst = XorLinkedList()

for index in range(5):
    lst.add(Node(index))


t1 = lst.get(4)
print(lst)