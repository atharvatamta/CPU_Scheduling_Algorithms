#include<bits/stdc++.h>
using namespace std;

//SRTF ALgorithm

class Process{
public:
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    bool isready; //true if it's present in ready_queue

    Process(int i,int j,int k){
        pid=i;
        at=j;
        bt=k;
        ct=-1;
        tat=-1;
        wt=-1;
        rt=k;
        isready=false;
    }


};

//custom comparator function for priority_queue 
class Compare{
public:
    bool operator()(Process* p1,Process* p2){
         if(p1->rt>p2->rt)return true;
        if(p1->rt==p2->rt){
           if(p1->at>p2->at)return true;
            if(p1->at==p2->at){
            if(p1->pid>p2->pid)return true;
     }
    }
    return false;
    }
};

bool cmp_at(Process* p1,Process* p2){
   if(p1->at>p2->at)return false;
   if(p1->at==p2->at){
     if(p1->pid>p2->pid)return false;
   }
   return true; 
}

void generateParams(vector<Process*>&process){
    for(int i=0;i<process.size();i++){
        process[i]->tat=process[i]->ct-process[i]->at;
        process[i]->wt=process[i]->tat-process[i]->bt;
    }

}


void srtf(vector<Process*>&process){
   sort(process.begin(),process.end(),cmp_at);
   priority_queue<Process*,vector<Process*>,Compare>ready;

   int timer=process[0]->at;
   int k=0;

    cout<<"GANTT-CHART->"<<endl;
   cout<<"````````"<<endl;
   cout<<"Pid"<<setw(5)<<"S.T"<<setw(5)<<"E.T"<<endl;
   cout<<"---------------"<<endl;
    
   while(k<process.size()){
       if(process[k]->at==timer){
         ready.push(process[k]);
         process[k]->isready=true;
         k++;
       }else break;
   }
   
   
   while(!ready.empty()){
       auto execution=ready.top();
       ready.pop();
       int temp=timer;
       timer++;
       execution->rt--;
       execution->isready=false;
       if(execution->rt==0){
        execution->ct=timer;
       }

       cout<<execution->pid<<setw(6)<<temp<<setw(6)<<timer<<endl;

       for(int l=0;l<process.size();l++){
         if(process[l]->isready)continue;
         if(process[l]->at<=timer){
            if(process[l]->rt>0){
                ready.push(process[l]);
                process[l]->isready=true;
            }
         }else break;
       }

   }

   cout<<endl<<endl;

   generateParams(process);

   int schedule=0;
   int tt=0;
   int wt=0;
   for(auto i:process){
      schedule=max(schedule,i->ct);
      tt+=i->tat;
      wt+=i->wt;
   }

   schedule-=process[0]->at;
   int width=5;
   cout<<"Process Attributes->"<<endl;
   cout<<"````````````"<<endl;
   cout<<"Pid"<<setw(width)<<"A.T"<<setw(width)<<"B.T"<<setw(width)<<"C.T"<<setw(7)<<"T.A.T"<<setw(width)<<"W.T"<<endl;
   cout<<setw(width)<<setfill('-')<<"---"<<setw(width)<<"----"<<setw(width)<<"----"<<setw(width)<<"---------------"<<setfill(' ')<<endl;

   for(auto i:process){
    cout<<i->pid<<setw(width+1)<<i->at<<setw(width)<<i->bt<<setw(width+1)<<i->ct<<setw(width+1)<<i->tat<<setw(width)<<i->wt<<endl;
   }
   cout<<endl;
   cout<<"AVERAGE T.A.T -> "<<(float)tt/process.size()<<endl;
   cout<<"AVERAGE W.T -> "<<(float)wt/process.size()<<endl;
   cout<<"Scheduling Length -> "<<schedule<<endl;
}
 
int main(){
    int n;
    cin>>n;
    vector<Process*>process;
    for(int i=0;i<n;i++){
        int pid,at,bt;
        cin>>pid>>at>>bt;
        Process*p1=new Process(pid,at,bt);
        process.push_back(p1);
    }

    srtf(process);
    
    return 0;
}
