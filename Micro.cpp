#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node * next;

	Node(int x){

		data = x;

		next = NULL;
	}

};

Node * head1 , *head2 , *tail1 , *tail2;


void insertOne(int data){

	Node * temp = new Node(data);

	tail1->next = temp;

	tail1 = temp;

}

void insertTwo(int data){

	Node * temp = new Node(data);

	tail2->next = temp;

	tail2 = temp;

}

void display(Node * temp){

	while(temp != NULL){

		cout << temp->data << " ";

		temp = temp->next;
	}
	cout << endl;
}

void removeDuplicates(Node * head){

	if(head->next == NULL)
		return ;

	Node * temp = head->next;
	
	Node * prev = head;

	while(temp != NULL){

		if(prev->data == temp->data){

			Node * temp1 = temp;

			temp = temp->next;

			prev->next = temp;

			delete(temp1);
		}
		else{

			prev = temp;

			temp = temp->next;

		}

	}



}

Node * Merge(Node * head1 , Node * head2){
	
	if(head1 == NULL)
		return head2;

	if(head2 == NULL)
		return head1;

	Node * temp;

	if(head1->data < head2->data){

		temp = new Node(head1->data);

		temp->next = Merge(head1->next , head2);
	}
	else{

		temp = new Node(head2->data);

		temp->next = Merge(head1 , head2->next);

	}

	removeDuplicates(temp);

	return temp;

	/*	
	if(head1 == NULL){
		removeDuplicates(head2);
		return head2;
	}

	if(head2 == NULL){
		removeDuplicates(head1);
		return head1;
	}

	Node * head;

	if(head1->data > head2->data)
		head = new Node(head2->data);
	else
		head = new Node(head1->data);

	Node * prev = head;

	while(head1 != NULL && head2 != NULL){

		Node * temp;

		if(head1->data < head2->data){

			temp = new Node(head1->data);

			head1 = head1->next;
		}
		else{

			temp = new Node(head2->data);

			head2 = head2->next;

		}

		prev->next = temp;

		prev = temp;
	}

	while(head1 != NULL){

		Node * temp = new Node(head1->data);

		prev->next = temp;

		prev = temp;

		head1 = head1->next;
	}	

	while(head2 != NULL){

		Node * temp = new Node(head2->data);

		prev->next = temp;

		prev = temp;

		head2 = head2->next;

	}

	removeDuplicates(head);

	return head;*/
}


int main(){

	head1 = new Node(1);
	head2 = new Node(4);

	tail1 = head1;

	tail2 = head2;

	insertOne(1);
	insertOne(1);
	insertOne(2);
	insertOne(3);
	insertOne(3);
	insertOne(4);
	insertOne(5);
	insertOne(10);

	insertTwo(4);
	insertTwo(4);
	insertTwo(5);
	insertTwo(5);
	insertTwo(8);
	insertTwo(8);
	insertTwo(9);

	display(head1);
	display(head2);

	Node * merged = Merge(head1 , head2);

	display(merged);
}
