//-1: same row and same col -10: that row and col are selected
//ans:43122431
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void row();
void col();
void zero();
void dis();
int a[4][4]={{-1,10,15,20},{5,-1,9,10},{6,13,-1,12},{8,8,9,-1}};
int t[8]={0};
int flag=0;
int main()
{
    int a1[4][4],i,j,k,minr,minc,y=0,maxx,p=0,yy,xx,q;
    //loop
for(q=0;q<3;q++)
{
    row();
    col();
    dis();
    cout<<"iteration"<<q+1<<endl;
    cout<<"path:"<<endl;
    for(int l=0;l<8;l++)
        cout<<t[l]<<"\t";
    cout<<endl;
    cout<<"matrix:"<<endl;
    //penalty calculation
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            a[i][j]=-1;
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
                {
                    minr=a[i][0];
                    for(k=0;k<4;k++)
                        {
                            if(a[i][k]<minr)
                                minr=a[i][k];
                        }
                    minc=a[0][j];
                    for(k=0;k<4;k++)
                        {
                            if(a[k][j]<minc)
                                minc=a[k][j];
                        }
                    y=minr+minc;
                    a1[i][j]=y;
                }
        }
    }
    for(i=0;i<4;i++)
    {
        maxx=a1[i][0];
        for(j=0;j<4;j++)
        {
            if(a1[i][j]>maxx)
                maxx=a1[i][j];
        }
    }//path between i and j
    xx=i;
    yy=j;
    for(j=0;j<4;j++)
        a[xx][j]=-10;
    for(i=0;i<4;i++)
        a[i][yy]=-10;
    t[p]=xx;
    p++;
    t[p]=yy;
    p++;
}//final loop
    return 0;
}
void row()
{
    int temp=0,i=0,j=0,k=0;

    for(i=0;i<4;i++)
    {
        temp=a[i][0];
        for(j=0;j<4;j++)
        {
            if(a[i][j]<temp && a[i][j]>=0)
                temp=a[i][j];
        }
        for(j=0;j<4;j++)
            a[i][j]-=temp;

    }

}
void col()
{
    int temp=0,i=0,j=0,k=0;

    for(i=0;i<4;i++)
    {
        temp=a[0][i];
        for(j=0;j<4;j++)
        {
            if(a[j][i]<temp && a[j][i]>=0)
                temp=a[j][i];
        }
        for(j=0;j<4;j++)
            a[j][i]-=temp;

    }

}
void zero()
{
    int i,j;
    for(i=0;i<4;i++)
    {

        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
                flag=1;

        }
        if(flag==0)
            row();
        flag=0;
    }
    flag=0;
    for(i=0;i<4;i++)
    {

        for(j=0;j<4;j++)
        {
            if(a[j][i]==0)
                flag=1;

        }
        if(flag==0)
            col();
        flag=0;
    }

}
void dis()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]>=0)
            cout<<a[i][j]<<"\t";
            else if(a[i][j]==-1)
                cout<<"-"<<"\t";
            else if(a[i][j]==-10)
                cout<<"x"<<"\t";
        }
        cout<<endl;
    }
}
