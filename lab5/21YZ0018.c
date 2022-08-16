// Suleyman Turker Guner - 21YZ0018 - LAB5 SOLUTION
// Coded for Data Structures Lecture in Summer School
// 12.08.2022

#include <stdio.h>
#include <stdlib.h>

// struct to represent node in linked list as queue
struct node_customer {
    int id; 
    int arrival; 
    int process; 
    int wait; 
    int employeeid; 
    int start; 
    int end; 
    struct node_customer* next; 
};
typedef struct node_customer* Customer;

// struct to represent Queue
struct linked_list_queue {
    Customer start; 
    Customer end; 
};
typedef struct linked_list_queue* Queue;

// struct to represent node in linked list as stack
struct node_employee {
    int id;
    int total; 
    int remining; 
    struct node_employee* next; 
};
typedef struct node_employee* Employee;

// struct to represent Stack
struct linked_list_stack {
    Employee top; 
};
typedef struct linked_list_stack* Stack;

// queue is FIFO implementation
// functions for queue
// create an empty queue
Queue create_queue();
// delete the queue
void destroy_queue(Queue q);
// create a customer struct
Customer create_customer();
// insert element at end of queue
void enqueue(Customer c, Queue q);
// remove first element from queue
Customer dequeue(Queue q);
// print elements of queue
void print_queue(Queue q);

// stack is LIFO implementation
// functions for stack
// create an empty stack
Stack create_stack();
// delete the stack
void destroy_stack(Stack s);
// create a employee struct
Employee create_employee();
// insert element at top of stack
void push(Employee e, Stack s);
// remove top element from stack
Employee pop(Stack s);
// print elements of stack
void print_stack(Stack s);

// main function to run the program
int main() {
    // create Stack and Queue to simulate the Bank
    Stack s = create_stack();
    Queue q = create_queue();

    // open input file to read data
    FILE* file;
    file = fopen("inputLAB5.txt", "r"); // open file in read mode
    // input file contains customer data
    int data;
    while (1) {
        // end of file is marker with -1;
        // each line of file contains customer id, arraival time and process time
        // first data is customer id
        // read first data from line
        fscanf(file, "%d", &data);
        // check for end of file
        if (data == -1) {
            // done reading data end the loop
            break;
        }
        // create a customer object to read data into customer
        Customer c = create_customer();
        // set customer id
        c->id = data;
        // second data is arraival time
        fscanf(file, "%d", &data);
        c->arrival = data;
        // third data is process time
        fscanf(file, "%d", &data);
        c->process = data;
        // add the customer to queue
        enqueue(c, q);
    }

    // initalize stack of employee
    // bank has 6 employee and id starting from 1 to 6
    for (int i = 1; i <= 6; i++) {
        // create an employee
        Employee e = create_employee();
        // set id of employee
        e->id = i;
        // add employee to the stack
        push(e, s);
    }

    // start the simulation of bank
    int time = 1; // start time from begining of 1st minute
    // create a queue to represent processed customers
    Queue processed = create_queue();
    // create a stack to represent currently working employees
    Stack working = create_employee();
    // run it till there is no customer in bank
    while (q->start != NULL) {
        // check if any employee has finished working
        // create iterator to iterate over stack
        Employee itr = working->top;
        while (itr != NULL) {
            // process time
            itr->remining--; // remove one minute as time passed by 1 minute of simulation
            // if remainign time for employee is 0 minute then employee is finished
            // processing that customer at this iteraton of time
            if (itr->remining == 0) {
                // add the employee on top of stack
                // remove employee from working stack
                if (itr == working->top) {
                    // if its top element then just pop it
                    Employee temp = pop(working);
                    push(temp, s);
                    itr = working->top;
                }
                else {
                    // create a loop and remove that element
                    Employee itr2 = working->top;
                    while (itr2->next != itr) {
                        itr2 = itr2->next;
                    }
                    itr2->next = itr->next;
                    push(itr, s);
                    itr = itr2->next;
                }
            }
            else {
                itr = itr->next;
            }
        }
        // if there there is an employee available he/she will process the customer
        while (s->top != NULL) {
            // get the customer from queue and start processing
            if (q->start->arrival <= time) {
                Customer c = dequeue(q);
                // remove an employee and assign them to customer
                Employee e = pop(s);
                c->employeeid = e->id;
                // set process start time
                c->start = time;
                // set wait time
                c->wait = time - c->arrival;
                // set process end time
                c->end = time + c->process;
                // incerase service time of employee
                e->total += c->process;
                // set remaining time for employee
                e->remining = c->process;
                // add customer to processed queue
                enqueue(c, processed);
                // add employee to working queue
                push(e, working);
            }
            else {
                // if no customer left to process finish simulation
                break;
            }
        }
        // if no employee available then customer will wait
        time++;
    }
    // when simulation finish finsh all employee's work and add them in sorted order by ids
    // to print the data on console
    while (working->top != NULL) {
        Employee e = pop(working);
        push(e, s);
    }
    
    // print simulation data
    print_queue(processed);
    printf("\n");
    print_stack(s);
    
    // delete all stuctures to free memory
    destroy_stack(s);
    destroy_stack(working);
    destroy_queue(q);
    destroy_queue(processed);
    return 0;
}

// function definitions
Queue create_queue() {
    // assign memory
    Queue q = (Queue)malloc(sizeof(struct linked_list_queue));
    // initialize queue
    q->start = NULL;
    q->end = NULL;
    return q;
}

void destroy_queue(Queue q) {
    // delete each node in q
    while (q->start != NULL) {
        Customer c = dequeue(q);
        free(c);
    }
    // delete queue
    free(q);
}

Customer create_customer() {
    // assign memory
    Customer c = (Customer)malloc(sizeof(struct node_customer));
    // initialize data
    c->arrival = 0;
    c->id = 0;
    c->process = 0;
    c->wait = 0;
    c->employeeid = 0;
    c->start = 0;
    c->end = 0;
    c->next = NULL;
    return c;
}

void enqueue(Customer c, Queue q) {
    // if queue is empty add customer as only element of queue
    if (q->start == NULL) {
        q->start = q->end = c;
    }
    else {
        // add customer to end of queue
        q->end->next = c;
        // update end of queue
        q->end = c;
    }
}

Customer dequeue(Queue q) {
    // remove customer from front of queue
    Customer c = q->start;
    // remove element from queue
    // update start
    q->start = q->start->next;
    c->next = NULL;
    return c;
}

void print_queue(Queue q) {
    // create iterator to iterate over queue
    Customer itr = q->start;
    // print each customer in new line
    while (itr != NULL) {
        // print customer id, employee id, transaction start time, transaction end time and total wait time
        printf("%d %d %d %d %d\n", itr->id, itr->employeeid, itr->start, itr->end, itr->wait);
        itr = itr->next;
    }
}

Stack create_stack() {
    // assign memory
    Stack s = (Stack)malloc(sizeof(struct linked_list_stack));
    // initialize data
    s->top = NULL;
}

void destroy_stack(Stack s) {
    // delete each node from stack
    while (s->top != NULL) {
        Employee e = pop(s);
        free(e);
    }
    // delete stack
    free(s);
}

Employee create_employee() {
    // assign memory
    Employee e = (Employee)malloc(sizeof(struct node_employee));
    // initialize data
    e->id = 0;
    e->total = 0;
    e->remining = 0;
    e->next = NULL;
    return e;
}

void push(Employee e, Stack s) {
    // add employee at top of stack
    e->next = s->top;
    // update top of stack
    s->top = e;
}

Employee pop(Stack s) {
    // remove employee from top of stack
    Employee e = s->top;
    // update stack
    s->top = s->top->next;
    e->next = NULL;
    return e;
}

void sort_stack(Stack s) {
    Stack sorted = create_stack();
    for (int i = 6; i > 0; i--) {
        Employee prev = NULL;
        Employee curr = s->top;
        while (curr != NULL) {
            if (curr->id == i) {
                if (prev == NULL) {
                    curr = pop(s);
                    push(curr, sorted);
                    curr = s->top;
                }
                else {
                    prev->next = curr->next;
                    push(curr, sorted);
                    curr = prev->next;
                }
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    // add elemnet in reverse order to sort in decending order
    for (int i = 0; i < 6; i++) {
        Employee e = pop(sorted);
        push(e, s);
    }
    destroy_stack(sorted);
}

void print_stack(Stack s) {
    // sort the stack before printing
    sort_stack(s);
    // create iterator to iterate over stack
    Employee itr = s->top;
    // print each employee in new line
    while (itr != NULL) {
        // print employee id and total service time
        printf("%d %d\n", itr->id, itr->total);
        itr = itr->next;
    }
}