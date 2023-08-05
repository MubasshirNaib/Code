#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


class shd
{
public:
    int bt,at,tat,wt,rt,finish;
};

struct tup{
    double avgresp,avgtat,avgwt;
};

struct Process
{
    int processId, arrivalTime, burstTime, waitingTime, turnaroundTime, remainingTime;
};

void sortArrivalTime(struct Process a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].arrivalTime > a[j].arrivalTime)
            {
                swap(a[i], a[j]);
            }
        }
    }
}


void FCFS(int,vector<pair<pair<int,int>,int> > );
void SJFPreemptive(int,vector<pair<pair<int,int>,int> > );
void SJFNonPreemptive(int,vector<pair<pair<int,int>,int> > );
void NonPremPriority(int,vector<pair<pair<int,int>,int> > );
void PreemptivePriority(int,vector<pair<pair<int,int>,int> > );
void RoundRobin(int,vector<pair<pair<int,int>,int> >,int);
void PriorityRobin(int,vector<pair<pair<int,int>,int> >,int);

tup FCFS2(int,vector<pair<pair<int,int>,int> > );
tup SJFPreemptive2(int,vector<pair<pair<int,int>,int> > );
tup SJFNonPreemptive2(int,vector<pair<pair<int,int>,int> > );
tup NonPremPriority2(int,vector<pair<pair<int,int>,int> > );
tup PreemptivePriority2(int,vector<pair<pair<int,int>,int> > );
tup RoundRobin2(int,vector<pair<pair<int,int>,int> >,int);
tup PriorityRobin2(int,vector<pair<pair<int,int>,int> >,int);

int main()
{
    int choice ;
    while(1)
    {
        cout<<"Enter Your Choice:"<<endl;
        cin>>choice;
        if(choice==9)
        {
            return 0;
        }
        int n;
        if(choice==1||choice==2||choice==3)
        {

            cout<<"Enter no. of processes\n";
            cin>>n;
            vector<pair<pair<int,int>,int> > vec(n);
            for(int i=0; i<n; i++)
            {
                cout<<"Enter The Burst Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.first;
                cout<<"Enter The Arrival Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.second;
            }
            if(choice==1)
            {
                FCFS(n,vec);
            }
            else if(choice==2)
            {
                SJFNonPreemptive(n,vec);
            }
            else
            {
                SJFPreemptive(n,vec);
            }
        }
        else if(choice == 4||choice == 5)
        {
            cout<<"Enter no. of processes\n";
            cin>>n;
            vector<pair<pair<int,int>,int> > vec(n);
            for(int i=0; i<n; i++)
            {
                cout<<"Enter The Burst Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.first;
                cout<<"Enter The Arrival Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.second;
                cout<<"Enter the priority of Process P"<<i<<": "<<endl;
                cin>>vec[i].second;
            }
            if(choice == 4)
            {
                NonPremPriority(n,vec);
            }
            else
            {
                PreemptivePriority(n,vec);
            }

        }
        else if(choice==6)
        {
            cout<<"Enter no. of processes\n";
            cin>>n;
            vector<pair<pair<int,int>,int> > vec(n);
            for(int i=0; i<n; i++)
            {
                cout<<"Enter The Burst Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.first;
                cout<<"Enter The Arrival Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.second;
            }
            int timeQuantum;
            cout << "Enter the time quantum: " << endl;
            cin >> timeQuantum;
            RoundRobin(n,vec,timeQuantum);

        }
        else if(choice == 7){
            cout<<"Enter no. of processes\n";
            cin>>n;
            vector<pair<pair<int,int>,int> > vec(n);
            for(int i=0; i<n; i++)
            {
                cout<<"Enter The Burst Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.first;
                cout<<"Enter The Arrival Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.second;
                cout<<"Enter the priority of Process P"<<i+1<<": "<<endl;
                cin>>vec[i].second;
            }
            int timeQuantum;
            cout << "Enter the time quantum: " << endl;
            cin >> timeQuantum;
            RoundRobin(n,vec,timeQuantum);
        }
        else{
            cout<<"Enter no. of processes\n";
            cin>>n;
            vector<pair<pair<int,int>,int> > vec(n);
            for(int i=0; i<n; i++)
            {
                cout<<"Enter The Burst Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.first;
                cout<<"Enter The Arrival Time of Process P"<<i+1<<":"<<endl;
                cin>>vec[i].first.second;
                cout<<"Enter the priority of Process P"<<i+1<<": "<<endl;
                cin>>vec[i].second;
            }
            int timeQuantum;
            cout << "Enter the time quantum: " << endl;
            cin >> timeQuantum;
            tup fcfs,nprsjf,prsjf,nppr,prpr,round,own;
            fcfs=FCFS2(n,vec);
            nprsjf=SJFNonPreemptive2(n,vec);
            prsjf=SJFPreemptive2(n,vec);
            nppr=NonPremPriority2(n,vec);
            prpr=PreemptivePriority2(n,vec);
            round=RoundRobin2(n,vec,timeQuantum);
            own=PriorityRobin2(n,vec,timeQuantum);
            cout<<"Algo: FCFS                     Avg Response T.:"<<fcfs.avgresp<<" Avg Waiting T.: "<<fcfs.avgwt<<" Avg. Turnaround T: "<<fcfs.avgtat<<endl;
            cout<<"Algo: Non-Preemptive-SJF       Avg Response T.:"<<nprsjf.avgresp<<" Avg Waiting T.: "<<nprsjf.avgwt<<" Avg. Turnaround T: "<<nprsjf.avgtat<<endl;
            cout<<"Algo: Preemptive-SJF           Avg Response T.:"<<prsjf.avgresp<<" Avg Waiting T.: "<<prsjf.avgwt<<" Avg. Turnaround T: "<<prsjf.avgtat<<endl;
            cout<<"Algo: Non-Preemptive-Priority  Avg Response T.:"<<nppr.avgresp<<" Avg Waiting T.: "<<nppr.avgwt<<" Avg. Turnaround T: "<<nppr.avgtat<<endl;
            cout<<"Algo: Preemptive-Priority      Avg Response T.:"<< prpr.avgresp<<" Avg Waiting T.: "<< prpr.avgwt<<" Avg. Turnaround T: "<< prpr.avgtat<<endl;
            cout<<"Algo: Round-Robin              Avg Response T.:"<<round.avgresp<<" Avg Waiting T.: "<<round.avgwt<<" Avg. Turnaround T: "<<round.avgtat<<endl;
            cout<<"Algo: Own-Algorithm            Avg Response T.:"<<own.avgresp<<" Avg Waiting T.: "<<own.avgwt<<" Avg. Turnaround T: "<<own.avgtat<<endl;
        }
    }

}

//FCFS

void FCFS(int n,vector<pair<pair<int,int>,int> > vec )
{

    int numProcesses=n;

    vector<pair<pair<int, int>, int>> processInfo(numProcesses);
    for(int i = 0; i < numProcesses; i++)
    {
        processInfo[i].first.second=vec[i].first.first;
        processInfo[i].first.first=vec[i].first.second;
        processInfo[i].second = i + 1;
    }
    sort(processInfo.begin(), processInfo.end());

    vector<pair<int, int>> executionOrder;
    vector<pair<int, int>> delay;
    int currentTime = 0;
    for(int i = 0; i < numProcesses; i++)
    {
        int arrivalTime = processInfo[i].first.first;
        int burstTime = processInfo[i].first.second;
        if(arrivalTime <= currentTime)
        {
            executionOrder.push_back({currentTime, processInfo[i].second});
            delay.push_back({currentTime - arrivalTime, processInfo[i].first.second});
            currentTime += processInfo[i].first.second;
        }
        else
        {
            delay.push_back({arrivalTime - currentTime, processInfo[i].first.second});
            executionOrder.push_back({arrivalTime, processInfo[i].second});
            currentTime = arrivalTime + processInfo[i].first.second;
        }
    }
    cout << "Gantt Chart: " << endl;
    double avgTurnaroundTime = 0, avgDelayTime = 0;
    vector<int> turnaround(numProcesses);
    for(int i = 0; i < numProcesses; i++)
    {
        cout << executionOrder[i].first << " P" << executionOrder[i].second << " ";
        turnaround[i] = delay[i].first + delay[i].second;
        avgTurnaroundTime += turnaround[i];
        avgDelayTime += delay[i].first;
    }
    cout << endl;
    for(int i = 0; i < numProcesses; i++)
    {
        cout << "Process: " << "P" << executionOrder[i].second << " Start time: " << executionOrder[i].first << " " << "Waiting time: " << delay[i].first << " " << "Turnaround time: " << turnaround[i] << endl;
    }
    cout << "Average waiting time: " << avgDelayTime / numProcesses << endl;
    cout << "Average turnaround time: " << avgTurnaroundTime / numProcesses << endl;
}

//SJF Preemptive

void SJFPreemptive(int n,vector<pair<pair<int,int>,int> > vec)
{
    double twt,ttat,total,tresptime=0;
    shd arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i].bt=vec[i].first.first,arr[i].at=vec[i].first.second;
    }
    total=0;
    twt=0;
    ttat=0;
    for(int i=0; i<n; i++)
    {
        arr[i].rt=arr[i].bt;
        arr[i].finish=0;
        arr[i].wt=0;
        arr[i].tat=0;
        total+=arr[i].bt;
    }
    int time,next=0,old,i;
    cout<<"Gantt Chart: \n";
    vector<int > starttime(n+1);
    for(time=0; time<total; time++)
    {
        old=next;

        int i,low;
        for(i=0; i<n; i++)
            if(arr[i].finish==0)
            {
                low=i;
                break;
            }
        for(i=0; i<n; i++)
            if(arr[i].finish!=1)
                if(arr[i].rt<arr[low].rt && arr[i].at<=time)
                    low=i;
        next =low;
        if(old!=next || time==0)
        {
            cout<<time<<" P"<<next+1<<" ";
            if(starttime[next+1]==0)
            {
                starttime[next+1]=time;
            }

        }


        arr[next].rt=arr[next].rt-1;
        if(arr[next].rt==0)
        {
            arr[next].finish=1;
        }
        for(i=0; i<n; i++)
            if(i!=next && arr[i].finish==0 && arr[i].at<=time)
                arr[i].wt++;
    }
    cout<<endl;
    cout<<endl;



    for(int i=0; i<n; i++)
    {
        twt+=arr[i].wt;
        arr[i].tat=arr[i].wt+arr[i].bt;
        ttat+=arr[i].tat;
        cout<<"Process: P"<<i+1<<" Start Time:   "<<starttime[i+1]<<" Waiting Time: "<<arr[i].wt<<" Turnaround Time: "<<arr[i].tat<<" Response Time: "<<starttime[i+1]-arr[i].at<<endl;
//        cout<<"Waiting time for P"<<(i+1)<<" = "<<arr[i].wt<<", Turnaround time = "<<arr[i].tat<<endl;
        tresptime+=(starttime[i+1]-arr[i].at);
    }
    cout<<endl;
    cout<<"Avg Waiting time = "<<(double)twt/n<<endl;
    cout<<"Avg. Turnaround time = "<<(double)ttat/n<<endl;
    cout<<"Avg Response time = "<<tresptime/n<<endl;

}


//SJF Non-Preemptive

void SJFNonPreemptive(int n,vector<pair<pair<int,int>,int> > vec)
{
    int numProcesses, totalTurnaroundTime = 0, totalWaitingTime = 0;
    numProcesses=n;
    int arrivalTime[numProcesses], burstTime[numProcesses + 1], totalBurstTime = 0;
    for (int i = 0; i < numProcesses; ++i)
    {
        burstTime[i]=vec[i].first.first;
        totalBurstTime += burstTime[i];
        arrivalTime[i]=vec[i].first.second;
    }
    burstTime[numProcesses] = 9999;
    int currentTime, smallest;
    vector< pair<int,  pair<int, int>>> processDetails;
    vector<int> processId;
    for (currentTime = 0; currentTime < totalBurstTime;)
    {
        smallest = numProcesses;
        for (int i = 0; i < numProcesses; i++)
        {
            if (arrivalTime[i] <= currentTime && burstTime[i] > 0 && burstTime[i] < burstTime[smallest])
                smallest = i;
        }
        cout << currentTime << " P" << smallest + 1 << " ";
        processId.push_back(smallest + 1);
        int startTime = currentTime, waitingTime = currentTime - arrivalTime[smallest], turnaroundTime = currentTime + burstTime[smallest] - arrivalTime[smallest];
        processDetails.push_back({startTime, {waitingTime, turnaroundTime}});
        totalTurnaroundTime += currentTime + burstTime[smallest] - arrivalTime[smallest];
        totalWaitingTime += currentTime - arrivalTime[smallest];
        currentTime += burstTime[smallest];
        burstTime[smallest] = 0;
    }
    cout <<  endl;
    for (int i = 0; i < processDetails.size(); ++i)
    {
        int startTime = processDetails[i].first, waitingTime = processDetails[i].second.first, turnaroundTime = processDetails[i].second.second;
        cout << "Process P" << processId[i] << " - Start time: " << startTime << ", Waiting time: " << waitingTime << ", Turnaround time: " << turnaroundTime <<  endl;
    }
    cout << "Average waiting time = " << totalWaitingTime * 1.0 / numProcesses << endl;
    cout << "Average turnaround time = " << totalTurnaroundTime * 1.0 / numProcesses <<endl;
    return ;
}


void NonPremPriority(int val,vector<pair<pair<int,int>,int> > vec )
{

    long long int n=val;
    vector<long long int>a(n+5),b(n+5),ind(n+5),pr(n+5);
    long long int i,t=0,mn=LLONG_MAX,k;
    vector<long long int>st,wa,tu;
    for(i=1; i<=n; i++)
    {

        b[i]=vec[i-1].first.first;
        a[i]=vec[i-1].first.second;

        pr[i]=vec[i-1].second;
        ind[i]=i;
        if(mn>a[i])
        {
            mn=a[i];
            k=i;
        }
        t+=b[i];
    }
    double s1=0.0,s2=0.0;
    swap(a[1],a[k]);
    swap(b[1],b[k]);
    swap(ind[1],ind[k]);
    swap(pr[1],pr[k]);
    s2+=b[1];
    st.push_back(0);
    wa.push_back(0);
    tu.push_back(b[1]);
    cout<<"Sample Output:"<<endl;
    cout<<"Gantt Chart"<<endl;
    cout<<0<<" P"<<ind[1];
    k=b[1];
    long long int y=2,j;
    for(; k<t;)
    {
        mn=LLONG_MAX;
        for(i=y; i<=n; i+=1)
        {
            if(a[i]<=k)
            {
                if(mn>pr[i])
                {
                    mn=pr[i];
                    j=i;
                }
            }
        }
        cout<<" "<<k;
        st.push_back(k);
        long long int wat=k-a[j];
        s1+=wat;
        long long int tur=wat+b[j];
        s2+=tur;
        wa.push_back(wat);
        tu.push_back(tur);
        k+=b[j];
        swap(a[y],a[j]);
        swap(b[y],b[j]);
        swap(ind[y],ind[j]);
        swap(pr[y],pr[j]);
        cout<<" P"<<ind[y];
        y++;
        if(y>n)
        {
            break;
        }

    }
    cout<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"Process : p"<<ind[i+1]<<" Start time: "<<st[i]<<" Waiting time: "<<wa[i]<<" Turnaround time: "<<tu[i]<<endl;
    }
    cout<<"Average waiting time: "<<s1/n<<endl;
    cout<<"Average turnover time: "<<s2/n<<endl;
}



void PreemptivePriority(int val,vector<pair<pair<int,int>,int> > vec )
{
    ll n;

    n=val;
    vector<ll>a(n+5),b(n+5),bb(n+5),ind(n+5),pr(n+5);
    ll i,t=0,mn=LLONG_MAX,k;
    for(i=1; i<=n; i++)
    {
        b[i]=vec[i-1].first.first;
        a[i]=vec[i-1].first.second;

        pr[i]=vec[i-1].second;

        t+=b[i];
    }
    bb=b;
    ll tq=1;
    k=0;
    ll y,j,kk=-1,pp=0;
    vector<ll>g,s;
    ll prev=-1;
    for(; k<t;)
    {
        mn=LLONG_MAX;
        for(i=1; i<=n; i++)
        {
            if(a[i]<=k&&b[i]>0)
            {
                if(mn>pr[i])
                {
                    mn=pr[i];
                    j=i;
                }
            }
        }
        if(prev!=j)
        {
            g.push_back(j);
            s.push_back(k);
            prev=j;
        }
        //cout<<k<<" "<<"P"<<j<<" ";
        k+=min(b[j],tq);
        b[j]-=min(b[j],tq);
        if(b[j]<=0)pp++;
    }
    cout<<"Gantt Chart"<<endl;
    for(i=0; i<g.size(); i++)
    {
        cout<<s[i]<<" "<<"P"<<g[i]<<" ";
    }

    cout<<t<<endl;
    s.push_back(t);
    double tr=0.0,tw=0.0,tt=0.0;
    for(i=1; i<=n; i++)
    {
        cout<<"Process: P"<<i<<" Start time: ";
        ll stt,enn;
        for(j=0; j<g.size(); j++)
        {
            if(g[j]==i)
            {
                stt=s[j];
                break;
            }
        }
        for(j=g.size()-1; j>=0; j--)
        {
            if(g[j]==i)
            {
                enn=s[j+1];
                break;
            }
        }
        cout<<stt<<" End time: "<<enn<<" Response time: ";
        cout<<stt-a[i]<<" Waiting time: "<<enn-a[i]-bb[i];
        cout<<" Turnaround time: "<<enn-a[i]<<endl;
        tr+=(stt-a[i]);
        tw+=(enn-a[i]-bb[i]);
        tt+=(enn-a[i]);
    }
    cout<<setprecision(2)<<fixed;
    cout<<"Average Response Time: "<<tr/n<<endl;
    cout<<"Average Waiting Time: "<<tw/n<<endl;
    cout<<"Average Turnaround Time: "<<tt/n<<endl;
}


void RoundRobin(int sz,vector<pair<pair<int,int>,int> > vec,int TQ)
{
    int i, j, n, time, remainingProcesses, flag = 0, timeQuantum;
    struct Process processes[100];
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    n=sz;
    int totalBurstTime = 0;
    remainingProcesses = n;

    for (i = 0; i < n; i++)
    {

        processes[i].burstTime=vec[i].first.first;
        processes[i].arrivalTime=vec[i].first.second;
        processes[i].processId = i;
        processes[i].remainingTime = processes[i].burstTime;
        totalBurstTime += processes[i].burstTime;
    }

    sortArrivalTime(processes, n);


    timeQuantum=TQ;

    cout << "Gantt Chart" << endl;

    vector<int> timeline(n + 1, 0);

    cout << "0 ";
    for (time = 0, i = 0; remainingProcesses != 0;)
    {
        if (processes[i].remainingTime <= timeQuantum && processes[i].remainingTime > 0)
        {
            time += processes[i].remainingTime;
            if (timeline[processes[i].processId] == 0)
            {
                timeline[processes[i].processId] = time;
            }
            cout << "P" << processes[i].processId + 1 << " ";
            if (time != totalBurstTime)
            {
                cout << time << " ";
            }

            processes[i].remainingTime = 0;
            flag = 1;
        }
        else if (processes[i].remainingTime > 0)
        {
            processes[i].remainingTime -= timeQuantum;
            time += timeQuantum;
            if (timeline[processes[i].processId] == 0)
            {
                timeline[processes[i].processId] = time;
            }
            cout << "P" << processes[i].processId + 1 << " ";
            if (time != totalBurstTime)
            {
                cout << time << " ";
            }
        }
        if (processes[i].remainingTime == 0 && flag == 1)
        {
            remainingProcesses--;
            processes[i].turnaroundTime = time - processes[i].arrivalTime;
            processes[i].waitingTime = time - processes[i].arrivalTime - processes[i].burstTime;
            avgWaitingTime += time - processes[i].arrivalTime - processes[i].burstTime;
            avgTurnaroundTime += time - processes[i].arrivalTime;
            flag = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (processes[i + 1].arrivalTime <= time)
            i++;
        else
            i = 0;
    }
    cout << endl;

    double avgResponseTime = 0;
    for (i = 0; i < n; i++)
    {
        cout << "Process: " << processes[i].processId + 1 << " Start Time: " << timeline[processes[i].processId]
             << " Waiting Time: " << processes[i].waitingTime << " Turnaround Time: " << processes[i].turnaroundTime
             << " Response Time: " << timeline[processes[i].processId] - processes[i].arrivalTime << endl;
        avgResponseTime += (timeline[processes[i].processId] - processes[i].arrivalTime);
    }

    avgWaitingTime = avgWaitingTime / n;
    avgResponseTime /= n;
    avgTurnaroundTime = avgTurnaroundTime / n;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Response Time: " << avgResponseTime << endl;

    return ;
}


void PriorityRobin(int sz,vector<pair<pair<int,int>,int> > vec,int TQ)
{
    ll n;
    n=sz;
    vector<ll>a(n+5),b(n+5),bb(n+5),ind(n+5),pr(n+5);
    ll i,t=0,mn=LLONG_MAX,k;
    for(i=1; i<=n; i++)
    {
        b[i]=vec[i].first.first;
        a[i]=vec[i].first.second;
        pr[i]=vec[i].second;
        t+=b[i];
    }
    bb=b;
    ll tq;
    tq=TQ;
    k=0;
    ll y,j,kk=-1,pp=0;
    vector<ll>g,s;
    cout<<"Gantt Chart"<<endl;
    for(; k<t;)
    {
        mn=LLONG_MAX;
        for(i=1; i<=n; i++)
        {
            if(a[i]<=k&&b[i]>0&&i!=kk)
            {
                if(mn>pr[i])
                {
                    mn=pr[i];
                    j=i;
                }
            }
        }
        cout<<k<<" "<<"P"<<j<<" ";
        g.push_back(j);
        s.push_back(k);
        k+=min(b[j],tq);
        b[j]-=min(b[j],tq);
        kk=j;
        if(b[j]<=0)pp++;
    }
    cout<<t<<endl;
    s.push_back(t);
    double tr=0.0,tw=0.0,tt=0.0;
    for(i=1; i<=n; i++)
    {
        cout<<"Process: P"<<i<<" Start time: ";
        ll stt,enn;
        for(j=0; j<g.size(); j++)
        {
            if(g[j]==i)
            {
                stt=s[j];
                break;
            }
        }
        for(j=g.size()-1; j>=0; j--)
        {
            if(g[j]==i)
            {
                enn=s[j+1];
                break;
            }
        }
        cout<<stt<<" End time: "<<enn<<" Response time: ";
        cout<<stt-a[i]<<" Waiting time: "<<enn-a[i]-bb[i];
        cout<<" Turnaround time: "<<enn-a[i]<<endl;
        tr+=(stt-a[i]);
        tw+=(enn-a[i]-bb[i]);
        tt+=(enn-a[i]);
    }
    cout<<setprecision(2)<<fixed;
    cout<<"Average Response Time: "<<tr/n<<endl;
    cout<<"Average Waiting Time: "<<tw/n<<endl;
    cout<<"Average Turnaround Time: "<<tt/n<<endl;
}



tup FCFS2(int n,vector<pair<pair<int,int>,int> > vec )
{

    int numProcesses=n;

    vector<pair<pair<int, int>, int>> processInfo(numProcesses);
    for(int i = 0; i < numProcesses; i++)
    {
        processInfo[i].first.second=vec[i].first.first;
        processInfo[i].first.first=vec[i].first.second;
        processInfo[i].second = i + 1;
    }
    sort(processInfo.begin(), processInfo.end());

    vector<pair<int, int>> executionOrder;
    vector<pair<int, int>> delay;
    int currentTime = 0;
    for(int i = 0; i < numProcesses; i++)
    {
        int arrivalTime = processInfo[i].first.first;
        int burstTime = processInfo[i].first.second;
        if(arrivalTime <= currentTime)
        {
            executionOrder.push_back({currentTime, processInfo[i].second});
            delay.push_back({currentTime - arrivalTime, processInfo[i].first.second});
            currentTime += processInfo[i].first.second;
        }
        else
        {
            delay.push_back({arrivalTime - currentTime, processInfo[i].first.second});
            executionOrder.push_back({arrivalTime, processInfo[i].second});
            currentTime = arrivalTime + processInfo[i].first.second;
        }
    }

    double avgTurnaroundTime = 0, avgDelayTime = 0;
    vector<int> turnaround(numProcesses);
    for(int i = 0; i < numProcesses; i++)
    {

        turnaround[i] = delay[i].first + delay[i].second;
        avgTurnaroundTime += turnaround[i];
        avgDelayTime += delay[i].first;
    }
    tup tmp;
    tmp.avgresp=avgDelayTime / numProcesses,tmp.avgwt=avgDelayTime / numProcesses;
    tmp.avgtat=avgTurnaroundTime / numProcesses;
    return tmp;
//    cout << "Average waiting time: " << avgDelayTime / numProcesses << endl;
//    cout << "Average turnaround time: " << avgTurnaroundTime / numProcesses << endl;
}

//SJF Preemptive

tup SJFPreemptive2(int n,vector<pair<pair<int,int>,int> > vec)
{
    double twt,ttat,total,tresptime=0;
    shd arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i].bt=vec[i].first.first,arr[i].at=vec[i].first.second;
    }
    total=0;
    twt=0;
    ttat=0;
    for(int i=0; i<n; i++)
    {
        arr[i].rt=arr[i].bt;
        arr[i].finish=0;
        arr[i].wt=0;
        arr[i].tat=0;
        total+=arr[i].bt;
    }
    int time,next=0,old,i;

    vector<int > starttime(n+1);
    for(time=0; time<total; time++)
    {
        old=next;

        int i,low;
        for(i=0; i<n; i++)
            if(arr[i].finish==0)
            {
                low=i;
                break;
            }
        for(i=0; i<n; i++)
            if(arr[i].finish!=1)
                if(arr[i].rt<arr[low].rt && arr[i].at<=time)
                    low=i;
        next =low;
        if(old!=next || time==0)
        {
            //cout<<time<<" P"<<next+1<<" ";
            if(starttime[next+1]==0)
            {
                starttime[next+1]=time;
            }

        }


        arr[next].rt=arr[next].rt-1;
        if(arr[next].rt==0)
        {
            arr[next].finish=1;
        }
        for(i=0; i<n; i++)
            if(i!=next && arr[i].finish==0 && arr[i].at<=time)
                arr[i].wt++;
    }



    for(int i=0; i<n; i++)
    {
        twt+=arr[i].wt;
        arr[i].tat=arr[i].wt+arr[i].bt;
        ttat+=arr[i].tat;
        //cout<<"Process: P"<<i+1<<" Start Time:   "<<starttime[i+1]<<" Waiting Time: "<<arr[i].wt<<" Turnaround Time: "<<arr[i].tat<<" Response Time: "<<starttime[i+1]-arr[i].at<<endl;
//        cout<<"Waiting time for P"<<(i+1)<<" = "<<arr[i].wt<<", Turnaround time = "<<arr[i].tat<<endl;
        tresptime+=(starttime[i+1]-arr[i].at);
    }
    tup tm;
    tm.avgresp=tresptime/n,tm.avgwt=(double)twt/n;
    tm.avgtat=(double)ttat/n;
    return tm ;


//    cout<<endl;
//    cout<<"Avg Waiting time = "<<(double)twt/n<<endl;
//    cout<<"Avg. Turnaround time = "<<(double)ttat/n<<endl;
//    cout<<"Avg Response time = "<<tresptime/n<<endl;

}


//SJF Non-Preemptive

tup SJFNonPreemptive2(int n,vector<pair<pair<int,int>,int> > vec)
{
    int numProcesses, totalTurnaroundTime = 0, totalWaitingTime = 0;
    numProcesses=n;
    int arrivalTime[numProcesses], burstTime[numProcesses + 1], totalBurstTime = 0;
    for (int i = 0; i < numProcesses; ++i)
    {
        burstTime[i]=vec[i].first.first;
        totalBurstTime += burstTime[i];
        arrivalTime[i]=vec[i].first.second;
    }
    burstTime[numProcesses] = 9999;
    int currentTime, smallest;
    vector< pair<int,  pair<int, int>>> processDetails;
    vector<int> processId;
    for (currentTime = 0; currentTime < totalBurstTime;)
    {
        smallest = numProcesses;
        for (int i = 0; i < numProcesses; i++)
        {
            if (arrivalTime[i] <= currentTime && burstTime[i] > 0 && burstTime[i] < burstTime[smallest])
                smallest = i;
        }
       // cout << currentTime << " P" << smallest + 1 << " ";
        processId.push_back(smallest + 1);
        int startTime = currentTime, waitingTime = currentTime - arrivalTime[smallest], turnaroundTime = currentTime + burstTime[smallest] - arrivalTime[smallest];
        processDetails.push_back({startTime, {waitingTime, turnaroundTime}});
        totalTurnaroundTime += currentTime + burstTime[smallest] - arrivalTime[smallest];
        totalWaitingTime += currentTime - arrivalTime[smallest];
        currentTime += burstTime[smallest];
        burstTime[smallest] = 0;
    }
    //cout <<  endl;
    for (int i = 0; i < processDetails.size(); ++i)
    {
        int startTime = processDetails[i].first, waitingTime = processDetails[i].second.first, turnaroundTime = processDetails[i].second.second;
        //cout << "Process P" << processId[i] << " - Start time: " << startTime << ", Waiting time: " << waitingTime << ", Turnaround time: " << turnaroundTime <<  endl;
    }
    tup tm;
    tm.avgresp=totalWaitingTime * 1.0 / numProcesses,tm.avgwt=totalWaitingTime * 1.0 / numProcesses;
    tm.avgtat=totalTurnaroundTime * 1.0 / numProcesses ;
    return tm ;

//    cout << "Average waiting time = " << totalWaitingTime * 1.0 / numProcesses << endl;
//    cout << "Average turnaround time = " << totalTurnaroundTime * 1.0 / numProcesses <<endl;

}


tup NonPremPriority2(int val,vector<pair<pair<int,int>,int> > vec )
{

    long long int n=val;
    vector<long long int>a(n+5),b(n+5),ind(n+5),pr(n+5);
    long long int i,t=0,mn=LLONG_MAX,k;
    vector<long long int>st,wa,tu;
    for(i=1; i<=n; i++)
    {

        b[i]=vec[i-1].first.first;
        a[i]=vec[i-1].first.second;

        pr[i]=vec[i-1].second;
        ind[i]=i;
        if(mn>a[i])
        {
            mn=a[i];
            k=i;
        }
        t+=b[i];
    }
    double s1=0.0,s2=0.0;
    swap(a[1],a[k]);
    swap(b[1],b[k]);
    swap(ind[1],ind[k]);
    swap(pr[1],pr[k]);
    s2+=b[1];
    st.push_back(0);
    wa.push_back(0);
    tu.push_back(b[1]);

    k=b[1];
    long long int y=2,j;
    for(; k<t;)
    {
        mn=LLONG_MAX;
        for(i=y; i<=n; i+=1)
        {
            if(a[i]<=k)
            {
                if(mn>pr[i])
                {
                    mn=pr[i];
                    j=i;
                }
            }
        }
       // cout<<" "<<k;
        st.push_back(k);
        long long int wat=k-a[j];
        s1+=wat;
        long long int tur=wat+b[j];
        s2+=tur;
        wa.push_back(wat);
        tu.push_back(tur);
        k+=b[j];
        swap(a[y],a[j]);
        swap(b[y],b[j]);
        swap(ind[y],ind[j]);
        swap(pr[y],pr[j]);
        y++;
        if(y>n)
        {
            break;
        }

    }
    tup tm;
    tm.avgresp=s1/n , tm.avgwt=s1/n;
    tm.avgtat=s2/n ;
    return tm ;

//    cout<<"Average waiting time: "<<s1/n<<endl;
//    cout<<"Average turnover time: "<<s2/n<<endl;
}



tup PreemptivePriority2(int val,vector<pair<pair<int,int>,int> > vec )
{
    ll n;

    n=val;
    vector<ll>a(n+5),b(n+5),bb(n+5),ind(n+5),pr(n+5);
    ll i,t=0,mn=LLONG_MAX,k;
    for(i=1; i<=n; i++)
    {
        b[i]=vec[i-1].first.first;
        a[i]=vec[i-1].first.second;

        pr[i]=vec[i-1].second;

        t+=b[i];
    }
    bb=b;
    ll tq=1;
    k=0;
    ll y,j,kk=-1,pp=0;
    vector<ll>g,s;
    ll prev=-1;
    for(; k<t;)
    {
        mn=LLONG_MAX;
        for(i=1; i<=n; i++)
        {
            if(a[i]<=k&&b[i]>0)
            {
                if(mn>pr[i])
                {
                    mn=pr[i];
                    j=i;
                }
            }
        }
        if(prev!=j)
        {
            g.push_back(j);
            s.push_back(k);
            prev=j;
        }
        //cout<<k<<" "<<"P"<<j<<" ";
        k+=min(b[j],tq);
        b[j]-=min(b[j],tq);
        if(b[j]<=0)pp++;
    }
    //cout<<"Gantt Chart"<<endl;
//    for(i=0; i<g.size(); i++)
//    {
//        cout<<s[i]<<" "<<"P"<<g[i]<<" ";
//    }

   //cout<<t<<endl;
    s.push_back(t);
    double tr=0.0,tw=0.0,tt=0.0;
    for(i=1; i<=n; i++)
    {
        //cout<<"Process: P"<<i<<" Start time: ";
        ll stt,enn;
        for(j=0; j<g.size(); j++)
        {
            if(g[j]==i)
            {
                stt=s[j];
                break;
            }
        }
        for(j=g.size()-1; j>=0; j--)
        {
            if(g[j]==i)
            {
                enn=s[j+1];
                break;
            }
        }
//        cout<<stt<<" End time: "<<enn<<" Response time: ";
//        cout<<stt-a[i]<<" Waiting time: "<<enn-a[i]-bb[i];
//        cout<<" Turnaround time: "<<enn-a[i]<<endl;
        tr+=(stt-a[i]);
        tw+=(enn-a[i]-bb[i]);
        tt+=(enn-a[i]);
    }
    tup tm;
    tm.avgresp=tr/n , tm.avgwt=tw/n;
    tm.avgtat=tt/n ;
    return tm ;
//    cout<<setprecision(2)<<fixed;
//    cout<<"Average Response Time: "<<tr/n<<endl;
//    cout<<"Average Waiting Time: "<<tw/n<<endl;
//    cout<<"Average Turnaround Time: "<<tt/n<<endl;
}


tup RoundRobin2(int sz,vector<pair<pair<int,int>,int> > vec,int TQ)
{
    int i, j, n, time, remainingProcesses, flag = 0, timeQuantum;
    struct Process processes[100];
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    n=sz;
    int totalBurstTime = 0;
    remainingProcesses = n;

    for (i = 0; i < n; i++)
    {

        processes[i].burstTime=vec[i].first.first;
        processes[i].arrivalTime=vec[i].first.second;
        processes[i].processId = i;
        processes[i].remainingTime = processes[i].burstTime;
        totalBurstTime += processes[i].burstTime;
    }

    sortArrivalTime(processes, n);


    timeQuantum=TQ;



    vector<int> timeline(n + 1, 0);


    for (time = 0, i = 0; remainingProcesses != 0;)
    {
        if (processes[i].remainingTime <= timeQuantum && processes[i].remainingTime > 0)
        {
            time += processes[i].remainingTime;
            if (timeline[processes[i].processId] == 0)
            {
                timeline[processes[i].processId] = time;
            }



            processes[i].remainingTime = 0;
            flag = 1;
        }
        else if (processes[i].remainingTime > 0)
        {
            processes[i].remainingTime -= timeQuantum;
            time += timeQuantum;
            if (timeline[processes[i].processId] == 0)
            {
                timeline[processes[i].processId] = time;
            }

        }
        if (processes[i].remainingTime == 0 && flag == 1)
        {
            remainingProcesses--;
            processes[i].turnaroundTime = time - processes[i].arrivalTime;
            processes[i].waitingTime = time - processes[i].arrivalTime - processes[i].burstTime;
            avgWaitingTime += time - processes[i].arrivalTime - processes[i].burstTime;
            avgTurnaroundTime += time - processes[i].arrivalTime;
            flag = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (processes[i + 1].arrivalTime <= time)
            i++;
        else
            i = 0;
    }


    double avgResponseTime = 0;
    for (i = 0; i < n; i++)
    {
//        cout << "Process: " << processes[i].processId + 1 << " Start Time: " << timeline[processes[i].processId]
//             << " Waiting Time: " << processes[i].waitingTime << " Turnaround Time: " << processes[i].turnaroundTime
//             << " Response Time: " << timeline[processes[i].processId] - processes[i].arrivalTime << endl;
        avgResponseTime += (timeline[processes[i].processId] - processes[i].arrivalTime);
    }

    avgWaitingTime = avgWaitingTime / n;
    avgResponseTime /= n;
    avgTurnaroundTime = avgTurnaroundTime / n;

    tup tm;
    tm.avgresp=avgResponseTime , tm.avgwt=avgWaitingTime;
    tm.avgtat=avgTurnaroundTime ;
    return tm ;
//    cout << "Average Waiting Time: " << avgWaitingTime << endl;
//    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
//    cout << "Average Response Time: " << avgResponseTime << endl;

    //return ;
}


tup PriorityRobin2(int sz,vector<pair<pair<int,int>,int> > vec,int TQ)
{
    ll n;
    n=sz;
    vector<ll>a(n+5),b(n+5),bb(n+5),ind(n+5),pr(n+5);
    ll i,t=0,mn=LLONG_MAX,k;
    for(i=1; i<=n; i++)
    {
        b[i]=vec[i].first.first;
        a[i]=vec[i].first.second;
        pr[i]=vec[i].second;
        t+=b[i];
    }
    bb=b;
    ll tq;
    tq=TQ;
    k=0;
    ll y,j,kk=-1,pp=0;
    vector<ll>g,s;
    //cout<<"Gantt Chart"<<endl;
    for(; k<t;)
    {
        mn=LLONG_MAX;
        for(i=1; i<=n; i++)
        {
            if(a[i]<=k&&b[i]>0&&i!=kk)
            {
                if(mn>pr[i])
                {
                    mn=pr[i];
                    j=i;
                }
            }
        }
       // cout<<k<<" "<<"P"<<j<<" ";
        g.push_back(j);
        s.push_back(k);
        k+=min(b[j],tq);
        b[j]-=min(b[j],tq);
        kk=j;
        if(b[j]<=0)pp++;
    }
   // cout<<t<<endl;
    s.push_back(t);
    double tr=0.0,tw=0.0,tt=0.0;
    for(i=1; i<=n; i++)
    {
        //cout<<"Process: P"<<i<<" Start time: ";
        ll stt,enn;
        for(j=0; j<g.size(); j++)
        {
            if(g[j]==i)
            {
                stt=s[j];
                break;
            }
        }
        for(j=g.size()-1; j>=0; j--)
        {
            if(g[j]==i)
            {
                enn=s[j+1];
                break;
            }
        }
//        cout<<stt<<" End time: "<<enn<<" Response time: ";
//        cout<<stt-a[i]<<" Waiting time: "<<enn-a[i]-bb[i];
//        cout<<" Turnaround time: "<<enn-a[i]<<endl;
        tr+=(stt-a[i]);
        tw+=(enn-a[i]-bb[i]);
        tt+=(enn-a[i]);
    }
//    cout<<setprecision(2)<<fixed;
//    cout<<"Average Response Time: "<<tr/n<<endl;
//    cout<<"Average Waiting Time: "<<tw/n<<endl;
//    cout<<"Average Turnaround Time: "<<tt/n<<endl;
    tup tmp;
    tmp.avgresp=tr/n , tmp.avgwt=tw/n;
    tmp.avgtat=tt/n ;
    return tmp;
}
