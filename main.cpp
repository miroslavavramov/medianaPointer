#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int countDataSize = 0;
int printMiddle = 0;

struct Node
{
  int data;
  struct Node *next;
};

void addSorted(struct Node** head, struct Node* newNode)
{
  struct Node* current = *head;
  struct Node* midle = *head;

  if (current == nullptr)
  {
     newNode->next = newNode;
     *head = newNode;
  }

  else if (current->data >= newNode->data)
  {


    while(current->next != *head)
    {
        current = current->next;
        if(countDataSize & 1)
            midle = midle->next;

        ++countDataSize;
    }

    //if(midle != *head)
        printMiddle = midle->data;

    current->next = newNode;
    newNode->next = *head;
    *head = newNode;
    //cout<< "temp countDataSize = "<< countDataSize << "midle->data = "<< midle->data << " current = "<< current->data <<endl;
  }

  else
  {


    while (current->next!= *head &&
           current->next->data < newNode->data)
    {
      current = current->next;
      if(countDataSize % 2 == 0)
          midle = midle->next;

      ++countDataSize;
    }

        printMiddle = midle->data;

    newNode->next = current->next;
    current->next = newNode;

    //cout<< "temp countDataSize = "<< countDataSize << "midle->data = "<< midle->data << " current = "<< current->data <<endl;
  }
}

void printMediana()
{
     cout<< "Mediana odd = " << printMiddle << " countDataSize = "<< countDataSize <<endl;
}

int main()
{
  vector<int> arr = {250, 250, 250, 150, 150, 150, 150, 150, 150, 150, 150,
                     250, 250,  300,
                      300, 150, 300,
                     600, 150,600, 150, 1250,1500, 600};

  struct Node *start = nullptr;
  struct Node *temp;

  std::cout << "Please enter some integers (enter 0 to end):\n";
  //  do {
  //    std::cin >> i;

  //    temp = new Node();
  //    if(i > 0){
  //    temp->data = i;
  //    addSorted(&start, temp);
  //    countDataSize++;
  //    }
  //  } while (i);

  for (int i = 0; i< arr.size(); i++)
   {
     temp = new Node();
     temp->data = arr[i];
     addSorted(&start, temp);
   }

   //countDataSize = arr.size();

   printMediana();

  return 0;
}
