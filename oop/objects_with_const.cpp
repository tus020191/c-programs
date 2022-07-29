#include<iostream>
#include<string>
using namespace std;

/*
1.functions made const can be accessed by both const and non const objects
2. no modification can be done in const function
3. const objects can access only const function

*/
class student
{
private:
    int id;
    string name;
    string dob;
    string number;
public:
    // constructor
    student(int id,string name,string dob ,string num): id(id), name(name),dob(dob),number(num) // list initilizer
    {

    }
    string get_name() const
    {
        //name="dgfh"; not allowed

        return name;
    }
    int get_id() const
    {
        //id=56; not allowed
        return id;
    }
    string get_dob() const;
    string get_num() ;
    friend void display_data(student &s);  // friend function can use private and protected member even
                                            // not being class member
};
string student:: get_num() // declaring outside class
{
    return number;
}
string student:: get_dob() const
{
    return dob;
}
void display_data(student &s) // declaration of friend function
{
    cout<<"*******************************data of student ****************************************\n";
    cout<<"name         "<<s.name<<endl;
    cout<<"number         "<<s.number<<endl;
    cout<<"dob         "<<s.dob<<endl;
    cout<<"id           "<<s.id<<endl;
}
int main()
{
    student s1(101,"tushar gupta","19/10/2002","7746xxxxx"); // making object
    cout<<"name  "<<s1.get_name()<<endl;
    cout<<"number  "<<s1.get_num()<<endl;
    cout<<"dob  "<<s1.get_dob()<<endl;
    display_data(s1);

    // making const object
    const student s2(102,"rahul","10/2/11","56797xxxxxx");
    //cout<<"number  "<<s2.get_num()<<endl;  give error as const object cannot access non const objects
    return 0;
}
