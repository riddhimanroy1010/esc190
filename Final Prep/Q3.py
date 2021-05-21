class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        '''
        node.insert(5) is the same as BST.insert(node, 5)
        We use this when recursively calling, e.g. self.left.insert
        '''
        if value < self.value:
            if self.left == None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right == None:
                self.right = BST(value)
            else:
                self.right.insert(value)

    def __repr__(self):
        '''The string representation of a node.
        Here, we convert the value of the node to a string and make that
        the representation.
        We can now use
        a = BST(4)
        print(a) # prints 4
        '''
        return str(self.value)

def third_largest(node):
    c = []

    c = third_largest_actual(node, c)

    c = sorted(c, reverse=True)
    return c[2]


def third_largest_actual(node, visited):

    visited.append(node.value)

    if node.left:
        third_largest_actual(node.left, visited)
    if node.right:
        third_largest_actual(node.right, visited)

    return visited

'''recursive implementation runs in O(n) time, while sorting is assumed O(logn). Since n dominates, overall runtime is O(n)'''
