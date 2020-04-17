// C program for different tree traversals 
#include <iostream> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{
    int data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 

/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right sdubtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->data << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}  

Node* TreeSearch(struct Node* node, int key){
    if (node == NULL ||  node->data == key)
        return node;
    
    if (key < node->data)
        return TreeSearch(node->left, key);
    if (key > node->data)
        return TreeSearch(node->right, key);
}

Node* TreeMinimum(struct Node* node){
    Node* minimum = node;
    while (minimum->left != NULL){
        minimum = minimum->left;
    }
    return minimum;
}

Node* TreeMaximum(struct Node* node){
    Node* maximum = node;
    while (maximum->right != NULL){
        maximum = maximum->right;
    }
    return maximum;
}


/* Driver program to test above functions*/
int main() 
{ 
    struct Node* root = new Node(0); 
    root->left = new Node(1); 
    root->left->left = new Node(3); 
    root->left->left->left = new Node(7); 
    root->left->right = new Node(4); 
    root->left->right->left = new Node(8); 
    root->left->right->right = new Node(9); 
    root->right = new Node(2); 
    root->right->left = new Node(5); 
    root->right->right = new Node(6);  
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    printPreorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root); 

    cout << "\nSearch for key 2 \n";
    int key = 2;
    cout <<" key 2 's left child's key is:"<< TreeSearch(root, key)->left->data << "\n";

    cout << "the root is still: " << root->data << "\n";
    
    cout << "since the tree is unsorted, \nthe minimum and maximum would be: \n" ;
    cout << TreeMinimum(root)->data << "\n";
    cout << TreeMaximum(root)->data << "\n";

    return 0; 
} 