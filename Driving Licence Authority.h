//
//  Header.h
//  P3_04071913024_MuhammadWahab_A4
//
//  Created by Ch Muhammad Wahab on 4/12/2020.
//  Copyright © 2020 Ch Muhammad Wahab. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include<iostream>
#include<fstream>
#include <chrono>
#include <ctime>
using namespace std;
class person{
    int token;
    long long id_card;
    string name;
    string BG;
    long long cont_no;
    string day;
    int dated;
    string month;
public:
    person():token(0),id_card(0),name(""),BG(""),cont_no(0),day(""){}
    void assignday(int d){
        auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        string time="",tt= ctime(&givemetime);
        for (int i=11; i<=15; i++) {
            time=time+tt[i];
        }
        string dayno,mm;
        int val,val2;
        if(tt[8]!=' ')
        {
            val=tt[8];
            val-='0';
            val*=10;
            val2=tt[9];
            val2-='0';
            val+=val2;
        }
        else
        {
            val=tt[9];
            val-='0';
        }
        dayno=tt[0]; dayno+=tt[1]; dayno+=tt[2];
        mm=tt[4]; mm+=tt[5]; mm+=tt[6];
        string mmm[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        int dayinmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string ddd[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
        int di=0,dm=0;
        
        while(mm.compare(mmm[dm])!=0)
        {
            dm++;
        }
        
        while(dayno.compare(ddd[di])!=0)
        {
            di++;
            di%=7;
        }
        
        do{
            val++;
            if(val>dayinmonth[dm])
            {
                val=1;
                dm++;
                dm%=12;
            }
            di++;
            di%=7;
        }while(ddd[di].compare(ddd[d])!=0);
        
        day=ddd[d];
        dated=val;
        month=mmm[dm];
    }
    
    friend istream& operator >> (istream& insert,person& obj){
        insert.ignore();
        cout<<"Your name:";getline(insert,obj.name);
        cout<<"Your id_card number:";insert>>obj.id_card;
        cout<<"Your Blood-Group:";insert>>obj.BG;
        cout<<"Your Phone-Number:";insert>>obj.cont_no;
        cout<<"Token no "<<++obj.token<<" has been issued against id-card number '"<<obj.id_card<<"'\n";
        cout<<"Written exam and driving test will be conducted on "<<obj.day<<" "<<obj.month<<" "<<obj.dated<<endl;
        return insert;
    }
    friend ostream& operator << (ostream& out,person& obj){
        out<<"Token:"<<obj.token<<endl;
        out<<"Name:"<<obj.name<<endl;
        out<<"Id_card number:"<<obj.id_card<<endl;
        out<<"Blood-Group:"<<obj.BG<<endl;
        out<<"Phone-Number:"<<obj.cont_no<<endl;
        out<<"Written exam and driving test will be conducted on "<<obj.day<<" "<<obj.month<<" "<<obj.dated<<endl;
        return out;
    }
    bool operator ==(int val){
        return token==val;
    }
};

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
    queue() {
        size=20;
        n=0;
        rear_idx = front_idx = NULL;
    }
    void operator=(const queue<t>& s) {
        make_empty();
        n=0;
        size=s.size;
        node<t>* temp;
        temp = s.front_idx;
        while (temp != NULL) {
            push(temp->data);
            temp = temp->next;
        }
    }
    bool remove(const int& val) {
        if (rear_idx == NULL)
            return false;
        node<t>* temp;
        temp = rear_idx;
        if (temp->data == val) {
            rear_idx = temp->next;
            delete temp;
            n--;
            return true;
        }
        while (temp->next != NULL) {
            if (temp->next->data == val) {
                node<t>* to_del;
                to_del = temp->next;
                temp->next = temp->next->next;
                delete to_del;
                n--;
                return true;
            }
            temp = temp->next;
        }
        return false;
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
        if (n>=size)
            throw("Only 20 people can have exam and test drive in a day\n");
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
        n++;
    }
    
    void pop() {
        if (empty())
            throw("Queue Underflow!");
        node<t>* temp;
        temp = front_idx;
        front_idx = front_idx->next;
        delete temp;
        n--;
        if (front_idx == NULL)
            rear_idx = NULL;
    }
    t front() const {
        if (empty())
            throw("Queue is empty!");
        return front_idx->data;
    }
    bool full() const {
        node<t>* temp;
        temp = new node<t>;
        if (temp == NULL)
            return true;
        else {
            delete temp;
            return false;
        }
    }
    void make_empty() {
        while (!empty())
            pop();
    }
};

#endif /* Header_h */
