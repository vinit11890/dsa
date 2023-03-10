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
                void insert_htable();
                void display_htable();
                void search_htable();
                void delete_htable();
                int apply_hash_function(int);
                
                
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

void myhash::insert_htable()
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

void myhash::display_htable()
{
  
  for(int i=0;i<size;i++)
  {
     cout<<"\n\t\t["<<i<<"]==>"<<A[i];
  }
}
  
  void myhash::search_htable()
{
  int X,hi,i;
  cout<<"\n enter the identifier to be searched:";
  cin>>X;
  hi=apply_hash_function(X);
  
  if(A[hi]==-1)
  {
   
   cout<<"\nIdentifier "<<X<<" inserted without collision at position "<<hi;
   
   }
   
   else
   {
       i=hi;
       int flag=0;
       do
        {
          if(A[i]=X)
              {
                
                cout<<"\nIdentifier "<<X<<" found at position "<<i;
                flag=1;
                break;
              }
              i=(i+1)%size;
        }while(A[i]!=-1&&i!=hi);
        if(flag==0)
          cout<<"\nIdentifier "<<X<<" not present in the table ";
   } 
}

void myhash::delete_htable()
{
  int X,hi,i;
  cout<<"\n enter the identifier to be deleted:";
  cin>>X;
  hi=apply_hash_function(X);
  
  if(A[hi]==-1)
  {
     cout<<"\nIdentifier "<<X<<" to b deleted not present in the table";
  }
  else
  {
    i=hi;
    int flag=0;
    do
    {
      if(A[i]==X)
      {
        A[i]=-2;
        cout<<"\nIdentifier "<<X<<" found at position"<<i<<"and deleted succesfully\n";
        flag=1;
        break;
      }
      i=(i+1)%size;
    }while(A[i]!=-1&&i!=hi);
    if(flag=0)
        cout<<"\nIdentifier "<<X<<" not present in the table";
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
      cout<<"\n\t\t3:search";
      cout<<"\n\t\t4:delete";
      cout<<"\n\t\t5:exit";
      cout<<"\n\t\tenter your choice:";
      cin>>ch;
      switch(ch)
      {
         case 1:h1.insert_htable();
                break;
         case 2:h1.display_htable();
                break;
         case 3:h1.search_htable();
                break;
         case 4:h1.delete_htable();
                break;
         case 5: cout<<"\nend\n";
                break;
         default: cout<<"\n invalid choice!! try agin!!\n";
      }
   }while(ch!=3);
   return 0;           
        
        
}
