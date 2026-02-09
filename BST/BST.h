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
        public:
            BST();
    };
}

template <class Type>
ds::BST<Type>::BST():root(nullptr), count(0){}