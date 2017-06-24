//
// Created by zyc on 17-6-23.
//

#ifndef NODELIST1_LIST_H
#define NODELIST1_LIST_H

#include "Node.h"

using namespace std;

class List {
public:
    List();

    List(const List &list);

    ~List();

    Node *Create(Node *node);

    void Print() const;

    void Push_back(Node &Value);

    void InsertK(int Index, Node &Value);

    void Delete(int Index);

    void Turn();

    void Destroy();

    void Combine(const List &list);

private:
    Node *FirstNode;
    int ListSize;
};


#endif //NODELIST1_LIST_H
