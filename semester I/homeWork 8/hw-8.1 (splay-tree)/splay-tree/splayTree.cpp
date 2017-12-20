#include "splayTree.h"
#include <stack>
#include <utility>

using namespace std;

// Гензель(двоичнный) - ходит по двоичному дереву, запоминая путь
struct Hansel;

struct SplayNode {
    KeyType key;
    ValueType value;

    SplayNode* leftChild;
    SplayNode* rightChild;

    Hansel* hansel;
};

struct Hansel {
    stack<SplayNode*> pass;
    SplayNode* lastVisitedChild;
};

struct Map {
    SplayNode* root;
};

// перемещает узел дерева с ключом key в корень
void splay(SplayNode* root, const KeyType& key);

// объединяет 2 дерева в 1
SplayNode* merge(SplayNode* left, SplayNode* right);

// возвращает указатель на элемент с ключом key
// nullptr, усли такого элемента не существует
SplayNode* findElement(const KeyType& key, SplayNode* root);

void mapUpdate(Map* map, SplayNode* root);

void initHansel(SplayNode* root);

// перейти в левую ветку
void moveLeft(SplayNode* root);

// перейти в правую ветку
void moveRight(SplayNode* root);

// перейти к родителю текущей ветки
void moveUp(SplayNode* root);

// перейти к тому потомку, от котрого пришел к родителю командой moveUp
void moveDown(SplayNode* root);

// перемещает Гензель в корень поддерева
void moveToRoot(SplayNode* root);


void add(const KeyType& key, const ValueType& value, Map* map)
{
    SplayNode* root = map->root;
    SplayNode* node = findElement(key, root);
    if (node != nullptr) {
        node->value = value;
    } else {
        moveUp(root);
        SplayNode* parent = root->hansel->pass.top();
        SplayNode* newNode = new SplayNode{key, value, nullptr, nullptr};
        if (key < parent->key) {
            parent->leftChild = newNode;
            moveLeft(root);
        } else if (key > parent->key) {
            parent->rightChild = newNode;
            moveRight(root);
        }
    }
    splay(root, key);
    moveToRoot(root);
}

const ValueType& get(const KeyType& key, Map* map)
{
    SplayNode* root = map->root;
    SplayNode* node = findElement(key, root);
    if (node == nullptr) {
        return "";
    } else {
        splay(root, key);
        return node->value;
    }
}

bool isExist(const KeyType& key, Map* map)
{
    SplayNode* root = map->root;
    SplayNode* node = findElement(key, root);
    if (node != nullptr)
        splay(root, key);

    return (node != nullptr);
}

void deleteKey(const KeyType& key, Map* map)
{
    SplayNode* root = map->root;
    SplayNode* node = findElement(key, root);
    if (node == nullptr)
        return;

    splay(root, key);
    SplayNode* newRoot = merge(node->leftChild, node->rightChild);
    delete root;
    mapUpdate(map, newRoot);
}

SplayNode* findElement(const KeyType& key, SplayNode* root)
{
    initHansel(root);
    SplayNode* current = root;
    while (current != nullptr) {
        if (key < current->key) {
            current = current->leftChild;
            moveLeft(root);
        } else if (key > current->key) {
            current = current->rightChild;
            moveRight(root);
        } else {
            return current;
        }
    }
    return nullptr;
}

const KeyType& maxKey(SplayNode* node)
{
    if (node == nullptr)
        return "";

    while (node->rightChild != nullptr) {
        node = node->rightChild;
    }
    return node->key;
}

SplayNode* merge(SplayNode* left, SplayNode* right)
{
    KeyType mKey = maxKey(left);
    if (mKey == "")
        return right;

    splay(left, mKey);
    left->rightChild = right;
    return left;
}

void initHansel(SplayNode* root)
{
    root->hansel->pass.push(root);
}

void moveLeft(SplayNode* root)
{
    Hansel* current = root->hansel;
    SplayNode* top = current->pass.top();
    current->pass.push(top->leftChild);
}

void moveRight(SplayNode* root)
{
    Hansel* current = root->hansel;
    SplayNode* top = current->pass.top();
    current->pass.push(top->rightChild);
}

void moveUp(SplayNode* root)
{
    Hansel* current = root->hansel;
    current->lastVisitedChild = current->pass.top();
    current->pass.pop();
}

void moveDown(SplayNode* root)
{
    Hansel* current = root->hansel;
    current->pass.push(current->lastVisitedChild);
    current->lastVisitedChild = nullptr;
}

void moveToRoot(SplayNode* root)
{
    Hansel* current = root->hansel;
    current->lastVisitedChild = nullptr;
    while (!current->pass.empty()) {
        current->pass.pop();
    }
}

void mapUpdate(Map *map, SplayNode *root)
{
    map->root = root;
}

