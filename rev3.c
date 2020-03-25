#include<stdio.h>
int n=0,j=0,k=0,l=0,t1=0,t2=0,t3=0;
int burstt[10],arrivalt[10],priority[10];
int AT1[10],BT1[10],PR1[10];
int AT2[10],BT2[10],PR2[10];
int AT3[10],BT3[10],PR3[10];

int main()
{
	int i=0;
	printf(" Enter no. of processes[max 10] ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
	printf("\n Enter arrival time for P[%d] ",i+1);
	scanf("%d",&arrivalt[i]);
	printf(" Enter burst time for P[%d] ",i+1);
	scanf("%d",&burstt[i]);
	printf(" Enter priority [0 to 15] 0(Highest) for P[%d] ",i+1);
	scanf("%d",&priority[i]);
	}
	
	for(i=0;i<n;i++)
	{
		if(priority[i]>=0 && priority[i]<=5) //roundrobin
		{
			AT1[j]=arrivalt[i];
			BT1[j]=burstt[i];
			t1+=burstt[i];
			j++;
			printf("\n P[%d] belongs to Queue 1",i+1);
		}
		if(priority[i]>=6 && priority[i]<=10) //priority
		{
			AT2[k]=arrivalt[i];
			BT2[k]=burstt[i];
			PR2[k]=priority[i];
			t2+=burstt[i];
			k++;
			printf("\n P[%d] belongs to Queue 2",i+1);
		}
		if(priority[i]>=11 && priority[i]<=15) //fcfs
		{
			AT3[l]=arrivalt[i];
			BT3[l]=burstt[i];
			t3+=burstt[i];
			l++;
			printf("\n P[%d] belongs to Queue 3",i+1);
		}
		}
	printf("\n\n Time Quantum between the 3 Queues is 10 Units\n");
	
	while(t1+t2+t3!=0)
	{
		if(t1>=10) //RR
		{
			t1-=10;
			printf("\n Queue1 [RR] will run for 10 units  Left Burst time = %d units",t1);
		}
		else if(t1>0)
		{
			printf("\n Queue1 [RR] will run for %d units  Left Burst time = 0 units" ,t1);
			t1=0;
		}
		//Priority
		if(t2>=10)
		{
			printf("\n Queue2 [PRIORITY] will run for 10 units  Left Burst time = %d units",t2);
			t2-=10;
		}
		else if(t2>0)
		{
			printf("\n Queue2 [PRIORITY]  will run for %d units  Left Burst time = 0 units" ,t2);
			t2=0;
		}
		//FCFS
		if(t3>=10)
		{
			t3-=10;
			printf("\n Queue3 [FCFS] will run for 10 units  Left Burst time = %d units",t3);
		}
		else if(t3>0)
		{
			printf("\n Queue3 [FCFS] will run for %d units  Left Burst time = 0 units" ,t3);
			t3=0; 
		}
	}
	r_robin();
	}
	
	int r_robin()       
	{
	int total1=0,t=0,i=0;

		for(t=0;t<3;t++)
		{
		
		for(i=0;i<j;i++)
		{
			if(total1>6 && BT1[i]>(10-total1))
			{
				printf("\n [Queue1] P[%d] Will Run For %d Units",i+1,10-total1);
				BT1[i]-=(10-total1);
				total1=0;
				printf("\n\n Quantum Time = 10 Finished for [Q1]");
				priorityf();
			}
			else if(BT1[0]==0 && BT1[1]==0 && i==2 && BT1[i]>=10-total1)
			{
				printf("\n [Queue1] P[%d] Will Run For %d Units",i+1,10-total1);
				BT1[i]-=(10-total1);
				total1=0;
				printf("\n\n Quantum Time = 10 Finished for [Q1]");
				priorityf();
			}
			else if(BT1[i]>0 && BT1[i]<=4)
			{
				printf("\n [Queue1] P[%d] Will Run For %d Units",i+1,BT1[i]);
				total1+=BT1[i];
				BT1[i]=0;
			}
			else if(BT1[i]>0)
			{
				printf("\n [Queue1] P[%d] Will Run For 4 Units",i+1);
				total1+=4;
				BT1[i]-=4;
			}
		}
	}	
	priorityf();
	}
	
    int priorityf()
	{
		
		int total=0,i=0;
		int m=0,temp=0,pos,min,p=0;
		for(i=0;i<k;i++)
		{
			pos=i;
			for(m=i+1;m<k;m++)
			{
				if(PR2[m]<PR2[pos])
				{
					pos=m;
				}
		}
		temp=BT2[i];
		BT2[i]=BT2[pos];
		BT2[pos]=temp;
		
		temp=PR2[i];
		PR2[i]=PR2[pos];
		PR2[pos]=temp;
		}
		for(p=0;p<3;p++)
		{
		for(i=0;i<k;i++)
		{
			if(total!=0 && BT2[i]>(10-total))
			{
				printf("\n [Queue2] P[%d] Will Run For %d Units",i+4,10-total);
				BT2[i]=BT2[i]-(10-total);
				total=0;
				printf("\n\n Quantum Time = 10 Finished for [Q2]");
				break;
			}

			else if(BT2[i]>0 && BT2[i]<=10)
			{
				printf("\n [Queue2] P[%d] Will Run For %d Units",i+4,BT2[i]);
				total+=BT2[i];
				BT2[i]=0;
			}
			}
		}
	
		}
	
	
