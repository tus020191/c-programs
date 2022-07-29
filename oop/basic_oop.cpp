#include<iostream>
#include<string>
using namespace std;

class student
{
private:
    string name;
    string dob;
    string number;
public:
    // constructor
    student(string name,string dob ,string num): name(name),dob(dob),number(num) // list initilizer
    {

    }
    string get_name()
    {
        return name;
    }
    string get_dob();
    string get_num();
    friend void display_data(student &s);  // friend function can use private and protected member even
                                            // not being class member
};
string student:: get_num() // declaring outside class
{
    return number;
}
string student:: get_dob()
{
    return dob;
}
void display_data(student &s) // declaration of friend function
{
    cout<<"*******************************data of student ****************************************\n";
    cout<<"name         "<<s.name<<endl;
    cout<<"number         "<<s.number<<endl;
    cout<<"dob         "<<s.dob<<endl;
}
int main()
{
    student s1("tushar gupta","19/10/2002","7746xxxxx"); // making object
    cout<<"name  "<<s1.get_name()<<endl;
    cout<<"number  "<<s1.get_num()<<endl;
    cout<<"dob  "<<s1.get_dob()<<endl;
    display_data(s1);
}
