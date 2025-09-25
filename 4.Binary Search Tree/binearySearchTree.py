class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
        self.count = 1   

def insert(root, key):
    if root is None:
        return Node(key)
    if root.val == key:
        root.count += 1   
        return root
    if root.val < key:
        root.right = insert(root.right, key)
    else:
        root.left = insert(root.left, key)
    return root

def delete(root, key):
    if root is None:
        return root

    if key < root.val:
        root.left = delete(root.left, key)

    elif key > root.val:
        root.right = delete(root.right, key)

    else:
        if root.count > 1:
            root.count -= 1
            return root

        # Case 1: Node has no child
        if root.left is None and root.right is None:
            return None

        # Case 2: Node has only one child
        elif root.left is None:
            return root.right
        elif root.right is None:
            return root.left

        # Case 3: Node has two children → find inorder successor (smallest in right subtree)
        temp = root.right
        while temp.left is not None:
            temp = temp.left

        # Replace current node’s value and count with inorder successor
        root.val = temp.val
        root.count = temp.count
        temp.count = 1  # reset before deleting so it's properly removed
        root.right = delete(root.right, temp.val)

    return root

def search(root, key):
    if root is None:
        return None

    if key == root.val:
        return root.count
    elif key < root.val:
        return search(root.left, key)
    else:
        return search(root.right, key)

def inorder(root):
    if root:
        inorder(root.left)
        if root.count > 1:
            print(f"{root.val}({root.count})", end=" ")
        else:
            print(root.val, end=" ")
        inorder(root.right)

def preorder(root):
    if root:
        if root.count > 1:
            print(f"{root.val}({root.count})", end=" ")
        else:
            print(root.val, end=" ")
        preorder(root.left)
        preorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        if root.count > 1:
            print(f"{root.val}({root.count})", end=" ")
        else:
            print(root.val, end=" ")

def depth(root):
    if root is None:
        return 0
    left_depth = depth(root.left)
    right_depth = depth(root.right)
    return 1 + max(left_depth, right_depth) 

def mirror_tree(root):
    if root is None:
        return None
    new_root = Node(root.val)
    new_root.count = root.count
    new_root.left = mirror_tree(root.right)
    new_root.right = mirror_tree(root.left)
    return new_root

def copy_tree(root):
    if root is None:
        return None
    new_root = Node(root.val)
    new_root.count = root.count
    new_root.left = copy_tree(root.left)
    new_root.right = copy_tree(root.right)
    return new_root

def display_parents(root):
    if root is None:
        return
    if root.left or root.right:
        print(f"Parent: {root.val}({root.count}) -> ", end="")
        if root.left:
            print(f"Left Child: {root.left.val}({root.left.count}) ", end="")
        else:
            print("Left Child: None ", end="")
        if root.right:
            print(f"Right Child: {root.right.val}({root.right.count})", end="")
        else:
            print("Right Child: None", end="")
        print()  # new line
    display_parents(root.left)
    display_parents(root.right)

def display_leaf_nodes(root):
    if root is None:
        return
    if root.left is None and root.right is None:  
        if root.count > 1:
            print(f"{root.val}({root.count})", end=" ")
        else:
            print(root.val, end=" ")
    display_leaf_nodes(root.left)
    display_leaf_nodes(root.right)

def display_level_wise(root):
    if root is None:
        return
    queue = [root]
    while queue:
        level_size = len(queue)   
        for i in range(level_size):
            current = queue.pop(0)
            if current.count > 1:
                print(f"{current.val}({current.count})", end=" ")
            else:
                print(current.val, end=" ")
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        print() 


root = int(input("Enter the root of the tree: "))

tree = Node(root)

operation = True

while operation:
    choice = int(input(
        "Which option you would like to perform?: \n"
        " 1. Insertion \n"
        " 2. Deletion \n"
        " 3. Search \n"
        " 4. Display Traversals \n"
        " 5. Depth of Tree \n"
        " 6. Display Mirror Image \n"
        " 7. Create a Copy \n"
        " 8. Display All Parent Nodes with Their Child Nodes \n"
        " 9. Display Leaf Nodes \n"
        " 10. Display Tree Level-wise \n"
        " 11. Exit \n\nEnter your choice number: "
    ))

    if choice == 1:
        noOfElements = int(input("How many elements you want to enter: "))
        for i in range(noOfElements):
            element = int(input(f"Enter the element no.{i+1} you want to insert: "))
            tree = insert(tree, element)
    
    elif choice == 2:
        element = int(input("Enter the element you want to delete: "))
        tree = delete(tree, element)

    elif choice == 3:
        element = int(input("Enter the element you want to search: "))
        result = search(tree, element)
        if result:
            print(f"\nElement {element} found with count = {result}\n")
        else:
            print(f"\nElement {element} not found in the tree\n")
    
    elif choice == 4:
        print("\nTraversal Options: ")
        choice = int(input(
            " 1. Inorder \n"
            " 2. Preorder \n"
            " 3. Postorder \n\nEnter your choice: "
        ))

        if choice == 1:
            print("Inorder Traversal: ", end="")
            inorder(tree)
        elif choice == 2:
            print("Preorder Traversal: ", end="")
            preorder(tree)
        elif choice == 3:
            print("Postorder Traversal: ", end="")
            postorder(tree)
        else:
            print("Invalid traversal choice!")

        print("\n")
    
    elif choice == 5:
        print(f"\nDepth (Height) of the tree = {depth(tree)}\n")
    
    elif choice == 6:
        mirrored = mirror_tree(tree)
        print("\n-- Mirror Image Created--")
        display_parents(mirrored)
    
    elif choice == 7:
        copied = copy_tree(tree)
        print("\n-- Copy of Tree Created (original tree preserved) --")
    
    elif choice == 8:
        print("\nParent Nodes with Their Children:")
        display_parents(tree)

    elif choice == 9:
        print("\nLeaf Nodes: ", end="")
        display_leaf_nodes(tree)

    elif choice == 10:
        print("\nTree Level-wise:")
        display_level_wise(tree)
      
    elif choice == 11:
        operation = False
    
    else:
        print("\nInvalid Choice Entered! \n\n")