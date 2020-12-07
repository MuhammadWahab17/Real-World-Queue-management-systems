//
//  main.cpp
//  Packet Queuing and Dropping in Routers
//
//  Created by Ch Muhammad Wahab on 05/12/2020.
//  Copyright © 2020 Ch Muhammad Wahab. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace  std;
void display(queue<int> q){
    q.reverse();
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}
int main(int argc, const char * argv[]) {
    cout<<"Packet Queuing and Dropping in Routers\n";
    float ram; int x=0,y=0,z=0;
    cout<<"Input RAM size[GB]:";cin>>ram;
    ram=(ram/3)*1024;
    cout<<ram;
    queue<int> hq(ram),mq(ram),lq(ram);
    while(1){
    cout<<"1-Incoming Pakage\n"
          "2-Outbound Pakage\n"
          "3-Queued Packets in router buffer\n_";
    cout<<endl;
        int c;cin>>c;
        switch (c) {
            case 1:
                if(!hq.full())
                    hq.push(++x);
                else if(!mq.full())
                    mq.push(++y);
                else
                {
                    try {
                        lq.push(++z);
                    } catch (const char* err) {
                        cout<<err;
                    }
                }
                break;
            case 2:
                if(!hq.empty())
                    hq.pop();
                else if(!mq.empty())
                    mq.pop();
                else
                {
                    try {
                        lq.pop();
                    } catch (const char* err) {
                        cout<<err;
                    }
                }
                break;
            case 3:
                cout<<"Packets in High Priority queue\n";display(hq);
                cout<<"Packets in Medium Priority queue\n";display(mq);
                cout<<"Packets in Low Priority queue\n";display(lq);
                break;
            default:
                break;
        }
    }

}
