//
//  main.cpp
//  P3_04071913024_MuhammadWahab_A4
//
//  Created by Ch Muhammad Wahab on 4/12/2020.
//  Copyright © 2020 Ch Muhammad Wahab. All rights reserved.
//

#include <iostream>
#include<fstream>
#include"Header.h"
using namespace std;
void display(queue<person> q){
    if(q.empty()){
        cout<<"No applicant found\n";
    }
    while (!q.empty()) {
            person obj=q.front();
            cout<<obj;
            q.pop();
        }
}
void menu2()
{
    cout<<"Select type of licence\n"
    "1-Mototcar\n"
    "2-Mototcar/Jeep/Car\n"
    "3-LTV\n"
    "4-HTV\n"
    "5-PSV\n"
    "_";
}
int main(int argc, const char * argv[]) {
    person pr[6];
    queue<person> licence[6];
    queue<person> renew[6];
    cout<<"Driving Licence Authority\n\n";
    while(1){
          cout<<"1-Want a new licence\n"
                "2-Renew exiting licence\n"
                "3-Visit waiting Queue\n"
                "4-Cancel application \n"
                "_";
        int c;cin>>c;
        switch (c) {
            case 1:
                menu2();
                cin>>c;
                pr[c].assignday(c);
                cin>>pr[c];
                licence[c].push(pr[c]);
                break;
            case 2:
                menu2();
                cin>>c;
                pr[c].assignday(c);
                cin>>pr[c];
                renew[c].push(pr[c]);
                break;
            case 3:
                cout<<"1-New Licence Applicant\n2-Renew Licence Applicant\n_";
                cin>>c;
                if(c==1){
                    menu2();
                    cin>>c;
                    display(licence[c]);
                }
                else if(c==2){
                    menu2();
                    cin>>c;
                    display(renew[c]);
                }
                else{
                    cout<<"Wrong choice\n";
                }
                break;
            case 4:
                 cout<<"1-New Licence Applicant\n2-Renew Licence Applicant\n_";
                cin>>c;
                if(c==1){
                    menu2();
                    cin>>c;
                    cout<<"Enter token no:";
                    int val;cin>>val;
                    licence[c].remove(val);
                }
                else if(c==2){
                    menu2();
                    cin>>c;
                    cout<<"Enter token no:";
                    int val;cin>>val;
                    renew[c].remove(val);
                }
                else{
                    cout<<"Wrong choice\n";
                }
                break;
            default:
                cout<<"Invalid choice\n";
                break;
        }
      
    }

}
