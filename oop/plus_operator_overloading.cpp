#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class cat
{
	char a[100];  //character array
public:
/*
	cat(char *str){
		cout<<"yes\n";
		a=str;

		}*/
		cat() // default empty constructor
		{
		}
	cat(char *c)  // constructor to assign value to a
	{
		strcpy(a,c); // copying c value in a

	}

	// overloading + operator
	// str2 object is one which is on right of + operator i,e, str1+str2
	// since str1 is on left so it means we have called + operator with str1
	// hence  str1 object members can be used directly inside it

	  cat operator +(cat &str2) // it is always good practice to pass object by refrence
	{
		cat tmp;
		int i=0,j=0;
		while(i<strlen(str2.a))
		{
			if(j< strlen(a))
			{
				tmp.a[j]=a[j];

				j++;
				continue ;

			}

			tmp.a[j]=str2.a[i];

			j++,i++;


		}
		tmp.a[j]='\0';

		return tmp; // returning concated string

	}
	void get()
	{
		cout<<a<<endl;
	}
};


int main(int argc, char *argv[])
{



	cat str1 ="h ell o" ,str2="c pp";
	str1.get();
	str2.get();

	cat cont=str1+str2;  // in this default copy constructor will run and the object
                    // which is returned will be copied to const
	cont.get();
	cout<<endl;

	return 0;



}
