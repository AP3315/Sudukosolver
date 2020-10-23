#include<iostream>
#include<iomanip>
using namespace std;

void print(int a[][9],int n)
{
    //cout<<"[";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<setw(2) <<a[i][j]<<",";
            //if(j%3==0)
                //cout<<"|";
        }
        cout<<endl;
    }
    //cout<<"]";
}

bool canplace(int a[][9],int n,int r,int c,int no)
{
    if(a[r][c]!=0)
    {
        cout<<"KKKKK";
        return false;
    }


    for(int k=0;k<n;k++)
    {
        if(a[r][k]==no)
            return false;
    }

    for(int k=0;k<n;k++)
    {
        if(a[k][c]==no)
            return false;
    }

    r=3*(r/3);
    //cout<<"r:"<<r<<" ";
    c=3*(c/3);
    //cout<<"c:"<<c<<endl;
    for(int i=r;i<r+3;i++)
    {
        for(int j=c;j<c+3;j++)
        {
            if(a[i][j]==no)
                return false;
        }
    }
    return true;
}

bool ss(int a[][9],int n,int r,int c,int &k)
{
    if(r==n)
    {
        k++;
        print(a,n);
        cout<<endl;
        return false;         ///if removed then will start givng the copy of the solution   only 3 unique soln
    }
    if(c==n)
    {
        return ss(a,n,r+1,0,k);
    }

    if(a[r][c]!=0)
    {
         return ss(a,n,r,c+1,k);
    }
    for(int no=9;no>0;no--)             ///this will only using this loop will help me for doing for one cell
    {
        //cout<<"k"<<" ";
        if(canplace(a,n,r,c,no))
        {
            a[r][c]=no;
            //print(a,n);
            //cout<<endl;
            if(ss(a,n,r,c+1,k))
                return true;        ///both working but one take more time;
            //ss(a,n,r,c+1,k);

            a[r][c]=0;
        }
    }
    return false;
}

int main()
{
    int n=9,k=0;

    // int a[9][9];
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cin>>a[i][j];
    //     }
    // }

    int a[][9]=
            {
                {5,3,0,0,7,0,0,0,0},
                {6,0,0,1,0,5,0,0,0},
                {0,0,8,0,0,0,0,6,0},
                {8,0,0,0,6,0,0,0,3},
                {4,0,0,8,0,3,0,0,1},
                {7,0,0,0,2,0,0,0,6},
                {0,6,0,0,0,0,2,8,0},
                {0,0,0,4,1,9,0,0,5},
                {0,0,0,0,8,0,0,7,9}
            };

    cout<<ss(a,n,0,0,k);
    cout<<" "<<k;
    return 0;
}

