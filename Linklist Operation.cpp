//Author:   Xin Junbo
//Date:  2014/10/28
//Modify:  fix some bugs on 1) hasCycle  2)merge_lists, 3)CycleBegin 
//add:  1)MergeSort
#include<iostream>
using namespace std;

struct Linklist
{
	int val;
	struct Linklist* next;
};
//***********************************Insert Node before the head of the Linklist***************************
Linklist* Insert_Node_Before_Head(Linklist* head, int key)
{
	  Linklist* newhead = (Linklist*)malloc(sizeof(Linklist));
	  newhead -> val = key;
	  newhead -> next = NULL;
	  if(NULL == head){
		  head = newhead;
		  return head;;
	  }
	  newhead -> next = head;
	  head = newhead;
	  return head;
}

//***********Insert Node after the tail of the Linklist***************
Linklist* Insert_Node_After_Tail(Linklist* head, int key)
{
	 Linklist* newhead = (Linklist*)malloc(sizeof(Linklist));
	 newhead -> val = key;
	 newhead -> next = NULL;
	 if(NULL == head) {
		   head = newhead;
		   return head;
	 }
     Linklist* cur = head;
	 while(NULL != cur -> next){
		 cur = cur -> next;
	 }
	 cur -> next = newhead;
	 return head;
}
 
//****************Delete the node by given the value***************
void Delete_Node_GivienKey(Linklist* head, int key)
{
	   if(NULL == head) return;
	   Linklist* cur = head;
	   Linklist* pre;
	   while(NULL != cur && cur -> val != key){
		    pre = cur;
			cur = cur -> next;
	   }
	   if(NULL == cur)
		   pre -> next = NULL;
	   else
		   pre -> next = cur -> next;
}

//***************Delete the node by given the Node*****************
void Delete_Node_GivenNode(Linklist * head, Linklist* pToBeDeleted){
	 if(head == NULL || pToBeDeleted == NULL) return;
	 if( pToBeDeleted -> next != NULL){
		 //not the tail of the Linklist, delete it in O(1) time complexity
		    Linklist* nex = pToBeDeleted -> next;
			pToBeDeleted -> val = nex -> val;
			pToBeDeleted -> next = nex -> next;
			delete nex;
			nex = NULL;
			//tail of the Linklist, deted it in O(n) time complexity
	 } else if(head == pToBeDeleted){
		   delete pToBeDeleted;
		   pToBeDeleted = NULL;
		   head = NULL;
	 }else{
		   Linklist* cur = head;
		   while(cur -> next != pToBeDeleted){
			   cur = cur -> next;
		   }
		   cur -> next = NULL;
		   delete pToBeDeleted;
		   pToBeDeleted = NULL;
   }
}

//*******************Finde Middle of the Linklist*****************
	Linklist* FindMiddle(Linklist* head){
		 if(head == NULL || head -> next)  return head;
		 Linklist* slow = head;
		 Linklist* fast = head -> next;
		 while(fast != NULL && fast -> next != NULL){
			 slow = slow -> next;
			 fast = fast -> next -> next;
		 }
		 return slow;
	 }

//***********************Reverse the Linklist*****************
	Linklist* Reverse(Linklist* head){
		if(head == NULL || head -> next == NULL) return head;
		Linklist* pre = NULL;
		Linklist* cur = head;
		Linklist* nex;
		while(cur != NULL){
			nex =  cur -> next;
			cur -> next = pre;
			pre = cur;
			cur = nex;
		}
		return pre;
	}

//*************************Has Cycle************************
 bool hasCycle(Linklist* head){
	 if(head == NULL || head -> next == NULL) return false;
	 Linklist* slow = head;
	 Linklist* fast = head;
	 while(fast != NULL && fast -> next != NULL){
		 slow = slow -> next;
		 fast = fast -> next -> next;;
		 if(slow == fast) return true;
	 }
	 return false;
 }

 //*********************where the cycle begins*****************
 Linklist* CycleBegin(Linklist* head){
	 if(head == NULL || head -> next == NULL) return NULL;
	 Linklist* slow, *fast;
	 while(fast != NULL && fast -> next != NULL && fast != slow){
		 slow = slow -> next;
		 fast = fast -> next -> next;
		 if(slow == fast) break;
	 }
	     if(fast == NULL) return NULL;
		 slow = head;
		 while(slow != fast){
			 slow = slow -> next;
			 fast = fast -> next;
		 }
		 return slow;
 }

 //***********************merge two lists*******************
 Linklist* merge_lists(Linklist* L1, Linklist* L2){
	   Linklist* dummy = (Linklist*)malloc(sizeof(Linklist));
	   Linklist * cur = dummy;
	   while(L1 != NULL && L2 != NULL){
		   if(L1 -> val < L2 -> val){
			   cur -> next = L1;
			   L1 = L1 -> next;
		    } else {
			   cur -> next = L2;
			   L2 = L2 -> next;
		    }
		   cur = cur -> next;
	   }
	   if(L1 != NULL) cur -> next = L1;
	   if(L2 != NULL) cur -> next = L2;
	   return dummy -> next;
 }
 
 //*******************find Kth Node**************************
Linklist* findKthNode(Linklist* head, int k){
	 if(head == NULL || k == 0) return NULL;
	 Linklist* fast, *slow;
	 fast = slow = head;
	 int count = 0;
	 while(fast !=NULL){
		 fast = fast -> next;
		 count++;
		 if(count > k)
			 slow = slow -> next;
	 }
	 return slow;
}

//**************Linklist sort using mergeSort alogrithm**************
Linklist* merge(Linklist* head1, Linklist* head2){
	 Linklist* dummy = (Linklist*)malloc(sizeof(Linklist));
	 Linklist* p = dummy;
	 if(head1 == NULL) return head2;
	 if(head2 == NULL) return head1;
	 while(head1 != NULL && head2 != NULL){
		  if(head1 -> val < head2 -> val){
			  p -> next = head1;
			  head1 = head1 -> next;
	        }else{
			   p -> next = head2;
			   head2 = head2 -> next;
		  }
		  p = p -> next;
	 }
	 if(head1 != NULL) p -> next = head1;
	 if(head2 != NULL) p -> next = head2;
	 return dummy -> next;
}

Linklist* mergeListSort(Linklist* head){
	if(head == NULL || head -> next == NULL)
		return head;
	Linklist* slow = head;
	Linklist* fast = head -> next;
	while(fast != NULL && fast -> next != NULL){
		slow =  slow -> next;
		fast    = fast   -> next -> next;
	}
	Linklist *first = head;
	Linklist *second = slow -> next;
	slow -> next = NULL;

	Linklist* newhead = merge(mergeListSort(first), mergeListSort(second));
	return newhead;
}

	  
int main(void){
	int arr[] = {3,2,25,5,1,8,4,7};
	Linklist* dummy = (Linklist*)malloc(sizeof(Linklist));
	Linklist* cur = dummy;
	for(int i=0; i< sizeof(arr)/sizeof(int); ++i){
		Linklist* temp = (Linklist*)malloc(sizeof(Linklist));
		temp -> val = arr[i];
		cur -> next = temp;
		cur = cur -> next;
	}
	cur -> next = NULL;
   
	 Linklist* findKth = findKthNode(dummy->next,10);
	 cout << findKth -> val << endl;
	 getchar();
	 return 0;
}
