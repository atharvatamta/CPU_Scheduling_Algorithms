#include<bits/stdc++.h>
using namespace std;

//Non-preemptive Priority Scheduling

class Process{
public:
	int pid;
	int at;
	int bt;
	int priority;
	int ct;
	int rt;
	int tat;
	int wt;
	bool isready;

	Process(int i,int j,int k,int l){
		pid=i;
		at=j;
		bt=k;
		priority=l;
		ct=-1;
		tat=-1;
		wt=-1;
		isready=false;
		rt=k;
	}

};

//custom comparator for sorting
bool cmp_at(Process* p1,Process* p2){
   if(p1->at>p2->at)return false;
   if(p1->at==p2->at){
     if(p1->pid>p2->pid)return false;
   }
   return true; 
}

//custom comparator for priority queue
class Compare{
public:
	bool operator()(Process*p1,Process*p2){
		if(p1->priority<p2->priority)return true;
		if(p1->priority==p2->priority){
			if(p1->at>p2->at)return true;
            if(p1->at==p2->at){
            if(p1->pid>p2->pid)return true;
     }
		}
		return false;
	}
};

void generateParams(vector<Process*>&process){
    for(int i=0;i<process.size();i++){
        process[i]->tat=process[i]->ct-process[i]->at;
        process[i]->wt=process[i]->tat-process[i]->bt;
    }

}

void Non_Pre_Priority(vector<Process*>&process){
	sort(process.begin(),process.end(),cmp_at);
	priority_queue<Process*,vector<Process*>,Compare>ready;
   
	int timer=process[0]->at;
	cout<<"GANTT-CHART->"<<endl;
        cout<<"````````"<<endl;
   	cout<<"Pid"<<setw(5)<<"S.T"<<setw(5)<<"E.T"<<endl;
   	cout<<"---------------"<<endl;
  
   	for(int i=0;i<process.size();i++){
   	 	if(process[i]->at>timer)break;
   	 	ready.push(process[i]);
   	 	process[i]->isready=true;
   	}

   while(!ready.empty()){
   	 auto execution=ready.top();
   	 ready.pop();
	   int temp=timer;
   	 timer+=execution->bt;
   	 execution->rt=0;
   	 execution->ct=timer;

   	 cout<<execution->pid<<setw(6)<<temp<<setw(6)<<execution->ct<<endl;

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

   schedule=schedule-process[0]->at;
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
        int pid,at,bt,priority;
        cin>>pid>>at>>bt>>priority;
        Process*p1=new Process(pid,at,bt,priority);
        process.push_back(p1);
    }

    Non_Pre_Priority(process);

    return 0;

}
