// Suleyman Turker Guner - 21YZ0018 - LAB3 SOLUTION
// Coded for Data Structures Lecture in Summer School
// 04.08.2022

struct nodeClass
{
    int classID;
    double classMidtermAverage;
    struct nodeClass *next;
    struct nodeStudent *studentPtr;
};

struct nodeStudent
{
    int studentID;
    int midterm;
    struct nodeStudent *next;
};

// Represent the head and tail of the singly linked list
struct nodeClass *head, *tail = NULL;

// Represent the head and tail of the singly linked list
struct nodeStudent *head2, *tail2 = NULL;

void appendClass(struct nodeClass **head_ref, int new_class_id, double new_class_midterm_avarage)
{
    /* 1. allocate node */
    struct nodeClass *new_node = (struct nodeClass *)malloc(sizeof(struct nodeClass));

    struct nodeClass *last = *head_ref; /* used in step 5*/

    /* 2. put in the id  */
    new_node->classID = new_class_id;
    new_node->classMidtermAverage = new_class_midterm_avarage;

    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;
    new_node->studentPtr = NULL;

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

void appendStudent(struct nodeStudent **head_ref, int new_student_id, int new_student_midterm)
{
    /* 1. allocate node */
    struct nodeStudent *new_node = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));

    struct nodeStudent *last = *head_ref; /* used in step 5*/

    /* 2. put in the id  */
    new_node->studentID = new_student_id;
    new_node->midterm = new_student_midterm;

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

void ascendingSortListStudent()
{
    // Node current will point to head
    struct nodeStudent *current = head2, *index = NULL;
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
                if (current->studentID < index->studentID)
                {
                    temp = current->studentID;
                    temp2 = current->midterm;
                    current->studentID = index->studentID;
                    current->midterm = index->midterm;
                    index->studentID = temp;
                    index->midterm = temp2;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void ascendingSortListFirstClassStudent()
{
    int temp;
    int temp2;
    struct nodeStudent *curr = head2, *index = NULL;

    while (curr->next != NULL)
    {
        int m = curr->next->studentID;
        int n = curr->studentID;
        int x = curr->midterm;
        int y = curr->next->midterm;

        while (n >= 10) // FIRST DIGIT OF CURR->NEXT
        {
            n /= 10;
        }

        while (m >= 10) // FIRST DIGIT OF CURR->NEXT->STUDENTID
        {
            m /= 10;
        }

        if (n == 6)
        {
            
            if (curr->midterm < curr->next->midterm && m == 6)
            {
                temp = curr->studentID;
                temp2 = curr->midterm;
                curr->studentID = curr->next->studentID;
                curr->midterm = curr->next->midterm;
                curr->next->studentID = temp;
                curr->next->midterm = temp2;
            }

            printf("%d %d", curr->studentID, curr->midterm);
            printf("\n");
        }
        curr = curr->next;
    }
    printf("%d %d",curr->studentID,curr->midterm);
    printf("\n");
}

void ascendingSortListSecondClassStudent()
{
    int temp;
    int temp2;
    struct nodeStudent *curr = head2, *index = NULL;

    while (curr->next != NULL)
    {
        int m = curr->next->studentID;
        int n = curr->studentID;
        int x = curr->midterm;
        int y = curr->next->midterm;

        while (n >= 10) // FIRST DIGIT OF CURR->NEXT
        {
            n /= 10;
        }

        while (m >= 10) // FIRST DIGIT OF CURR->NEXT->STUDENTID
        {
            m /= 10;
        }

        if (n == 7)
        {
            if (curr->midterm < curr->next->midterm && m == 7)
            {
                temp = curr->studentID;
                temp2 = curr->midterm;
                curr->studentID = curr->next->studentID;
                curr->midterm = curr->next->midterm;
                curr->next->studentID = temp;
                curr->next->midterm = temp2;
            }

            printf("%d %d", curr->studentID, curr->midterm);
            printf("\n");
        }
        curr = curr->next;
    }
}

void ascendingSortListThirdClassStudent()
{
    int temp;
    int temp2;
    struct nodeStudent *curr = head2, *index = NULL;

    while (curr->next != NULL)
    {
        int m = curr->next->studentID;
        int n = curr->studentID;
        int x = curr->midterm;
        int y = curr->next->midterm;

        while (n >= 10) // FIRST DIGIT OF CURR->NEXT
        {
            n /= 10;
        }

        while (m >= 10) // FIRST DIGIT OF CURR->NEXT->STUDENTID
        {
            m /= 10;
        }

        if (n == 8)
        {
            if (curr->midterm < curr->next->midterm && m == 8)
            {
                temp = curr->studentID;
                temp2 = curr->midterm;
                curr->studentID = curr->next->studentID;
                curr->midterm = curr->next->midterm;
                curr->next->studentID = temp;
                curr->next->midterm = temp2;
            }

            printf("%d %d", curr->studentID, curr->midterm);
            printf("\n");
        }
        curr = curr->next;
    }
}

void ascendingSortListFourthClassStudent()
{
    int temp;
    int temp2;
    struct nodeStudent *curr = head2;

    while (curr->next != NULL)
    {
        int m = curr->next->studentID;
        int n = curr->studentID;
        int x = curr->midterm;
        int y = curr->next->midterm;

        while (n >= 10) // FIRST DIGIT OF CURR->NEXT
        {
            n /= 10;
        }

        while (m >= 10) // FIRST DIGIT OF CURR->NEXT->STUDENTID
        {
            m /= 10;
        }

        if (n == 9)
        {
            if (curr->midterm < curr->next->midterm && m == 9)
            {
                temp = curr->studentID;
                temp2 = curr->midterm;
                curr->studentID = curr->next->studentID;
                curr->midterm = curr->next->midterm;
                curr->next->studentID = temp;
                curr->next->midterm = temp2;
            }

            printf("%d %d", curr->studentID, curr->midterm);
            printf("\n");
        }
        curr = curr->next;
    }
}

// This function prints contents of linked list starting from head
void printListStudent(struct nodeStudent *nodeStudent)
{
    while (nodeStudent != NULL)
    {
        printf("%d %d\n", nodeStudent->studentID, nodeStudent->midterm);
        nodeStudent = nodeStudent->next;
    }
    printf("\n");
}

void printListClass(struct nodeClass *nodeClass, int index)
{
    int counter = 1;
    while (nodeClass != NULL)
    {
        if (counter == index)
        {
            printf("%d %0.2f\n", nodeClass->classID, nodeClass->classMidtermAverage);
        }
        nodeClass = nodeClass->next;
        counter++;
    }
}

float avarageFirstClass()
{
    struct nodeStudent *curr = head2;
    int counter = 0;
    int sum;
    float avg1;
    while (curr->next != NULL)
    {
        int m = curr->next->studentID;
        int n = curr->studentID;
        int x = curr->midterm;
        int y = curr->next->midterm;

        while (n >= 10) // FIRST DIGIT OF CURR->NEXT
        {
            n /= 10;
        }

        while (m >= 10) // FIRST DIGIT OF CURR->NEXT->STUDENTID
        {
            m /= 10;
        }
        if (m == 6 && n == 6)
        {
            if (counter >= 1)
            {
                sum += y;
            }
            else
            {
                sum = (float)x + (float)y;
            }
            counter++;
        }
        curr = curr->next;
    }
    avg1 = (float)sum / (float)(counter + 1);
    return avg1;
}

float avarageSecondClass()
{
    struct nodeStudent *curr = head2;
    int counter = 0;
    int sum;
    float avg1;
    while (curr->next != NULL)
    {
        int m = curr->next->studentID;
        int n = curr->studentID;
        int x = curr->midterm;
        int y = curr->next->midterm;

        while (n >= 10) // FIRST DIGIT OF CURR->NEXT
        {
            n /= 10;
        }

        while (m >= 10) // FIRST DIGIT OF CURR->NEXT->STUDENTID
        {
            m /= 10;
        }
        if (m == 7 && n == 7)
        {
            if (counter >= 1)
            {
                sum += y;
            }
            else
            {
                sum = (float)x + (float)y;
            }
            counter++;
        }
        curr = curr->next;
    }
    avg1 = (float)sum / (float)(counter + 1);
    return avg1;
}

float avarageThirdClass()
{
    struct nodeStudent *curr = head2;
    int counter = 0;
    int sum;
    float avg1;
    while (curr->next != NULL)
    {
        int m = curr->next->studentID;
        int n = curr->studentID;
        int x = curr->midterm;
        int y = curr->next->midterm;

        while (n >= 10) // FIRST DIGIT OF CURR->NEXT
        {
            n /= 10;
        }

        while (m >= 10) // FIRST DIGIT OF CURR->NEXT->STUDENTID
        {
            m /= 10;
        }
        if (m == 8 && n == 8)
        {
            if (counter >= 1)
            {
                sum += y;
            }
            else
            {
                sum = (float)x + (float)y;
            }
            counter++;
        }
        curr = curr->next;
    }
    avg1 = (float)sum / (float)(counter + 1);
    return avg1;
}

float avarageFourthClass()
{
    struct nodeStudent *curr = head2;
    int counter = 0;
    int sum;
    float avg1;
    while (curr->next != NULL)
    {
        int m = curr->next->studentID;
        int n = curr->studentID;
        int x = curr->midterm;
        int y = curr->next->midterm;

        while (n >= 10) // FIRST DIGIT OF CURR->NEXT
        {
            n /= 10;
        }

        while (m >= 10) // FIRST DIGIT OF CURR->NEXT->STUDENTID
        {
            m /= 10;
        }
        if (m == 9 && n == 9)
        {
            if (counter >= 1)
            {
                sum += y;
            }
            else
            {
                sum = (float)x + (float)y;
            }
            counter++;
        }
        curr = curr->next;
    }
    avg1 = (float)sum / (float)(counter + 1);
    return avg1;
}

void printAll()
{
    ascendingSortListStudent();
	appendClass(&head,1,avarageFirstClass());
	appendClass(&head,2,avarageSecondClass());
	appendClass(&head,3,avarageThirdClass());
	appendClass(&head,4,avarageFourthClass());
    printListClass(head,1);
	ascendingSortListFirstClassStudent();
	printListClass(head,2);
	ascendingSortListSecondClassStudent();
	printListClass(head,3);
	ascendingSortListThirdClassStudent();
	printListClass(head,4);
	ascendingSortListFourthClassStudent();
}