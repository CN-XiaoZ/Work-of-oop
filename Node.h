//
// Created by zyc on 17-6-23.
//

#ifndef NODELIST1_NODE_H
#define NODELIST1_NODE_H

#include <iostream>

using namespace std;
enum type {
    Int, Double, String, Base
};

class Node {
protected:
    type TypeofNode;
public:
    Node *next;

    Node() { TypeofNode = Base; }

    type Get_type() { return TypeofNode; }

    virtual void print() {}

    virtual void *get_Value() { return 0; };
};

class IntNode : public Node {
private:
    int Value;
public:
    IntNode(int Value) {
        this->Value = Value;
        TypeofNode = Int;
    }

    IntNode(void *Value) {
        int *p = (int *) Value;
        this->Value = *p;
        TypeofNode = Int;
    }

    IntNode(const IntNode &Value) {
        this->Value = Value.Value;
        TypeofNode = Int;
    }

    IntNode(const IntNode &Value, Node *next) {
        this->Value = Value.Value;
        this->next = next;
        TypeofNode = Int;
    }

    void *get_Value() {
        int *a = &Value;
        return a;
    }

    void print() {
        cout << Value << "\n";
    }
};

class DouNode : public Node {
private:
    double Value;
public:
    DouNode(double Value) {
        this->Value = Value;
        TypeofNode = Double;
    }

    DouNode(void *Value) {
        double *p = (double *) Value;
        this->Value = *p;
        TypeofNode = Double;
    }

    DouNode(const DouNode &Value) {
        this->Value = Value.Value;
        TypeofNode = Double;
    }

    DouNode(const DouNode &Value, Node *next) {
        this->Value = Value.Value;
        this->next = next;
        TypeofNode = Double;
    }

    void *get_Value() {
        double *a = &Value;
        return a;
    }

    void print() {
        cout << Value << "\n";
    }
};

class StrNode : public Node {
private:
    string Value;
public:
    StrNode(string Value) {
        this->Value = Value;
        TypeofNode = String;
    }

    StrNode(void *Value) {
        string *p = (string *) Value;
        this->Value = *p;
        TypeofNode = String;
    }

    StrNode(const StrNode &Value) {
        this->Value = Value.Value;
        TypeofNode = String;
    }

    StrNode(const StrNode &Value, Node *next) {
        this->Value = Value.Value;
        this->next = next;
        TypeofNode = String;
    }

    void *get_Value() {
        string *a = &Value;
        return a;
    }

    void print() {
        cout << Value << "\n";
    }
};

#endif //NODELIST1_NODE_H
