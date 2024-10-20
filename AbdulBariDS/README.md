# Array ADT (Abstract data type)
* representation of data and operations on data combined together is called ADT.
* representation is given by compiler and operations are provided by developer.
* Data -- array space and type, size of array, lenght of an array
* representation -- delete, insert, search, etc.
* Method to make search of a key faster in array (in linear search)
  - Transposition -- whenever you find a key with linear search, move it one step forward.
  - Move to front/head -- swap to first element
*  While loop and tail recursion are same
  - Binary search can be done with while or recursion
  - only finding can come in one case, when mid is same as element.
- 



Tree:
* Root : only node which has no parent in the tree.
* parent: any mode which have at least one children is a parent
* child: a node with a parent is called child
  - parent and immediate child are connected with 1 edge.
* siblings: nodes which are having same parent is called sibling.
* descendent: all nodes which can be travelled to by a node, are called descendent of that node.
* ancestor: all nodes coming in a path between that node to root.
* degree of a node: number of direct children of the node is a degree of that node
* degree of a tree: maxinmum degree of any node in a tree is called degree of a tree.
* leaf/external/termnal nodes: nodes with degree zero
* non-leaf/internal/non-termianl nodes: nodes with non-zero degree
* level: level starts 1 onwards, root is at level 1. for level we count nodes on path from root till that level.
* height: root at height zero. for height we count edges.
* forests: collection of trees are called forests. there won't be any root.

binary tree: 
* binary: a tree of degree 2. node can have at most 2 children. (e.g. child <= 2). childs are called left, right child.
* left-skewed binary tree (only left child), right skewedd binary tree (only right child)
* number of binary trees
  - WITHOUT LABELS
  - given number of nodes - catalon number: T(n) = 2nCn/(n+1) , e.g. 5 nodes - 2*5 C 5 /(5 + 1) = 10C5/6 = (10 * 9 * 8 * 7 * 6 / 5 * 4 * 3 * 2 * 1) / 6 = 42 
  - Recursive formulae for catalon number T(n) = Sigma(i = 1 to n) T(i - 1) * T(n - 1).
  - with maximum height : max height of a tree with number of n nodes : (n-1) :: number of trees with max height 2 ^ (n-1)
  - WITH LABELS
  - n! means, n nodes can be placed in one tree form, in these many number of ways. T(n) labeled = T(n) unlabelled * n!
* Given height
  - possible nodes : min nodes = (h + 1), (G.P series) max nodes = (2 ^ (h+1)) - 1
  - h + 1 <= nodes <= (2 ^ (h+1)) - 1
  - O(h) to O(non-linear)
* Given nodes
  - possible heights : min h =  log2(n + 1) -  1, max h = (n - 1)
  - log2(n+1) - 1 <= height <= n - 1
  - O(log(n)) to O(n) which is logarithemic to linear
* leaf nodes degree(0), non-leaf nodes degree(non-zero) // relationship between internal/external tree.
  - number of leaf nodes or number of degree(0) nodes = number of degree(2) nodes + 1, FOR ANY BINARY TREE.
* Strict binary trees / proper BT / complete BT / strict 2 - ary tree
  - Tree nodes can have only 0 or 2 child. // strictly binary, no unary
  - heights vs nodes
      - height given give number of nodes : max nodes are same as normal binary tree = (2 ^ (h+1) - 1), but for min number of nodes = (2 * h) + 1 
      - nodes givein find the height: max = (n + 1) / 2, min = log2(n+1) - 1
  - External vs internal nodes
      - number of leaf nodes = number of non-leaf nodes + 1; e = i + 1; //same as binary tree
* Strict m-ary trees (m is max degree)
  - for normal, m-ary, capacity is m, but it will be 0 to m, and that will decide degree of a tree.
  - capacity is 4 for 4 - ary tree, but degree can be less for a tree, as node can have children between 0 - 4 children.
  - strict m-ary means, either 0 or m children. Capacity is m, and degree can be 0 0r m.
  - height vs nodes
      - height given - find nodes: min nodes = (m * h) + 1, max nodes = (m ^ (h+1) - 1) / (m - 1);
      - nodes given - find height: min height = logm(n (m - 1) + 1) - 1, max heights =  (n - 1) /  m;
  - internal vs external nodes
      - external nodes (e) = internal nodes (i) * 2 + 1 =  (m - 1) * i + 1;
      - internal nodes (i) = (e - 1) / (m - 1);
* Binary tree representation
  - array
    - array index starts from index 1 onwards. if something is starting with 0 then, ignore 0 always, and continue with 1 as start.
    - element at i, then left child at = 2 * i, right child at = 2 * i + 1
    - child given at i, then parent at i/2 (floor value)
  - linked
    - struct Node {
        struct Node *left;
        int data;
        struct Node *right;
      };
    - n nodes then, n + 1 NULL pointers // same as e = i + 1
* Full binary tree vs complete binary tree vs Strict binary tree
    - Full binary tree: binary tree of height h, having max nodes, is called a full binary tree. there will be no spaces at all at end in array representation
    - Complete binary tree: binary tree of height h, can have less than max nodes. basically there won't be spaces in-between in array representation.
      - Complete binary tree will be full binary tree upto h-1, at last level elements will be filled left-right.
    - Incomplete binary tree: in array represenation it will have some intermittent spaces.
    - Full is a complete binary tree always, but complete can't be always full binary tree. full is special case of complete binary tree.
    - Strict/proper binary tree: will have 0 or 2 child. there could be blank spaces in between in an array represenation (at some places, strict is called complete, and complete binary tree is called almost complete.)
* Traversal
  - pre-order - left right root
  - post-order - root left right
  - in-order - left root right
  - level-order - level by level
* Creating tree from given tree and nodes
  - ![image](https://github.com/user-attachments/assets/7cba696f-a3fc-44eb-92f3-a76e0e574427)
  - we use queue, to add addressess, pop and ask if there is left or right child, create a node, made parent point to that node, andadd address to queue.
  - pop the address from queue, make p point to that node, check again left and right, create and make temp point to there and store in queue, make parent point to temp, and go for other side, and make tmep point there.
  - keep on repeating, until queue is empty. and root will be there which is holding the value for root node.
  - https://www.udemy.com/course/datastructurescncpp/learn/lecture/13168486#overview
* 
