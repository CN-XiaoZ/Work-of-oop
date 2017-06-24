//
// Created by zyc on 17-6-23.
//

#include "List.h"

using namespace std;

/**
 * 创建一个新的Node对象,分类型创建
 * @param node Node类型指针
 * @return Node类型指针
 */
Node *List::Create(Node *node) {
    Node *p = NULL;
    Node *Node1;
    switch (node->Get_type()) {
        case Int:
            Node1 = new IntNode(node->get_Value());
            p = Node1;
            break;
        case Double:
            Node1 = new DouNode(node->get_Value());
            p = Node1;
            break;
        case String:
            Node1 = new StrNode(node->get_Value());
            p = Node1;
            break;
        case Base:
            p = NULL;
            break;
    }
    return p;
}

List::List() {
    FirstNode = NULL;
    ListSize = 0;
}

List::List(const List &list) {
    ListSize = list.ListSize;
    if (ListSize == 0) {
        FirstNode = NULL;
        return;
    }
    Node *SourceNode = list.FirstNode;
    FirstNode = Create(SourceNode);
    SourceNode = SourceNode->next;
    Node *target = FirstNode;
    while (SourceNode != NULL) {
        target->next = Create(SourceNode);
        target = target->next;
        SourceNode = SourceNode->next;
    }
    target->next = NULL;
}

List::~List() {
    while (FirstNode != NULL) {
        Node *target = FirstNode->next;
        delete FirstNode;
        FirstNode = target;
    }
}

void List::Print() const {
    int count = 1;
    Node *CurrentNode = FirstNode;
    while (count != ListSize + 1) {
        cout << "No. " << count << " is ";
        CurrentNode->print();
        CurrentNode = CurrentNode->next;
        count++;
    }
}

void List::Push_back(Node &Value) {
    Node *p = &Value;
    if (ListSize == 0) {
        FirstNode = Create(p);
        FirstNode->next = NULL;
    } else {
        Node *CurrentNode = FirstNode;
        for (int i = 0; i < ListSize - 1; i++) {
            CurrentNode = CurrentNode->next;
        }
        CurrentNode->next = Create(p);
    }
    ListSize++;
}

void List::InsertK(int Index, Node &Value) {
    Index = Index - 1;
    Node *p = &Value;
    int i = 0;

    if (Index == 0) {
        FirstNode = Create(p);
        FirstNode->next = NULL;
        ListSize = 1;
    } else {
        Node *CurrentNode = FirstNode;
        for (i = 0; i < Index - 1; i++) {
            CurrentNode = CurrentNode->next;
        }
        Node *NextNode = CurrentNode->next;
        CurrentNode->next = Create(p);
        CurrentNode->next->next = NextNode;
    }

    ListSize++;
}

void List::Delete(int Index) {
    Node *DeleteNode;
    Index = Index - 1;
    if (Index == 0) {
        DeleteNode = FirstNode;
        FirstNode = FirstNode->next;
    } else {
        Node *CurrentNode = FirstNode;
        for (int i = 0; i < Index - 1; i++) {
            CurrentNode = CurrentNode->next;
        }
        DeleteNode = CurrentNode->next;
        CurrentNode->next = CurrentNode->next->next;
    }
    ListSize--;
    delete DeleteNode;
}

void List::Turn() {
    Node *PreNode = NULL;
    Node *CurrentNode = FirstNode;
    Node *FroNode = FirstNode->next;
    while (CurrentNode->next != NULL) {
        FroNode = CurrentNode->next;
        CurrentNode->next = PreNode;
        PreNode = CurrentNode;
        CurrentNode = FroNode;
    }
    CurrentNode->next = PreNode;
    FirstNode->next = NULL;
    FirstNode = CurrentNode;
}

void List::Destroy() {
    while (FirstNode != NULL) {
        Node *target = FirstNode->next;
        delete FirstNode;
        FirstNode = target;
    }
    ListSize = 0;
}

void List::Combine(const List &list) {
    Node *CurrentNode = FirstNode;
    while (CurrentNode->next != NULL) {
        CurrentNode = CurrentNode->next;
    }
    Node *copy = list.FirstNode;
    for (int i = 0; i < list.ListSize; i++) {
        Push_back(*copy);
        copy = copy->next;
    }
}








