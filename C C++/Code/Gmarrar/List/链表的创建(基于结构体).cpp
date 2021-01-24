#include<iostream>
using namespace std;
struct Stu {
	string name;
	int num;
	Stu *next;
};

//链表的建立
struct Stu *creatList(void) {
	struct Stu *head,*p1,*p2;
	p1=p2=new Stu;
	cin>>p1->name >>p1->num ;
	head=NULL;
	while(p1->num!=0) {	
		if(head==NULL) {
			head=p1;
		} 
		else {
			p2->next=p1;
		}
		p2=p1;
		p1= new Stu;
		cin>>p1->name >>p1->num ;
	}
	//封口 
	p2->next =NULL;
	return head;
}

//链表的输出
void printList(Stu *head){
	Stu *p;
	p=head;
	if(head!=NULL){
		do{
			cout<<"姓名:"<<p->name<<" "<<"学号:"<<p->num<<endl;
			p=p->next;
		}while(p!=NULL);
	}
} 

//链表的删除
struct Stu *deleteList(Stu *head,int num){
	Stu *p1,*p2;
	if(head==NULL){
		cout<<"Iist is NULL!"<<endl;
		return head; 
	}
	p1=head;
	while(num!=p1->num&&p1->next!=NULL){
		p2=p1;
		p1=p1->next; 	
	}
} 

int main() {
    Stu *head;
    head=creatList();
	printList(head);
	return 0; 
}
