#include<bits/stdc++.h>
using namespace std;

//ROUND-ROBIN ALGORITHM
class Process{
public:
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    bool isready;

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

//comparator function for custom sorting
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


void Round_Robin(vector<Process*>&process,int quantum){
    sort(process.begin(),process.end(),cmp_at);
    queue<Process*>ready;

    cout<<"GANTT-CHART->"<<endl;
    cout<<"````````"<<endl;
    cout<<"Pid"<<setw(5)<<"S.T"<<setw(5)<<"E.T"<<endl;
    cout<<"---------------"<<endl;
	
    int timer=process[0]->at;
    for(int i=0;i<process.size();i++){
    	if(process[i]->at>timer)break;
    	ready.push(process[i]);
    	process[i]->isready=true;
    }

    while(!ready.empty()){
    	auto execution=ready.front();
    	ready.pop();
    	execution->isready=false;
        int temp=timer;
    	if(execution->rt>quantum){
          timer+=quantum;
          execution->rt-=quantum;
    	}
        else if(execution->rt<=quantum){
            timer+=execution->rt;
            execution->rt=0;
            execution->ct=timer;
        }

       cout<<execution->pid<<setw(6)<<temp<<setw(6)<<timer<<endl;

        
        for(int l=0;l<process.size();l++){
        	if(process[l]->isready||process[l]==execution)continue;
        	if(process[l]->at<=timer){
                if(process[l]->rt>0){
        		ready.push(process[l]);
        		process[l]->isready=true;
             }
        	}else break;
        }

        if(execution->rt>0){
        	ready.push(execution);
        	execution->isready=true;
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
	int n,tq;
	cin>>n>>tq;
	vector<Process*>process;
	for(int i=0;i<n;i++){
		int id,at,bt;
		cin>>id>>at>>bt;
		Process* p1=new Process(id,at,bt);
		process.push_back(p1);
	}
    
    Round_Robin(process,tq);

	return 0;
}
