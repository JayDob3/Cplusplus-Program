#ifndef Contact_H
#define Contact_H
#include<string>
using namespace std;

class ContactNode{
public:
ContactNode();
ContactNode(string name, string phone);
void InsertAfter(ContactNode*);
string GetName();
string GetPhoneNumber();
ContactNode* GetNext();
void PrintContactNode();

private:
string contactName;
string contactPhoneNum;
ContactNode* nextNodePtr;
};
#endif

//Contacts.cpp:

#include <iostream>
using namespace std;

ContactNode::ContactNode(){
nextNodePtr=NULL;
}

ContactNode::ContactNode(string name, string phoneNum){
contactName=name;
contactPhoneNum=phoneNum;
nextNodePtr=NULL;
}
void ContactNode::InsertAfter(ContactNode *nextNode){
ContactNode *temp;
if(nextNodePtr==NULL)
nextNodePtr=nextNode;
else{
temp=nextNodePtr;
while(temp->nextNodePtr!=NULL){
temp=temp->GetNext();
}
temp->nextNodePtr=nextNode;   
}
}
string ContactNode::GetName(){
return contactName;
}
string ContactNode::GetPhoneNumber(){
return contactPhoneNum;
}
ContactNode* ContactNode::GetNext(){
return nextNodePtr;
}
void ContactNode::PrintContactNode(){
  
if(nextNodePtr!=NULL) {
cout<<"Name: "<<nextNodePtr->GetName()<<endl;
cout<<"Phone number: "<<nextNodePtr->GetPhoneNumber()<<endl<<endl;
  
GetNext()->PrintContactNode();
}
}

//main.cpp:

#include <iostream>
using namespace std;
int main()
{
   
ContactNode *List;
string Name;
string PhoneNum;
List=new ContactNode;
for(int i=0;i<3;i++){
cout<<"Person " << i+1<<endl;
cout<<"Enter name:"<<endl ;
getline(cin, Name);
cout<<"Enter phone number:"<<endl ;
getline(cin, PhoneNum);
cout<<"You entered: "<< Name << ", " << PhoneNum << endl << endl;
List->InsertAfter(new ContactNode(Name,PhoneNum));
}
cout<<"CONTACT LIST"<<endl;
List->PrintContactNode();
return 0;
}