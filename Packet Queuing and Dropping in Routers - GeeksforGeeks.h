//
//  Header.h
//  Packet Queuing and Dropping in Routers
//
//  Created by Ch Muhammad Wahab on 05/12/2020.
//  Copyright © 2020 Ch Muhammad Wahab. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include<iostream>
#include<fstream>
#include <stack>
#include <ctime>
using namespace std;
template<typename t>
struct node{
    t data;
    node<t> *next;
    node(const t &val=0,node<t> *n=NULL){
        data=val;
        next=n;
    }
};
template<typename t>
class queue {
    node<t>* rear_idx;
    node<t>* front_idx;
    int size,n;
public:
    queue(const int s=1024) {
        size=s;n=0;
        rear_idx = front_idx = NULL;
    }
    void operator=(const queue<t>& s) {
        size=s.size;
        n=0;
        make_empty();
        node<t>* temp;
        temp = s.front_idx;
        while (temp != NULL) {
            push(temp->data);
            temp = temp->next;
        }
    }
    queue(const queue<t>& s) {
        rear_idx = front_idx = NULL;
        operator=(s);
    }
    ~queue() {
        make_empty();
    }
    bool empty() const {
        return rear_idx == NULL;
    }
    void push(const t& val) {
        //cout<<"n:"<<n<<" size:"<<size<<endl;
        if (full())
            throw "Heap overflow\n";
        node<t>* temp;
        temp = new node<t>(val,NULL);
        if (empty()) {
            rear_idx = temp;
            front_idx = rear_idx;
        }
        else {
            rear_idx->next = temp;
            rear_idx = temp;
        }
        n+=sizeof(*this);
    }
    
    void pop() {
        if (empty())
            throw("Queue Underflow! No packet in router\n");
        node<t>* temp;
        temp = front_idx;
        front_idx = front_idx->next;
        delete temp;
        if (front_idx == NULL)
            rear_idx = NULL;
        n-=sizeof(*this);
    }
    t front() const {
        if (empty())
            throw("Queue is empty!");
        return front_idx->data;
    }
    bool full() const {
        return n>=size;
    }
    void make_empty() {
        while (!empty())
            pop();
    }
    void reverse(){
        stack<int> s;
        while(!empty()){
            s.push(front());
            pop();
        }
        while(!s.empty())
        {
            push(s.top());
            s.pop();
        }
    }
};

#endif /* Header_h */

