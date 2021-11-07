'''Generic Node Class.'''
class Node:

    def __init__(self, data, next = None):
        self.data = data
        self.next = next

    def __str__(self):
        return "{}".format(self.data) 

    def __eq__(self, other):
        if isinstance(other, Node):
            return self.data == other.data
        
        return False

    def __ne__(self, other):
        result = self.__eq__(other)

        if result is NotImplemented:
            return result
        
        return not result

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_data(self, data):
        self.data = data

    def set_next(self, node):
        self.next = node

''' equality is by reference. '''
class RefNode():

    def __init__(self, data, next=None):
        self.data = data
        self.next = next

def build_ref_list(values):
    head, prev = None, None

    for val in values:
        node = RefNode(val)

        if head == None:            
            head, prev = node, node
        else:
            prev.next = node
            prev = node

    return head