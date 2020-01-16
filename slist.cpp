#include "slist.h"
#include <iostream>

/*

Class Library File

*/
class Node{
  friend class slist;
  private:
    Airport* data;
    Node* next;
  public:
    Node(){
      data = NULL;
      next = NULL;

    }
};

// Constructor
slist::slist(){
  this->head = new Node; //make head node
  this->length = 0;
};

// Destructor
slist::~slist(){
  Node* cur = this->head;
  for(int i=0; i<length; i++){  //iterate through head to last element and delete everything
    Node* next = cur->next;
    delete(&cur); //delete literal value of curent Node ptr
    cur = next;
  }
};

// add(value)       //Adds a new value to the end of this list.
void slist::add(Airport* val){
  Node* last = this->head;

  Node* add = new Node;   //make new node with data and set last to point at it
  add->data = val;

  for(int i=0; i<length; i++){  //find last element
    last = last->next;
  }

  last->next = add;

  this->length++;
}

// clear()          //Removes all elements from this list.
void slist::clear(){
  Node* cur = head;
  for(int i=0; i<length; i++){  //go through from head to last and delete everything
    Node* next = cur->next;
    delete(&cur);
    length--;
    cur = next;
  }
}

// equals(list)       //Returns true if the two lists contain the same elements in the same order.
bool slist::equals(slist* list){
  Node* curA = head;
  Node* curB = list->head;
  
  for(int i=0; i<length; i++){  //run through all elements reutrn false if they don't match
    if(curA->data != curB->data){return false;}

    curA = curA->next;
    curB = curB->next;
  }

  return true; //return true if we survive
}

//get(index)        //Returns the element at the specified index in this list.
Airport* slist::get(int index){
  Node* cur = head;

  for(int i=0; i<length; i++){ //iterate through all values, so that bad input is protected from
    cur = cur->next;
    
    if(i == index){
      return cur->data;
    }
  }
  cout << "Error bad input to function |get|\n  Value: " << index <<  "\n length:" << length <<"\n";
  return NULL;
}

//insert(index, value)    //Inserts the element into this list before the specified index.
void slist::insert(int index, Airport* val){
  Node* cur = head;

  for(int i=0; i<length; i++){ //iterate through all values, so that bad input is protected from
    cur = cur->next;
    
    if(i == index){
      length++;
      Node* add = new Node;   //make new node with data
      add->data = val;
      
      add->next = cur->next; //fix the pntrs
      cur->next = add;
      return;                //in this contex just stops while returning void
    }
  }
  cout << "Error bad input to function |insert| \n    Value: " << index;  
}

//exchg(index1, index2)   //Switches the payload data of specified indexex.
void slist::exchg(int index1, int index2){  
  Node* cur = head;
  Node* i1 = NULL;
  Node* i2 = NULL;

  for(int i=0; i<length; i++){ //iterate through all values, so that bad input is protected from
    cur = cur->next;
    if(i1 != NULL && i2 != NULL){
      break;
    }
    
    if(i == index1){
      i1 = cur;       //sets i1 to value rught before i1
    }
    if(i == index2){
      i2 = cur;       //sets i1 to value rught before i2
    }
  }
  
  if(i1 == NULL || i2 == NULL){
    cout << "Error bad input to function |exchg| \n   Value: " << index1 << "\n   Value: " << index2 << "\n size:" << length << "\n";
  }
  
  Airport* hold;
  
  hold = i1->data;  //switch data
  i1->data = i2->data;
  i2->data = hold;
}

//swap(index1,index2)   //Swaps node located at index1 with node at index2
void slist::slist::swap(int index1, int index2){
  Node* cur = head;
  Node* pre1;
  Node* pre2;

  for(int i=0; i<length; i++){ //iterate through all values, so that bad input is protected from
    cur = cur->next;
    if(pre1 != NULL && pre2 != NULL){break;}
    
    if(i == index1){
      pre1 = cur;       //sets i1 to value rught before i1
    }
    if(i == index2){
      pre2 = cur;       //sets i1 to value rught before i2
    }
  }

  if(pre1 == NULL || pre2 == NULL){
    cout << "Error bad input to function |swap| \n    Value: " << index1 << "\n   Value: " << index2;
  }

  Node* i1 = pre1->next;  //setup
  Node* i2 = pre2->next;      
  Node* holder;

  holder = pre1->next;  //pre pointers
  pre1->next = pre2->next;
  pre2->next = holder;
  
  holder = i1->next;  //index pointers
  i1->next = i2->next;
  i2->next = holder;
}


// isEmpty()        //Returns true if this list contains no elements.
bool slist::isEmpty(){
  if(length == 0){return true;}
  return false;
}

// remove(index)      //Removes the element at the specified index from this list.
void slist::remove(int index){
  Node* cur = head;

  for(int i=0; i<length; i++){ //iterate through all values, so that bad input is protected from
    cur = cur->next;
    
    if(i == index){
      if(cur->next != NULL){ //checks if there is a next value and then fixes list
        cur->next = cur->next->next;
      }

      length--;     //removal
      delete(&cur);

      return;                //in this contex just stops while returning void
    }
  }
  cout << "Error bad input to function |remove| \n    Value: " << index;
}

// set(index, value)    //Replaces the element at the specified index in this list with a new value.
void slist::set(int index, Airport* val){
  Node* cur = head;

  for(int i=0; i<length; i++){ //iterate through all values, so that bad input is protected from
    cur = cur->next;
    
    if(i == index+1){
      cur->data = val;
      return;                //in this contex just stops while returning void
    }
  }
}

// size()         //Returns the number of elements in this list.
int slist::size(){
  return length;
}

// subList(start, length) //Returns a new list containing elements from a sub-range of this list.
slist* slist::subList(int sIn, int fIn){
  slist* justSomeDataThatIUsedToKnow = new slist;

  Node* butYouDidntHaveToCutMeUp = head;
  for(int i=0; i<length; i++){ //Now and then I think of when you were a member
    butYouDidntHaveToCutMeUp = butYouDidntHaveToCutMeUp->next;

    if(i == sIn){
      justSomeDataThatIUsedToKnow->head->next = butYouDidntHaveToCutMeUp->next;
    }
    if(i > sIn && i < fIn){
      justSomeDataThatIUsedToKnow->add(butYouDidntHaveToCutMeUp->data);
      remove(i);
    }
  }

  return justSomeDataThatIUsedToKnow; //NOW YOUR JUST SOME DATA THAT I USED TO KNOW
}

// toString()       //Converts the list to a printable string representation.
string slist::toString(){
  Node* cur = head;
  string str = "";

  for(int i=0; i<length; i++){ //iterate through all values, so that bad input is protected from
    cur = cur->next;

    str += cur->data->toString();
  }
  return str;
}