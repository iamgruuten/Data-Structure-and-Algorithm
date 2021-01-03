### Binary Search Revision

The properties that separate a binary search tree from a regular binary tree is

1. All nodes of left subtree are less than the root node
2. All nodes of right subtree are more than the root node
3. Both subtrees of each node are also BSTs i.e. they have the above two properties

There are many different types of binary trees:
- Complete Binary tree
- Perfect Binary tree
- Balanced Binary tree (known as the AVL tree)
- Degenerate Binary tree

src="https://miro.medium.com/max/16000/1*CMGFtehu01ZEBgzHG71sMg.png" width="250">

## Cases when searching a node to be deleted
1) Node to be deleted is leaf: Simply remove from the tree.

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70
         /  \    /  \                     \    /  \
       20   40  60   80                   40  60   80

2) Node to be deleted has only one child: Copy the child to the node and delete the child

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70
            \    /  \                          /  \
            40  60   80                       60   80

3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used.


              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70
                 /  \                            \
                60   80                           80



## Self Balancing Binary Search Tree

Self Balancing Binary Search Tree are height-balanced binary search trees that automatically keeps height as small as possible when insertion and deletion operations are performed on tree. The height is typically maintained in order of Log n so that all operations take O(Log n) time on average.

It works by using rotation to peform a re-balanced BST without violating the BST property
