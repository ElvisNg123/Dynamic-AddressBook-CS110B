#include <iostream>
using namespace std;

struct node
{
        string firstname;
        string lastname;
        string address; 
        string phone;
        struct node*next;

};

struct node* BuildData(){
    struct node*head = NULL;
    head = new node;
    return head; 
}

struct node* addEntry(struct node*head,int &count){
    struct node* newNode = new node;
  
    cout << "Add the full name of the user:" << endl;
    cin >> newNode-> firstname;
    cin >> newNode-> lastname;
    cout << "Add the address of the user:" << endl;
    cin >> newNode-> address;
    cout << "Add the phone of the user:" << endl;
    cin >> newNode-> phone;
    newNode->next=NULL;
    while(head != NULL){
      head = head->next;// Loop it 
    }
    head = newNode;
    count++; 
    cout << head-> firstname<<" "<< head-> lastname<< " successfully added to address book" << endl;
    return head;
    
    
}
struct node* updateContact(struct node*head,int &count){
  struct node* iter = head;
  bool matchFound = false;
  cout << "Which contact would you like to update? Please enter the name" << endl;
  string firstname_current, lastname_current;
  cin >> firstname_current;
  cin >> lastname_current;

  while (iter != NULL) {
     if(firstname_current == iter->firstname && lastname_current == iter->lastname){
            cout << "What is the updated name of " <<iter->firstname<<" "<<iter->lastname << "?" << endl;
            cin >> iter-> firstname;
            cin >> iter-> lastname;

            cout << "What is the updated number?" << endl;
            cin >> iter-> address;

            cout << "What is the updated address?" << endl;
            cin >> iter-> phone;
            matchFound = true;
      }
    iter = iter->next;
  }
  if (!matchFound){
        cout << "There was no match for that entry" << endl;
  }
  return iter; 
}

void searchContact(struct node*head,int &count)
{ 
  struct node* iter = head;
  bool matchFound = false;
  cout << "What is the full name of the user you are searching for?" << endl;
    string firstname_current, lastname_current;
    cin >> firstname_current;
    cin >> lastname_current;

  while (iter != NULL) {
     if(firstname_current == iter->firstname && lastname_current == iter->lastname){
      cout << "Here is the user's information" << endl;
      cout << iter->firstname<<" "<< iter->lastname<< endl;
      cout << iter->phone << endl;
      cout << iter->address << endl;

      matchFound = true;
    }
    iter = iter->next;
  }
  if (!matchFound){
        cout << "There was no match for that entry" << endl;
  }
}

void displayMenu()
{

    cout << "Menu" << endl;
    cout << "1) Add new contact" << endl;
    cout << "2) Update existing contact" << endl;
    cout << "3) Search for a contact" << endl;
    cout << "4) Quit" << endl;

}

int main(){
    struct node* myList = BuildData();
    bool keepPlaying = true;
    int count = 0;
    while (keepPlaying) {
        displayMenu();
        
        int menu_choice;
        cout << "Please choose an option";
        cin >> menu_choice;
        cout << myList-> firstname<<" "<< myList-> lastname<< endl;

        //address book array

        if (menu_choice == 1)
        {
            myList = addEntry(myList, count);
        } 
        else if (menu_choice == 2)
        {
            myList = updateContact(myList, count);
        }
        else if (menu_choice == 3)
        {
            searchContact(myList, count);
        }
        else if (menu_choice == 4)
        {
            keepPlaying = false;
        }
    }
        
}