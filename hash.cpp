#include<iostream>
#include<stdlib.h>
#define size 10

using namespace std;
class myhash
{
        private:
                int A[size];
        public:
                myhash();
                void insert();
                int apply_hash_function(int);
                void display();
                
};         



myhash::myhash()
{
  for(int i=0;i<size;i++)
  {
      A[i]=-1;
  
  }
      
}

int myhash :: apply_hash_function(int X)
{
  return(X% size);
}

void myhash::insert()
{
  int X,hi,i;
  cout<<"\n enter the identifier to be inserted:";
  cin>>X;
  hi=apply_hash_function(X);
  
  if(A[hi]==-1)
  {
   A[hi]=X;
   cout<<"\nIdentifier "<<X<<" inserted without collision at position "<<hi;
   
   }
   
   else
   {
        for(i=(hi+1)%size;i!=hi;i=(hi+1)%size)
        {
    
              if(A[i]==-1)
              {
                A[i]=X;
                cout<<"\nIdentifier "<<X<<" inserted without collision at position "<<i;
                break;
              }  
        }
        
        if(i==hi)
        {
                cout<<"\n\t\t overflow....!";
        
        }
   }
   
  for(i=0;i<size;i++)
  {
     cout<<"\n\t\t["<<i<<"]==>"<<A[i];
  }
}

void myhash::display()
{
  
  for(int i=0;i<size;i++)
  {
     cout<<"\n\t\t["<<i<<"]==>"<<A[i];
  }
}
  
  
int main()
{
   int ch;
   system("clear");
   myhash h1;
   do
   {
      cout<<"\n\t\t1:insert";
      cout<<"\n\t\t2:Display";
      cout<<"\n\t\t3:exit";
      cout<<"\n\t\tenter your choice:";
      cin>>ch;
      switch(ch)
      {
         case 1:h1.insert();
                break;
         case 2:h1.display();
                break;
         case 3: cout<<"\nend\n";
                break;
         default: cout<<"\n invalid choice!! try agin!!\n";
      }
   }while(ch!=3);
   return 0;           
        
        
}

