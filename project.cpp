#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class cpuschedule
{
    int n,Bu[20];
    float TotalWaitingTime, AverageWaitingTime, A[10],WaitingTime[10],w;
public:
    void Getdata();
    void Fcfs();
    void Sjf();
    void SjfP();
    void SjfNp();
    void RoundRobin();
    void Priority();
};

void cpuschedule::Getdata()
{
    int i;
    cout<<"\nEnter the no of processes:";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"\nEnter The Burst Time for Process p"<<i<<"=	";
        cin>>Bu[i];
    }
}

void cpuschedule::Fcfs()
{
    int i,B[10];
   TotalWaitingTime=0.0;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process p"<<i<<"=	";
        cout<<B[i];
    }
    WaitingTime[1]=0;
    for(i=2; i<=n; i++)
    {
        WaitingTime[i]=B[i-1]+WaitingTime[i-1];
    }

    for(i=1; i<=n; i++)
    {
        TotalWaitingTime = TotalWaitingTime + WaitingTime[i];
    }
    AverageWaitingTime = TotalWaitingTime/n;
    cout<<"\n\nTotal   Weighting Time="<<TotalWaitingTime;
    cout<<"\n\nAverage Weighting Time="<<AverageWaitingTime<<""<<endl;
}

void cpuschedule::Sjf()
{
    int i,j,temp,B[10];
    TotalWaitingTime=0.0;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process p"<<i<<"=	";
        cout<<B[i];
    }
    for(i=n; i>=1; i--)
    {
        for(j=1; j<=n; j++)
        {
            if(B[j-1]>B[j])
            {
                temp=B[j-1];
                B[j-1]=B[j];
                B[j]=temp;
            }
        }
    }

    WaitingTime[1]=0;
    for(i=2; i<=n; i++)
    {
        WaitingTime[i]=B[i-1]+WaitingTime[i-1];
    }
    for(i=1; i<=n; i++)
    {
        TotalWaitingTime = TotalWaitingTime + WaitingTime[i];
    }
    AverageWaitingTime=TotalWaitingTime/n;
    cout<<"\nTotal   Weighting Time="<<TotalWaitingTime;
    cout<<"\nAverage Weighting Time="<<AverageWaitingTime<<"";
}

void cpuschedule::SjfNp(){
    int i,B[10],Tt=0,temp,j;
    char S[10];
    float A[10],temp1,t;
    TotalWaitingTime=0.0;
    w=0.0;
    for(i=1; i<=n; i++){
        B[i]=Bu[i];
        cout<<"\nBurst time for process p "<<i<<"=	";
        cout<<B[i];
        S[i]='T';
        Tt=Tt+B[i];
        cout<<"\nEnter the Arrival Time for"<<i<<"th process=	";
        cin>>A[i];
    }
    for(i=n; i>=1; i--){
        for(j=3; j<=n; j++){
            if(B[j-1]>B[j]){
                temp=B[j-1];
                temp1=A[j-1];
                B[j-1]=B[j];
                A[j-1]=A[j];
                B[j]=temp;
                A[j]=temp1;
            }
        }
    }
    for(i=1; i<=n; i++){
        cout<<" p"<<i<<"	"<<B[i]<<"	"<<A[i];
    }
    WaitingTime[1]=0;
    w=w+B[1];
    t=w;
    S[1]='F';
    while(w<Tt){
        i=2;
        while(i<=n)
        {
            if(S[i]=='T'&&A[i]<=t)
            {
                WaitingTime[i]=w;
                cout<<" \n WT "<<i<<"= "<<WaitingTime[i];
                S[i]='F';
                w=w+B[i];
                t=w;
                i=2;
            }
            else
                i++;
        }
    }
    for(i=1; i<=n; i++) {
        cout<<"\n Wt"<<i<<"=="<<WaitingTime[i];
    }
    for(i=1; i<=n; i++)
        TotalWaitingTime=TotalWaitingTime+(WaitingTime[i]-A[i]);
    AverageWaitingTime=TotalWaitingTime/n;
    cout<<"\nTotal   Weighting Time = "<<TotalWaitingTime<<""<<endl;
    cout<<"\nAverage Weighting Time="<<AverageWaitingTime<<""<<endl;
}

void cpuschedule::Priority()
{
    int i,B[10],P[10],j;
    w=0.0;
    int max;
    TotalWaitingTime=0.0;
    max=1;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for process p"<<i<<"=	";
        cout<<B[i];
        cout<<"\nEnter the priority for process P"<<i<<"=	";
        cin>>P[i];
        if(max<P[i]){
            max=P[i];
        }
    }
    j=1;
    while(j<=max)
    {
        i=1;
        while(i<=n)
        {
            if(P[i]==j)
            {
                WaitingTime[i]=w;
                w=w+B[i];
            }
            i++;
        }
        j++;
    }
    for(i=1; i<=n; i++){
        TotalWaitingTime=TotalWaitingTime+WaitingTime[i];
    }
    AverageWaitingTime=TotalWaitingTime/n;
    cout<<"\nTotal   Weighting Time = "<<TotalWaitingTime<<""<<endl;
    cout<<"\nAverage Weighting Time = "<<AverageWaitingTime<<""<<endl;
}

void cpuschedule::SjfP()
{
    int i,j,m,WaitingTime[10],k,B[10],A[10],Tt=0,Wtm[10],temp;
    char S[20],start[20];
    int max=0,Time=0,min;
    float TotalWaitingTime=0.0,AverageWaitingTime;
    for(i=1; i<=n; i++){
        B[i]=Bu[i];
        cout<<"\nBurst time for process P"<<i<<"=	"<<B[i];
        if(B[i]>max){
            max=B[i];
        }
        WaitingTime[i]=0;
        S[i]='T';
        start[i]='F';
        Tt=Tt+B[i];
        cout<<"\nEnter the Arrival Time for"<<i<<"th process=	";
        cin>>A[i];
        if(A[i]>Time){
            Time=A[i];
        }
    }
    int w=0,flag=0,t=0;
    i=1;
    while(t<Time){
        if(A[i]<=t && B[i]!=0){
            if(flag==0){
                WaitingTime[i]=WaitingTime[i]+w;
                cout<<"\n Wt["<<i<<"] = "<<WaitingTime[i];
            }
            B[i]=B[i]-1;
            if(B[i]==0)
                S[i]='F';
            start[i]='T';
            t++;
            w=w+1;
            if(S[i]!='F'){
                j=1;
                flag=1;
                while(j<=n && flag!=0){
                    if(S[j]!='F' && B[i]>B[j] && A[j]<=t && i!=j ){
                        flag=0;
                        WaitingTime[i]=WaitingTime[i]-w;
                        i=j;
                    }
                    else
                    {
                        flag=1;
                    }
                    j++;
                }
            }
            else{
                i++;
                j=1;
                while(A[j]<=t &&j<=n){
                    if(B[i]>B[j] && S[j]!='F'){
                        flag=0;
                        i=j;
                    }
                    j++;
                }
            }
        }
        else if(flag==0){
            i++;
        }
    }
    cout<<"\nPrinting remaining burst time";
    for(i=1; i<=n; i++){
        cout<<"B["<<i<<"]="<<B[i];
    }
    cout<<"";
    while(w<Tt){
        min=max+1;
        i=1;
        while(i<=n){
            if(min>B[i] && S[i]=='T'){
                min=B[i];
                j=i;
            }
            i++;
        }
        i=j;
        if(w==Time && start[i]=='T'){
            w=w+B[i];
            S[i]='F';
        }
        else{
            WaitingTime[i]=WaitingTime[i]+w;
            w=w+B[i];
            S[i]='F';
        }
    }
    cout<<"\nWeight info ";
    for(i=1; i<=n; i++) {
        cout<<" WT["<<i<<"] = "<<WaitingTime[i];
    }
    cout<<"\nAfter subtracting arrival time";
    for(i=1; i<=n; i++)
    {
        WaitingTime[i]=WaitingTime[i]-A[i];
        cout<<" WT["<<i<<"] = "<<WaitingTime[i];
    }
    for(i=1; i<=n; i++)
        TotalWaitingTime=TotalWaitingTime+WaitingTime[i];
    AverageWaitingTime=TotalWaitingTime/n;
    cout<<"\n\nAverage Weighting Time = "<<AverageWaitingTime<<endl;
}

void cpuschedule::RoundRobin(){
    int i,j,tq,k,B[10],Rrobin[10][10],count[10];
    int max=0;
    int m;
    TotalWaitingTime=0.0;
    for(i=1; i<=n; i++){
        B[i]=Bu[i];
        cout<<"\nBurst time for process p"<<i<<"=	";
        cout<<B[i];
        if(max<B[i])
            max=B[i];
        WaitingTime[i]=0;
    }
    cout<<"\nEnter the Time Quantum = ";
    cin>>tq;
    m=max/tq+1;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            Rrobin[i][j]=0;
        }
    }
    i=1;
    while(i<=n){
        j=1;
        while(B[i]>0){
            if(B[i]>=tq){
                B[i]=B[i]-tq;
                Rrobin[i][j]=tq;
                j++;
            }
            else{
                Rrobin[i][j]=B[i];
                B[i]=0;
                j++;
            }
        }
        count[i]=j-1;
        i++;
    }
    cout<<"Display";
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cout<<"Rr["<<i<<","<<j<<"] = "<<Rrobin[i][j];
            cout<<"	";
        }
        cout<<"";
    }
    int x=1;
    i=1;
    while(x<=n){
        for(int a=1; a<x; a++){
            WaitingTime[x]=WaitingTime[x]+Rrobin[a][i];
        }
        i=1;
        int z=x;
        j=count[z];
        k=1;
        while(k<=j-1){
            if(i==n+1){
                i=1;
                k++;
            }
            else{
                if(i!=z){
                    WaitingTime[z]=WaitingTime[z]+Rrobin[i][k];
                }
                i++;
            }
        }
        x++;
    }
    for(i=1; i<=n; i++) {
        cout<<"\nWeighting Time for process P"<<i<<"="<<WaitingTime[i];
    }
    for(i=1; i<=n; i++) {
        TotalWaitingTime=TotalWaitingTime+WaitingTime[i];
    }
    AverageWaitingTime=TotalWaitingTime/n;
    cout<<"\n Total   Weighting Time = "<<TotalWaitingTime<<endl;
    cout<<"\n\nAverage Weighting Time = "<<AverageWaitingTime<<""<<endl;
}

int main()
{
    int ch,cho;
    cpuschedule c;
        cout<<" |<><><><><><><><><><><><><><><><><><><><>| " << endl;
        cout<<" |........................................| " << endl;
        cout<<" |........................................| " << endl;
        cout<<" |.......Welcome To The Menu Driven.......| " << endl;
        cout<<" |.............CPU Scheduling.............| " << endl;
        cout<<" |........................................| " << endl;
        cout<<" |........................................| " << endl;
        cout<<" |<><><><><><><><><><><><><><><><><><><><>| " << endl;
    do
    {

        cout<<'\n'<<endl;
        cout<<"1.             For Burst Time"<<endl;
        cout<<"2.  For First Come First Served (FCFS)"<<endl;
        cout<<"3.     For Shortest Job First (SJF)"<<endl;
        cout<<"4.          For Round Robin (RR)"<<endl;
        cout<<"5.              For Priority"<<endl;
        cout<<"6.           Click Here To End"<<endl;
        cout<<"\nDrop Your Choice Here: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            c.Getdata();
            break;
        case 2:
            cout<<"\nFirst Come First Served (FCFS) CPU Scheduling"<<endl;
            c.Fcfs();
            break;
        case 3:
            cout<<"\nShortest Job First (SJF) CPU Scheduling"<<endl;
            do
            {
                cout<<"\n1.Shortest Job First(Normal)"<<endl;
                cout<<"2.Shortest Job First(Preemptive)"<<endl;
                cout<<"3.Shortest Job First(NonPreemptive)"<<endl;
                cout<<"Drop your choice here: ";
                cin>>cho;
                switch(cho)
                {
                case 1:
                    c.Sjf();
                    break;
                case 2:
                    c.SjfP();
                    break;
                case 3:
                    c.SjfNp();
                    break;
                }
            }
            while(cho<=3);
            break;
        case 4:
            cout<<"\nRound Robin (RR)"<<endl;
            c.RoundRobin();
            break;
        case 5:
            cout<<"\nPriority Scheduling"<<endl;
            c.Priority();
            break;
        case 6:
            break;
        }
    }
    while(ch<=5);
}
