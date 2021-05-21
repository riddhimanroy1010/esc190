/*
Queues
Enqueue: append to end
Dequeue: remove and return from start
FIFO

Implementation
linked list:
enqueue/dequeue both O(1) -> store head, tail

circular array:
store first index, number of items
[4,0,0,1,2,3] -> front = 3, max_size = 6, nitems = 4
index = (front + nitems) % max_size


Heaps and Priority Queues
-> first elem dequeued is one with highest priority
ex: simulate real-world systems organized by priority, A* search

insert(S, x): add elem with priority x to queue S
min(S): return elem with smallest value
extract_min(S): remove smallest elem

Implementation

array/linked list:
O(1) insert, O(n) min/extract_min

sorted array/linked list
O(n) insert, O(1) min/extract_min

heaps:
a tree
each node has children
first node is root, end nodes are leaves

        root
        /   \
    leaf    node
            /  \
         leaf  leaf

store as array: [_,root, leaf, node, leaf, leaf, ??, ??] left->right top->bottom
parent(i) = i/2 (integer division)
left(i) = 2*i
right(i) = 2*i + 1

heap order property: for each node -n- other than root, value stored in parent must be <= value stored in n --> mini
mum in root


insert: place value in leftmost empty space at bottom level -> might break order
-> percolate value up tree until in correct spot:

          1
        /   \
       2     5
            /  \
           7    9
               / \
              12  [3]
          1
        /   \
       2     5
            /  \
           7   [3]
               / \
              12  9
          1
        /   \
       2    [3]
            /  \
           7    5
               / \
              12  9
algorithm: insert(x)
n = size of heap
pq = array sorting heap
k = n +1
pq[k] = x
while(k>1 and pq[k/2] > pq[k])
    swap(pq[k], pq[k/2])
    k = k/2

extract: removes/returns the minimim, replace with end of array (extreme right)
         [10]
        /   \
       2     5
            /  \
           7    9
               / \
              12  14
          2
        /   \
      [10]   5
            /  \
           7    9
               / \
              12  14

algorithm: extract_min
(just look at the slides its too long)
basically:
store min
swap(min, last element)
percolate down


complexity:
height (h) = longest path from node to leaf ~log_2(n)
insert/extract O(h) = O(logn) 

*/