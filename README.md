Github: amazingDeveloper976

# Learning-DSA-


Nothin' just understandin' DSA!

Day 1: 

learned basics like time complexity 

________________________________________________

Day 2: 

Big Oh : represents upper bound.Mathematically, 0<=f(n)<=c.g(n)

Big omega : represents lower bound. Mathematically, 0<=c.g(n)<=f(n)

Big theta : combination of Big oh and Big omega.
Mathematically, 0<=c1.g(n)<=f(n)<=c2.g(n)
(c1 of Big omega, c2 for Big oh) multiplier

where, f(n)= no of steps the program takes for 'n' size input
g(n)=is the rate of growth of runtime as n increases

................................................

DATA STRUCTURES AND ARCHITECTURE:

Abstract Data Types(ADTs): ADT is a data type which defines WHAT operations are performed but hides HOW they are performed.

Array as ADT: 1. Array allocates a contiguous memory block after its declaration, this is abstract.

2.It tracks total memory allocated and total memory used


-----------------------------------------------
Day 3:


added files: main.cpp and searchTree.cpp

understood how to implement array as ADT.

understood about array traversal,insertion,deletion as well as shifting of its elements.

understood about searchTree and even prcticed!

_________________________________________________


DAY 4:

added file: linkListTraversal.cpp

understood that linked list holds a pointer to next element and insertion and deletion is easier in this then array.

Drawback: Reading data is time consuming and it have Big O(n) whereas array had Big O(1). (guess we should must sacrifice read speed for easier insertion and deletion)

understood how to make a linked list and practiced with file mentioned above.

___________________________________________________

DAY 5:

Added files: LinkedListInsertion.cpp

understood the logic for insertion at different places.

Wrote a program for insertion of node at different places at "LinkedListInsertion.cpp".

____________________________________________________


DAY 6:

Added file:LinkedListDeletion.cpp

understood the logic for deletion at different places.

Wrote a program for deletion of node at different places at "LinkedListDeletion.cpp".

_______________________________________________

DAY 7:

Added files: circularLinkedList.cpp,doublyLinkedList.cpp

Understood about circular and doubly linked list

wrote a practice program for both of them.


______________________________________________________

DAY 8:

Added files: NULL

Added some more functions in doubly li ked list.

Currently understanding Stack.

____________________________________________________

DAY 9:(Its been a little late because i'm stuck at a problem in leetcode)

Added file: stackUsingArray.cpp

Implemented stack using array and did some basic operation there.

 ____________________________________________________

DAY10&&Day11 (There was just a little on 10 so 10&&11 together)

Added files: stackOperations.cpp,peekOperationStack.cpp,stackTop&stackBottom.cpp

Just understood what the file name signifies.

In stackOperations.cpp,did (push,pop,isFull,isEmpty)operations.

______________________________________________________

DAY 12

Added files:stackUsingLinkedList.cpp,stackTop&BottomInLinkedList.cpp,parenthesisMatching.cpp,multipleParenthesisMatching.cpp

Understood what thr file names signifies.

Basically same things as previous days BUT with linkedList including

->How to match parenthesis

->How to match multiple parenthesis(Brackets)

______________________________________________________

DAY 13

Added files: infixToPostfix.cpp

Understood about infix,prefix and postfix.

Postfix is majorly used by machines as understanding it us easy for machines.

__________________________________________________

DAY 14

Added file: queueImplementation.cpp

understood about queue and that unlike stack, it works on fifo principle.

Wrote a cpp code for that operation but i see that the cpp code i wrote is linear
and after every dequeue, i lose the access to starting memory blocks of array for O(1) 
as this could have been solved by shifting all elements of array but this would cause O(n).
I researched and found that i can solve this with circular queue. I'll get to that soon.

_________________________________________________________________________

DAY 15

Added files: circularQueue.cpp

The problem with linear queue was solved using circular queue
also known ring buffers or circular buffers.

_____________________________________________________________

DAY 16

Added files:queueUsingLinkedList.cpp,doubleEndedQueue.cpp
bubbleSort.cpp,insertionSort.cpp

Queue was made using linked list and double ended one with array.

Started sorting algorithm.

Did bubble sort and insertion sort.

Bubble sort: Pushes all the heavy elements to backside and has O(n²)
This is stable algo but non adative. however, this can be made adaptive.

Insertion sort:This Considers the first element as sorted and starts from another
and checks its relation with first element. if first element is greater then second,
pushes the second to first place and and first one backward. This is also stable and 
this is adaptive from beginning. Time complexity O(n) if already sorted(best case).
worst case(if sorted in reverse order) O(n²). Average case O(n²)


_____________________________________________

DAY 17

Added files: selectionSort.cpp,quickSort.cpp,mergeSort.cpp

selection sort: we assume the current element smallest and move forward and if another
smaller is found then we make that smallest. after the array finishes in 'j', the value 
of array at index 'i' is swapped with index of minimum value. Time complexity O(n²) in all cases.
This is neither adaptive nor stable.

Quick sort: We take an element as pivot element and arrange the pivot element in such way
that its one side are all elements smaller and other side greater then it. then we repeat this 
for two sub-arrays we have. Time complexity O(n²) for worst case if array is already sorted. 
O(nlogn) is average and best case. This is not stable and not adaptive. 

Merge sort: we take an array, divide it using recursive mergeSort function, when there are only 2 elements 
it gets divided into single elements and divided element's partition mergeSort does nothing as low<high fails.
when thess 2 elements' pass to merge function(which looks at 2 elements and treats it like 2 sorted arrays) 
,this function merges the number and sorts them. This creates a sorted partition 
in the array and when next partition is dropped by mergeSort function, it also gets sorted. this happens 
recursively and when parent mergeSort's merge gets triggers, there will be 2 sorted partitions which our 
merge function will merge and sort. 

ONE THING I SHOULD REMEMBER INCASE I FORGET: Array never gets divided, its just that the function only gets to see a partition 
so it treats it like 2 arrays.

Time complexity: O(nlogn) in all cases (best, worst, average) because the tree divides evenly and every level 
requires a full pass to merge. unlike quick sort this sort's speed can't get changed with different array orders. 

Space complexity:O(n) because it requires an extra temporary array to hold elements while sorting them, 
ublike quick sort whith O(1) (worst) and O(nlogn) memory complexity

unlike quick sort This is a stable algorithm but like quick sort this is also not adaptive.so, this works same even if sorted array is given to it.

__________________________________________________________

DAY 18

Added files:

count sort: this sort creates an array of size of greatest element in given array+1 (+1 in order to get grestest element'th index) 
and we set the indices value of new array to 0 amd then increment the value at the element'th index by one everytime we encounter that element. 
This naturally sorts the array as the indices are already sorted. we then traverse the new array and check its elements and if element>0 then 
the index of that element is added as value from 0th index of our original array. this sorts the elements automatically as we are moving 
from 0 to front and copying in same order.

Time complexity: O(n+k), where n=size of given array and k is max element.However, if n is exceptionally large, so, k is negligible 
and time comolexity becomes O(n). This is faster then all algos above but at the cost of space.

Space complexity: O(k) so if k is exceptionally large, this becomes slower then others and this will take massive memory. 

This is neither stable nor adaptive

_______________________________________________________

(forgot to push at day 18)

DAY 19

INTRODUCTION TO TREES

Root: Topmost node

Parent: Node connecting to child

child: Node connected by by other node above

siblings: Nodes belonging to same parent

leaf/extended node: Nodes with no child nodes

Internal node: nodes with atleast 1 child node

Depth: Distance from root(topmost node)

Height: Depth from bottommost node

Ancesteors: All the nodes connecting backward from a node

Descendends: All the hodes connecting forward(dounward) from a node

Edges: no of links(arrows)

n nodes=>n-1 edges

Degree: no of direct children

Degree of tree: Highest degree of a node in tree



BINARY TREE

:-The tree with at most 2 degrees. 

TYPES:
1) Full or Strict Binary Tree: All nodes have either 0 or 2 children

2) Perfect Binary Tree: Internal Nodes have exactly 2 children and all 
leaf nodes are on same level.

3) Complete/Almost complete Binary Tree: All levels are comoletely filled except possibly last level 
and all the keys of last level must be as left as possible.This is almost becoming perfect binary tree.

4) Degenerate Tree: Every parent node->exactly one child.

a) Left skewed: All childs on left side

b) Right skewed: All childs on right side

_______________________________________________

DAY 20

REPRESENTATION OF BINARY TREE

1)Array Representation: By using array

2) Linked Representation: By using Doubly linked list where both pointers point to different node

________________________________________________

DAY 21

Added files: representationOfBinaryTree.cpp, preOrderTraversal.cpp

Represented a binary ttee using list and tried unique_ptr for one node for first time.



TRAVERSAL IN BINARY TREE

1)Preorder Traversal: Root->Left subtree->Right subtree

2)Postorder Traversal: Left subtree->Right subtree->Root

3)Inorder Traversal: Left subtree->Root->Right subtree

_____________________________________________

DAY 22

Added files: postOrderTraversal.cpp, inOrderTraversal.cpp

The file name specidies everything

___________________________________________

DAY 23

Added files:BST.cpp

Binary Search Tree

Its basically a binary tree BUT Left subtree < Root && Right Subtree > Root (Even duplicates aren't allowed)

And the left and right subtrees are also binary search trees

inorder traversal of BST gives sorted result

___________________________________________

DAY 24

Added files: searchingInBST.cpp,insertionInBST.cpp

Searching is highly efficient with O(log n) at best and average case and O(n) at worst case if 
the tree is skewed at either side. Basically this wiol be linked list at this skewed case.

insertion is also really efficient witn O(log n) time complexity.

_________________________________________________

DAY 25

Added files: None

Deleting Node in BST

I thought deleting would be simple as linked list but i was wrong. Deleting leaf node is easy BUT non-leaf node and 
root nodes are a nightmare. I thought i could even practice a code of this but because i started late today, i could not 
finish a code and i dont want to copy paste that without concept and understanding so, tomorrow it is.

___________________________________________________

DAY 26

Added files: deletionInBST.cpp

It was a bit confusing at first but i got it now. what is done is if the node to delete is leaf node, it just deletes that node. 
if not then it is replaced with its inorder predesessor(left then continue right). since it is replaced with predesessor, the duplicate 
exists in left side. after continuous recursion, it finally reaches that point. if that has a left child again recursion does its work. finally 
it reaches leaf node and that node is deleted, so, code rerurns nullptr which gets assigned to the node->side as it is called like this: 

node->side=deleteNode(root,val);

so, that part gets nullptr in this rewinding process where all recursions clear the stack one by one.



AVL TREES

->Height balanced BST

->Max height difference allowed=+- 1

->Balance factor= height of right subtree - height of left subtree

->Rotation is required if tree becomes unbalanced. (i dont know what this rotation is but guess we'll see)

_________________________________________________________

DAY 27

ROTATION IN AVL TREES

LL Rotation : when node is inserted in left->left side

RR Rotation : when inserted in Right->right side

LR Rotation : when in Left->right side

RL Rotation : when in Right->left

made a file for these but i dont have time today for this so its empty.

____________________________________________

