#pragma once
namespace ds{
    template <class Type>
    class BST{
        private:
            class Node{
                public:
                    Type data;
                    Node* left, * right;
                    Node():left(nullptr), right(nullptr){}
                    Node(Type item):left(nullptr), right(nullptr), data(item){}
                };
            Node* root;
            size_t count;

            Node* insert(Type item, Node* tree);
            Node* search(Type item, Node* tree) const;
            void printInOrder(Node* tree) const;
            void printPreOrder(Node* tree) const;
            void printPostOrder(Node* tree) const;
            int height(Node* tree);
            Node* remove(Type item, Node* tree);
            Node* min(Node* tree) const;
            Node* max(Node* tree) const;

        public:
            BST();
            void insert(Type item);
            bool search(Type item) const;
            size_t size() const;
            bool isEmpty() const;
            void printInOrder() const;
            void printPreOrder() const;
            void printPostOrder() const;
            int height();
            void remove(Type item);
            Type min() const;
            Type max() const;

    };
}

template <class Type>
ds::BST<Type>::BST():root(nullptr), count(0){}

template <class Type>
typename ds::BST<Type>::Node* ds::BST<Type>::insert(Type item, Node *tree){
    if (tree == nullptr) {
        Node* newNode = new Node(item); 
        count++;
        return newNode;
    }
    if (item < tree->data) tree->left = insert(item, tree->left);
    if (item > tree->data) tree->right = insert(item, tree->right);
    return tree;
}

template <class Type>
void ds::BST<Type>::insert(Type item){
    root = insert(item, root);
}

template <class Type>
typename ds::BST<Type>::Node* ds::BST<Type>::search(Type item, Node *tree) const{
    if (tree == nullptr) return nullptr;
    if (item < tree->data) return search(item, tree->left);
    if (item > tree->data) return search(item, tree->right);
    if (item == tree->data) return tree;
    return nullptr;
}

template <class Type>
bool ds::BST<Type>::search(Type item)const{
    return search(item, root) != nullptr;
}

template <class Type>
size_t ds::BST<Type>::size() const{
    return count;
}

template <class Type>
bool ds::BST<Type>::isEmpty() const{
    return count == 0;
}

template <class Type>
int ds::BST<Type>::height(Node* tree){
    if (tree == nullptr) return -1;
    return 1 + std::max(height(tree->left), height(tree->right));
}

template <class Type>
int ds::BST<Type>::height(){
    return height(root);
}

template <class Type>
void ds::BST<Type>::printInOrder(Node* tree)const{
    if (tree == nullptr) return;
    printInOrder(tree->left);
    std::cout << tree->data << " ";
    printInOrder(tree->right);
}

template <class Type>
void ds::BST<Type>::printInOrder()const{
    printInOrder(root);
    std::cout << std::endl;
}

template <class Type>
void ds::BST<Type>::printPreOrder(Node* tree)const{
    if (tree == nullptr) return;
    std::cout << tree->data << " ";
    printPreOrder(tree->left);
    printPreOrder(tree->right);
}

template <class Type>
void ds::BST<Type>::printPreOrder()const{
    printPreOrder(root);
    std::cout << std::endl;
}

template <class Type>
void ds::BST<Type>::printPostOrder(Node* tree)const{
    if (tree == nullptr) return;
    printPostOrder(tree->left);
    printPostOrder(tree->right);
    std::cout << tree->data << " ";
}

template <class Type>
void ds::BST<Type>::printPostOrder()const{
    printPostOrder(root);
    std::cout << std::endl;
}

template <class Type>
typename ds::BST<Type>::Node* ds::BST<Type>::min(Node* tree) const{
    if(tree->left == nullptr) return tree;
    else return min(tree->left);
}

template <class Type>
Type ds::BST<Type>::min() const{
    if(isEmpty()) throw std::runtime_error("Tree is empty");
    Node* minNode = min(root);
    return minNode->data;
}

template <class Type>
typename ds::BST<Type>::Node* ds::BST<Type>::max(Node* tree) const{
    if(tree->right == nullptr) return tree;
    else return max(tree->right);
}

template <class Type>
Type ds::BST<Type>::max() const{
    if(isEmpty()) throw std::runtime_error("Tree is empty");
    Node* maxNode = max(root);
    return maxNode->data;
}

template <class Type>
typename ds::BST<Type>::Node* ds::BST<Type>::remove(Type item, Node* tree){
    if (tree == nullptr) return nullptr;
    if (item < tree->data) tree->left = remove(item, tree->left);
    if (item > tree->data) tree->right = remove(item, tree->right);
    if (item == tree->data){
        if (tree->left == nullptr && tree->right == nullptr){
            delete tree;
            count--;
            return nullptr;
        }
        else if((tree->left != nullptr) != (tree->right != nullptr)){
            Node* next = tree->left != nullptr ? tree->left : tree->right;
            delete tree;
            count--;
            return next;
        } 
        else if(tree->left != nullptr && tree->right != nullptr){
            Node* suc = min(tree->right);
            tree->data = suc->data;
            tree->right = remove(suc->data, tree->right);
            return tree;
        }
    }
    return tree;
}

template <class Type>
void ds::BST<Type>::remove(Type item){
    root = remove(item, root);
}