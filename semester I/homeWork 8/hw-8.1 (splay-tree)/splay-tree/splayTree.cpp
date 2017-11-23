#include "splayTree.h"
#include <stack>

using namespace std;

struct Node {
    KeyType key;
    ValueType value;
    Node* leftChild;
    Node* rightChild;
};

// Гензель(двоичнный) - ходит по двоичному дереву, запоминая путь
struct Hansel {
    stack<Node*> pass;
    Node* lastVisitedChild;
};

struct SplayTree {
    Node* root;
    Hansel* hansel;
};


// перейти в левую ветку
void moveLeft(Hansel* current);

// перейти в правую ветку
void moveRight(Hansel* current);

// перейти к родителю текущей ветки
void moveUp(Hansel* current);

// перейти к тому потомку, от котрого пришел к родителю командой moveUp
void moveDown(Hansel* current);

// перемещает Гензель в корень поддерева
void moveToRoot(Hansel* hansel);


// перемещает узел дерева с ключом key в корень
void splay(SplayTree* tree, const KeyType& key);

// объединяет 2 дерева в 1
Node* merge(Node* left, Node* right);


// возвращает указатель на элемент с ключом key
// nullptr, усли такого элемента не существует
Node* findElement(const KeyType &key, SplayTree *tree);


void add(const KeyType& key, const ValueType& value, SplayTree* tree)
{
    Node* node = findElement(key, tree);
    if (node != nullptr) {
        node->value = value;
    } else {
        moveUp(tree->hansel);
        Node* parent = tree->hansel->pass.top();
        Node* newNode = new Node{key, value, nullptr, nullptr};
        if (key < parent->key) {
            parent->leftChild = newNode;
            moveLeft(tree->hansel);
        } else if (key > parent->key) {
            parent->rightChild = newNode;
            moveRight(tree->hansel);
        }
    }
    splay(tree, key);
    moveToRoot(tree->hansel);
}

const ValueType& get(const KeyType& key, SplayTree* tree)
{
    Node* node = findElement(key, tree);
    if (node == nullptr) {
        return "";
    } else {
        splay(tree, key);
        return node->value;
    }
}

bool isExist(const KeyType& key, SplayTree* tree)
{
    Node* node = findElement(key, tree);
    if (node != nullptr) {
        splay(tree, key);
        return true;
    } else {
        return false;
    }
}

void deleteKey(const KeyType& key, SplayTree* tree)
{
    Node* node = findElement(key, tree);
    if (node == nullptr)
        return;

    splay(tree, key);
    Node* newRoot = merge(node->leftChild, node->rightChild);
    delete tree->root;
    tree->root = newRoot;
}

Node* findElement(const KeyType& key, SplayTree* tree)
{
    Node* current = tree->root;
    while (current != nullptr) {
        if (key < current->key) {
            current = current->leftChild;
            moveLeft(tree->hansel);
        } else if (key > current->key) {
            current = current->rightChild;
            moveRight(tree->hansel);
        } else {
            return current;
        }
    }
    return nullptr;
}


const KeyType& maxElement(Node* node)
{
    if (node == nullptr)
        return "";

    while (node->rightChild != nullptr) {
        node = node->rightChild;
    }
    return node->key;
}

Node* merge(Node* left, Node* right)
{
    KeyType max = maxElement(left);
    if (max == "") {
        return right;
    }
}

void moveLeft(Hansel *current)
{
    Node* top = current->pass.top();
    current->pass.push(top->leftChild);
}

void moveRight(Hansel *current)
{
    Node* top = current->pass.top();
    current->pass.push(top->rightChild);
}

void moveUp(Hansel *current)
{
    current->lastVisitedChild = current->pass.top();
    current->pass.pop();
}

void moveDown(Hansel *current)
{
    current->pass.push(current->lastVisitedChild);
    current->lastVisitedChild = nullptr;
}
