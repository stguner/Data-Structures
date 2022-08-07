// Suleyman Turker Guner - 21YZ0018 - LAB3 SOLUTION
// Coded for Data Structures Lecture in Summer School
// 02.08.2022

struct nodeFB
{
  int id;
  int age;
  struct nodeFB *next;
};

struct nodeGS
{
  int id;
  struct nodeGS *next;
};

// Represent the head and tail of the singly linked list
struct nodeGS *head, *tail = NULL;

// Represent the head and tail of the singly linked list
struct nodeFB *head2, *tail2 = NULL;

// This function prints contents of linked list starting from head
void printListGS(struct nodeGS *nodeGS)
{
  while (nodeGS != NULL)
  {
    printf("%d \n", nodeGS->id);
    nodeGS = nodeGS->next;
  }
}

// This function prints contents of linked list starting from head
void printListFB(struct nodeFB *nodeFB)
{
  while (nodeFB != NULL)
  {
    printf("%d %d\n", nodeFB->id, nodeFB->age);
    nodeFB = nodeFB->next;
  }
  printf("\n");
}

void printElementFB(struct nodeFB *nodeFB,int index)
{
  int counter=1;
  while (index > counter)
  {
    nodeFB = nodeFB->next;
    counter++;
  }
  printf("%d %d", nodeFB->id, nodeFB->age);
  printf("\n");
}



void printElementGS(struct nodeGS *nodeGS,int index)
{
  int counter=1;
  while (index > counter)
  {
    nodeGS = nodeGS->next;
    counter++;
  }
  printf("%d", nodeGS->id);
  printf("\n");
}

void appendGS(struct nodeGS **head_ref, int new_id)
{
  /* 1. allocate node */
  struct nodeGS *new_node = (struct nodeGS *)malloc(sizeof(struct nodeGS));

  struct nodeGS *last = *head_ref; /* used in step 5*/

  /* 2. put in the id  */
  new_node->id = new_id;

  /* 3. This new node is going to be the last node, so make next of
        it as NULL*/
  new_node->next = NULL;

  /* 4. If the Linked List is empty, then make the new node as head */
  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }

  /* 5. Else traverse till the last node */
  while (last->next != NULL)
    last = last->next;

  /* 6. Change the next of last node */
  last->next = new_node;
  return;
}

void appendFB(struct nodeFB **head_ref2, int new_id, int new_age)
{
  /* 1. allocate node */
  struct nodeFB *new_node = (struct nodeFB *)malloc(sizeof(struct nodeFB));

  struct nodeFB *last = *head_ref2; /* used in step 5*/

  /* 2. put in the id and age  */
  new_node->id = new_id;
  new_node->age = new_age;

  /* 3. This new node is going to be the last node, so make next of
        it as NULL*/
  new_node->next = NULL;

  /* 4. If the Linked List is empty, then make the new node as head */
  if (*head_ref2 == NULL)
  {
    *head_ref2 = new_node;
    return;
  }

  /* 5. Else traverse till the last node */
  while (last->next != NULL)
    last = last->next;

  /* 6. Change the next of last node */
  last->next = new_node;
  return;
}

void descendingSortListGS()
{
  // Node current will point to head
  struct nodeGS *current = head, *index = NULL;
  int temp;

  if (head == NULL)
  {
    return;
  }
  else
  {
    while (current != NULL)
    {
      // Node index will point to node next to current
      index = current->next;

      while (index != NULL)
      {
        // If current node's id is greater than index's node id, swap the id between them
        if (current->id < index->id)
        {
          temp = current->id;
          current->id = index->id;
          index->id = temp;
        }
        index = index->next;
      }
      current = current->next;
    }
  }
}

void ascendingSortListFB()
{
  // Node current will point to head
  struct nodeFB *current = head2, *index = NULL;
  int temp;
  int temp2;

  if (head2 == NULL)
  {
    return;
  }
  else
  {
    while (current != NULL)
    {
      // Node index will point to node next to current
      index = current->next;

      while (index != NULL)
      {
        // If current node's id is greater than index's node id, swap the id between them
        if (current->id > index->id)
        {
          temp = current->id;
          temp2 = current->age;
          current->id = index->id;
          current->age = index->age;
          index->id = temp;
          index->age = temp2;
        }
        index = index->next;
      }
      current = current->next;
    }
  }
}


