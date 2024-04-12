#include<bits/stdc++.h>
using namespace std;

//Return (pid,time)

vector<pair<int,int>>FCFS(vector<pair<pair<int,int>,int>>&process,int n){
       sort(process.begin(),process.end());
       map<int,vector<int>>param;  //(pid,(at,bt,ct,tat,wt))
       for(auto i:process){
        param[i.first.second].push_back(i.first.first);
        param[i.first.second].push_back(i.second);
       }
       vector<pair<int,int>>gant;
       int time=0;
       for(auto i:process){
          if(i.first.first>time){
             while(i.first.first<time){
                time++;
            }
            time+=i.second;
            gant.push_back({i.first.second,time});

          }else{
            time+=i.second;
             gant.push_back({i.first.second,time});
          }
       }

       for(auto i:gant){
          param[i.first].push_back(i.second);
       }
       for(auto i:param){
         int TT=i.second[2]-i.second[0];
         param[i.first].push_back(TT);
       }
       for(auto i:param){
         int CT=i.second[3]-i.second[1];
         param[i.first].push_back(CT);
       }
       cout<<"DATA TABLE"<<endl;
       cout<<"Pid"<<"  "<<"A.T"<<"  "<<"B.T"<<"  "<<"C.T"<<"  "<<"T.A.T"<<"  "<<"W.T"<<endl;
       
       for(auto i:param){
         cout<<i.first<<"   ";
         for(auto j:i.second){
            cout<<j<<"    ";
         }
         cout<<endl;
       }
       cout<<endl;
       
       float wt=0;
       float TAT=0;
       int schedule=0;
       for(auto i:param){
          wt+=i.second[4];
          TAT+=i.second[3];
          schedule=max(schedule,i.second[2]);
       }
       wt=(float)wt/n;
       TAT=(float)TAT/n;
       
       cout<<"Average T.A.T -->"<<TAT<<endl;
       cout<<"Average W.T -->"<<wt<<endl;
       cout<<"Scheduling Time -->"<<schedule<<endl;
     
     return gant;

}

int main()
{   
    //Case-1
    // vector<pair<pair<int,int>,int>>process={
    //     {{0,1},30},{{0,2},5},{{0,3},5}
    // }; //((arrival,pid),(BT))
    
    
    //Case-2
    vector<pair<pair<int,int>,int>>process;
    int n;
    // cout<<"enter the no. of process"<<endl;
    cin>>n;
    int temp=n;

    while(n--){
        // cout<<"Enter the pid,arrival,bt"<<endl;
        int pid;
        int arrival;
        int bt;
        cin>>pid>>arrival>>bt;
        pair<pair<int,int>,int>p={{arrival,pid},bt};
        process.push_back(p); 
    }

    
    vector<pair<int,int>>res=FCFS(process,temp);

    //FOR PRINTING GANTT CHART
    
    cout<<endl<<"Gant Chart"<<endl;
    for(auto i:res){
        cout<<i.first<<" | ";
    }    
    return 0;
}
