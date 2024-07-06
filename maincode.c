#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
#define SIZE 4
#define QSIZE 5
#define CSIZE 5

struct node
{
    int datac;
    struct node *nextc;
};

struct NodeSl {
    int data;
    struct NodeSl* next;
};

struct Noded {
    int data;
    struct Noded* nextd;
    struct Noded* prevd;
};

struct Nodeb {
    int key;
    struct Nodeb* left;
    struct Nodeb* right;
};

struct Nodebst {
    int keyb;
    int level;
    struct Nodebst *leftb, *rightb;
};
void displayAllLinkedLists();
int displayCircularQueue();
void typesofSorting();

int deleteElement(int arr[], int *size, int element);
void displaySinglyLinkedListfun(struct NodeSl* Shead);
void displayCircular(struct node *headc);
int top = -1, stack[SIZE];
int queue[QSIZE];

int queueC[CSIZE];
int frontC = -1, rearC = -1;
int front = -1, rear = -1;

// Global Shead pointer for the linked list
struct NodeSl* Shead = NULL;
struct Noded* headd = NULL;
struct Noded* tempd = NULL;
struct Noded* newNoded = NULL;
struct Noded* taild = NULL;
struct node *headc = NULL, *tempc, *newNode, *tailc;



//------------------------Array Starts Here----------------------------------------------------------------------------------------
void displayWorkingArray(int arr[], int size) {
    printf("\nArray elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found in the array
}

// Function to insert an element into the array
int insertElements(int arr[], int *size, int capacity) { // Corrected function name
    int numElements;

    printf("\nEnter the number of elements to insert: ");
    scanf("%d", &numElements);

    if (*size + numElements <= capacity) {
        printf("\nEnter %d elements:\n", numElements);
        for (int i = 0; i < numElements; i++) {
            scanf("%d", &arr[*size]);
            (*size)++;
        }
        return 1; // Insertion successful
    }

    return 0; // Array is full
}

// Function to delete an element from the array
int deleteElement(int arr[], int *size, int element) {
    int position = searchElement(arr, *size, element);

    if (position != -1) {
        // Shift elements to the left to fill the gap
        for (int i = position; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        return 1; // Deletion successful
    }

    return 0; // Element not found in the array
}


void seeArrayFunctioning(int *on) {
    int array[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    do {
        // Menu
    printf(" ______________________________________\n");
    printf("|           **MENU**                   |\n");
    printf("| 1. Display Array                     |\n");
    printf("| 2. Search Element                    |\n");
    printf("| 3. Insert Element                    |\n");
    printf("| 4. Delete Element                    |\n");
    printf("| 5. Exit                              |\n");
    printf("|______________________________________|\n");


        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayWorkingArray(array, size);
                break;

            case 2:
                printf("\nEnter the element to search: ");
                scanf("%d", &element);
                position = searchElement(array, size, element);
                if (position != -1) {
                    printf("\nElement found at index %d.\n", position);
                } else {
                    printf("\nElement not found in the array.\n");
                }
                break;

            case 3:
                if (insertElements(array, &size, MAX_SIZE)) { // Corrected function name
                    printf("\nElements inserted successfully.\n");
                } else {
                    printf("\nArray is full. Cannot insert more elements.\n");
                }
                break;

            case 4:
                printf("\nEnter the element to delete: ");
                scanf("%d", &element);
                if (deleteElement(array, &size, element)) {
                    printf("\nElement deleted successfully.\n");
                } else {
                    printf("\nElement not found in the array. Deletion failed.\n");
                }
                break;

            case 5:
                printf("\nExiting the program.\n");
                *on = 0;
                break;

            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }

    } while (choice!=5);

}


void displayArray() {
        int on;
    // Display theory and code for arrays
    printf("\n----------------------------------------------------------------------------------------Array-----------------------------------------------------------------------------------------------------\n");
    printf("\nAn array in C is a fixed-size collection of similar data items stored in contiguous memory locations. It can be used to store the collection of primitive data types such as int, char, float, etc., and also derived and user-defined data types such as pointers, structures, etc.\n\n");

    printf("C Array Declaration:\n");
    printf("In C, we have to declare the array like any other variable before using it. We can declare an array by specifying its name, the type of its elements, and the size of its dimensions. When we declare an array in C, the compiler allocates the memory block of the specified size to the array name.\n\n");

    printf("Syntax of Array Declaration:\n");
    printf("data_type array_name [size];\n");
    printf("         or\n");
    printf("data_type array_name [size1] [size2]...[sizeN];\n\n");
    printf("where N is the number of dimensions.\n");

    printf("\nExample Code:\n");
    printf("\n");
    printf("#include <stdio.h>\n\n");
    printf("int main() {\n");
    printf("    // array declaration and initialization\n");
    printf("    int arr[5] = {10, 20, 30, 40, 50};\n");
    printf("\n");
    printf("    // modifying element at index 2\n");
    printf("    arr[2] = 100;\n");
    printf("\n");
    printf("    // traversing array using for loop\n");
    printf("    printf(\"Elements in Array: \");\n");
    printf("    for (int i = 0; i < 5; i++) {\n");
    printf("        printf(\"%%d \", arr[i]);\n");
    printf("    }\n");
    printf("\n");
    printf("    return 0;\n");
    printf("}\n");
    printf("\n\n");
    printf("   ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Want to See the Functioning?                      |\n");
    printf("  | Press 1 to see, otherwise Press 0 for Cancel:     |\n");
    printf("  |___________________________________________________|\n");

    printf("\nEnter Your Choice:\t");
    scanf("%d",&on);
   do {
        switch (on) {
            case 1:
                seeArrayFunctioning(&on);
                break;
            case 0:
                printf("\nEnjoy Learning!!\n");
                break;
            
            default:
            printf("\nInvalid Choice\n");
            on=0;
            break;
        }

    } while (on != 0);


}

//------------------------Array Part End Here----------------------------------------------------------------------------------------









//------------------------Linked List Explanation Starts Here----------------------------------------------------------------------------------------

void displayLinkedList() {
    printf("\n------------------------------------------------------------------------------------Linked List-----------------------------------------------------------------------------------------------------\n");

    printf("\nLinked List is a linear data structure, in which elements are not stored at a contiguous location, "
           "rather they are linked using pointers. Linked List forms a series of connected nodes, where each node "
           "stores the data and the address of the next node.\n\n");
    
    printf("Node Structure: A node in a linked list typically consists of two components:\n");
    printf("Data: It holds the actual value or data associated with the node.\n");
    printf("Next Pointer: It stores the memory address (reference) of the next node in the sequence.\n\n");

    printf("Shead and Tail: The linked list is accessed through the Shead node, which points to the first node in the list. "
           "The last node in the list points to NULL or nullptr, indicating the end of the list. This node is known as the tail node.\n\n");

    printf("Why linked list data structure needed?\n");
    printf("Here are a few advantages of a linked list:\n");
    printf("- Dynamic Data structure: The size of memory can be allocated or de-allocated at runtime based on the operation insertion or deletion.\n");
    printf("- Ease of Insertion/Deletion: The insertion and deletion of elements are simpler than arrays since no elements need to be shifted after insertion and deletion, Just the address needed to be updated.\n");
    printf("- Efficient Memory Utilization: As we know Linked List is a dynamic data structure, the size increases or decreases as per the requirement, so this avoids the wastage of memory.\n");
    printf("- Implementation: Various advanced data structures can be implemented using a linked list like a stack, queue, graph, hash maps, etc.\n\n");

    printf("\nTypes of LinkedList are:\n");
    
    // Single-linked list
    printf("1. Single-linked list:\n");
    printf("   In a singly linked list, each node contains a reference to the next node in the sequence. "
           "Traversing a singly linked list is done in a forward direction.\n");
    printf("   Single-linked list\n");
    
    // Double-linked list
    printf("\n2. Double-linked list:\n");
    printf("   In a doubly linked list, each node contains references to both the next and previous nodes. "
           "This allows for traversal in both forward and backward directions, but it requires additional memory for the backward reference.\n");
    printf("   Double-linked list\n");
    
    // Circular linked list
    printf("\n3. Circular linked list:\n");
    printf("   In a circular linked list, the last node points back to the Shead node, creating a circular structure. "
           "It can be either singly or doubly linked.\n");
    printf("   Circular linked list\n\n");

    displayAllLinkedLists();
}







//--------------------------------------------------Singly Linked List----------------------------------------------------------------------------------------


void displaySinglyLinkedListfun(struct NodeSl* Shead) {
    struct NodeSl* current = Shead;

    printf("\nLinked List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


// Function to insert an element at the beginning of a singly linked list
struct NodeSl* insertAtBeginningSingly(struct NodeSl* Shead) {
    int value;
    printf("\nEnter the element to insert at the beginning: ");
    scanf("%d", &value);

    struct NodeSl* newNodeSl = (struct NodeSl*)malloc(sizeof(struct NodeSl));
    if(newNodeSl == NULL) {
        printf("Memory allocation failed. Insertion failed.\n");
        exit(EXIT_FAILURE);
    }
    newNodeSl->data = value;
    newNodeSl->next = Shead;
    displaySinglyLinkedListfun(Shead);
    
    return newNodeSl;
}

// Function to insert an element at the end of a singly linked list
struct NodeSl* insertAtEndSingly(struct NodeSl* Shead) {
    int value;
    printf("\nEnter the element to insert: ");
    scanf("%d", &value);

    struct NodeSl* newNodeSl = (struct NodeSl*)malloc(sizeof(struct NodeSl));
    if(newNodeSl == NULL) {
        printf("Memory allocation failed. Insertion failed.\n");
        exit(EXIT_FAILURE);
    }
    newNodeSl->data = value;
    newNodeSl->next = NULL;

    if (Shead == NULL) {
        // If the list is empty, the new NodeSl becomes the Shead
        return newNodeSl;
    }

    // Traverse to the end of the list and append the new NodeSl
    struct NodeSl* current = Shead;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNodeSl;
    return Shead;
}

// Function to delete an element from a singly linked list
struct NodeSl* deleteElementSingly(struct NodeSl* Shead) {
    int value;
    printf("\nEnter the element to delete: ");
    scanf("%d", &value);

    struct NodeSl* current = Shead;
    struct NodeSl* previous = NULL;

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nElement not found in the linked list. Deletion failed.\n");
        return Shead;
    }

    if (previous == NULL) {
        // If the element is in the Shead NodeSl
        Shead = Shead->next;
    } else {
        // If the element is in a non-Shead NodeSl
        previous->next = current->next;
    }

    free(current);
    printf("\nElement deleted successfully.\n");
    displaySinglyLinkedListfun(Shead);
    return Shead;
}

struct NodeSl* createSinglyLinkedList() {
    int numNodes;
    printf("\nEnter the number of nodes to create: ");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        Shead = insertAtEndSingly(Shead);
    }
    return Shead;
}
// Function to display theory and code for a singly linked list
int seeSinglyLinkedListFunctioning() {
    int choice;
    int on = 1;  // Initialize on to 1

    do {
        // Menu for singly linked list operations

    printf(" ______________________________________\n");
    printf("|           **MENU**                   |\n");
    printf("| 1. Create Linked List                |\n");
    printf("| 2. Insert At Beginning               |\n");
    printf("| 3. Insert At End                     |\n");
    printf("| 4. Delete Element                    |\n");
    printf("| 5. Display Linked List               |\n");
    printf("| 6. Exit                              |\n");
    printf("|______________________________________|\n");


        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Shead = createSinglyLinkedList();
                break;
            case 2:
                Shead = insertAtBeginningSingly(Shead);
                break;
            case 3:
                Shead = insertAtEndSingly(Shead);
                break;
            case 4:
                Shead = deleteElementSingly(Shead);
                break;
            case 5:
                displaySinglyLinkedListfun(Shead);
                break;
            case 6:
                printf("Exiting the singly linked list operations.\n");
                on = 0;
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return on;  // Return on value
}


void displaySinglyLinkedList() {
    int on;
    printf("\n-------------------------------------------------------------------------------Singly Linked List-----------------------------------------------------------------------------------------------------\n");

    printf("A singly linked list is a type of basic linked list where each node points to the next node, "
           "and the last node points to NULL.\n\n");

    printf("Characteristics of a Singly Linked List:\n");
    printf("- Each node holds a single value and a reference to the next node in the list.\n");
    printf("- The list has a head, which is a reference to the first node in the list, and a tail, which is a reference to the last node in the list.\n");
    printf("- The nodes are not stored in a contiguous block of memory, but instead, each node holds the address of the next node in the list.\n");
    printf("- Accessing elements in a singly linked list requires traversing the list from the head to the desired node, "
           "as there is no direct access to a specific node in memory.\n\n");

    printf("\nExample Code:\n");
    printf("\n");
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n\n");

    printf("// Node structure\n");
    printf("struct Node {\n");
    printf("    int data;\n");
    printf("    struct Node* next;\n");
    printf("};\n\n");

    printf("// Function to display the elements of a linked list\n");
    printf("void displayLinkedList(struct Node* head) {\n");
    printf("    struct Node* current = head;\n\n");

    printf("    printf(\"Linked List elements: \");\n");
    printf("    while (current != NULL) {\n");
    printf("        printf(\"%%d \", current->data);\n");
    printf("        current = current->next;\n");
    printf("    }\n");
    printf("    printf(\"\\n\");\n");
    printf("}\n\n");

    printf("// Function to create a new node with given data\n");
    printf("struct Node* createNode(int data) {\n");
    printf("    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));\n");
    printf("    if (newNode == NULL) {\n");
    printf("        printf(\"Memory allocation failed.\\n\");\n");
    printf("        exit(1);\n");
    printf("    }\n");
    printf("    newNode->data = data;\n");
    printf("    newNode->next = NULL;\n");
    printf("    return newNode;\n");
    printf("}\n\n");

    printf("int main() {\n");
    printf("    // Creating the first node\n");
    printf("    struct Node* head = createNode(10);\n\n");

    printf("    // Creating the second node\n");
    printf("    struct Node* secondNode = createNode(20);\n\n");

    printf("    // Linking the first node to the second node\n");
    printf("    head->next = secondNode;\n\n");

    printf("    // Creating the third node\n");
    printf("    struct Node* thirdNode = createNode(30);\n\n");

    printf("    // Linking the second node to the third node\n");
    printf("    secondNode->next = thirdNode;\n\n");

    printf("    // Displaying the linked list\n");
    printf("    displayLinkedList(head);\n\n");

    printf("    return 0;\n");
    printf("}\n");

    printf("   ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Want to See the Functioning?                      |\n");
    printf("  | Press 1 to see, otherwise Press 0 for Cancel:     |\n");
    printf("  |___________________________________________________|\n");
    printf("Enter Your Choice:\t");
    scanf("%d", &on);
    do {
        switch (on) {
            case 1:
                // Assuming seeSinglyLinkedListFunctioning() is defined elsewhere
                on=seeSinglyLinkedListFunctioning();
                break;
            case 0:
                printf("\nEnjoy Learning!!\n");
                break;
            default:
            printf("\nInvalid Choice\n");
            on=0;
                break;
        }
    } while (on != 0);
}








// `````````````````````````````````````````````````````````````````````````````Doubly Linked List`````````````````````````````````````````````````````````````



void displayDoublyfun(struct Noded* headd) {
    int count = 0;
    tempd = headd;
    printf("\nElements in the linked list are:\t");
    while (tempd != NULL) {
        printf("%d\t", tempd->data);
        tempd = tempd->nextd;
        count++;
    }
    printf("\nTotal elements in the linked list are: %d\n", count);
}

void reverse_displayDoublyfun(struct Noded* headd) {
    int count = 0;
    tempd = headd;

    while (tempd != NULL && tempd->nextd != NULL) {
        tempd = tempd->nextd;
    }

    printf("\nElements in the linked list (in reverse order) are:\t");
    while (tempd != NULL) {
        printf("%d\t", tempd->data);
        tempd = tempd->prevd;
        count++;
    }
    printf("\nTotal elements in the linked list are: %d\n", count);
}

void insertionAtBeginningDoubly() {
    newNoded = (struct Noded*)malloc(sizeof(struct Noded));
    if (newNoded == NULL) {
        printf("\nNo memory allocated\n");
        exit(EXIT_FAILURE);
    }
    printf("\nEnter the data you want to insert: ");
    scanf("%d", &newNoded->data);
    newNoded->nextd = NULL;
    newNoded->prevd = NULL;

    if (headd == NULL) {
        headd = newNoded;
        taild = newNoded;
    } else {
        newNoded->nextd = headd;
        headd->prevd = newNoded;
        headd = newNoded;
    }
    displayDoublyfun(headd);
}

void insertionAtMiddleDoubly() {
    int pos, i = 1;
    printf("\nEnter the position you want to insert element: ");
    scanf("%d", &pos);

    if (headd == NULL) {
        printf("\nNo memory allocated\n");
    } else {
        tempd = headd;
        while (i < pos) {
            tempd = tempd->nextd;
            i++;
        }
        newNoded = (struct Noded*)malloc(sizeof(struct Noded));
        if (newNoded == NULL) {
            printf("\nNo memory allocated\n");
            exit(EXIT_FAILURE);
        }
        printf("\nEnter the data you want to insert: ");
        scanf("%d", &newNoded->data);
        newNoded->nextd = tempd->nextd;
        newNoded->prevd = tempd;
        tempd->nextd = newNoded;
        newNoded->nextd->prevd = newNoded;
    }
    displayDoublyfun(headd);
}

void insertionAtEndDoubly() {
    if (headd == NULL) {
        printf("\nNo memory allocated\n");
    } else {
        tempd = headd;
        while (tempd->nextd != NULL) {
            tempd = tempd->nextd;
        }
        newNoded = (struct Noded*)malloc(sizeof(struct Noded));
        if (newNoded == NULL) {
            printf("\nNo memory allocated\n");
            exit(EXIT_FAILURE);
        }
        printf("\nEnter the data you want to insert: ");
        scanf("%d", &newNoded->data);
        newNoded->nextd = NULL;
        newNoded->prevd = tempd;
        tempd->nextd = newNoded;
        taild = newNoded;
    }
    displayDoublyfun(headd);
}

void deletionAtBeginningDoubly() {
    if (headd == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
    } else {
        tempd = headd;
        headd = tempd->nextd;
        if (headd != NULL) {
            headd->prevd = NULL;
        } else {
            taild = NULL;
        }
        free(tempd);
        displayDoublyfun(headd);
    }
}

void deletionAtMiddleDoubly() {
    int pos, i = 1;
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);

    tempd = headd;
    while (i < pos) {
        tempd = tempd->nextd;
        i++;
    }

    tempd->prevd->nextd = tempd->nextd;
    if (tempd->nextd != NULL) {
        tempd->nextd->prevd = tempd->prevd;
    } else {
        taild = tempd->prevd;
    }

    free(tempd);
    displayDoublyfun(headd);
}

void deletionAtEndDoubly() {
    if (headd == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
    } else {
        tempd = taild;
        if (tempd->prevd != NULL) {
            tempd->prevd->nextd = NULL;
            taild = tempd->prevd;
        } else {
            headd = taild = NULL;
        }
        free(tempd);
        displayDoublyfun(headd);
    }
}

void createDoublyLinkedList() {
    int num;
    printf("\nEnter the elements you want to insert in the linked list: ");
    scanf("%d", &num);
    
    for (int i = 1; i <= num; i++) {
        newNoded = (struct Noded*)malloc(sizeof(struct Noded));
        if (newNoded == NULL) {
            printf("\nNo memory allocated\n");
            exit(EXIT_FAILURE);
        }
        printf("Enter %d element data: ", i);
        scanf("%d", &newNoded->data);
        newNoded->nextd = NULL;
        newNoded->prevd = NULL;

        if (headd == NULL) {
            headd = taild = newNoded;
            tempd = newNoded;  // Initialize tempd here
        } else {
            tempd->nextd = newNoded;
            newNoded->prevd = tempd;
            tempd = newNoded;
            taild = newNoded;
        }
    }
    displayDoublyfun(headd);
}


int seeDoublyLinkedListFunctioning(){
    createDoublyLinkedList();
    int choice;
    int on=1;
    
    do {


    printf(" ______________________________________\n");
    printf("|           **MENU**                   |\n");
    printf("| 1. Insert At Beginning               |\n");
    printf("| 2. Insert At Specific Position       |\n");
    printf("| 3. Insert At End                     |\n");
    printf("| 4. Delete From Beginning             |\n");
    printf("| 5. Delete From Specific Position     |\n");
    printf("| 6. Delete at End                     |\n");
    printf("| 7. Reverse Display                   |\n");
    printf("| 0. Exit                              |\n");
    printf("|______________________________________|\n");


        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertionAtBeginningDoubly();
                break;
            case 2:
                insertionAtMiddleDoubly();
                break;
            case 3:
                insertionAtEndDoubly();
                break;
            case 4:
                deletionAtBeginningDoubly();
                break;
            case 5:
                deletionAtMiddleDoubly();
                break;
            case 6:
                deletionAtEndDoubly();
                break;
            case 7:
                reverse_displayDoublyfun(headd);
                break;
            case 0:
                printf("Enjoy Learning!!\n");
                on=0;
                break;

            default:
                printf("Invalid option\n");
        }

    } while (choice != 0);

    return on;
}


void displayDoublyLinkedList() {
    int on;
    
    printf("\n-----------------------------------------------------------------------------Doubly Linked List-----------------------------------------------------------------------------------------------------\n");

    printf("\nA doubly linked list is a type of linked list where each node points to both the next and previous nodes.\n");
    printf("Advantages: Bidirectional traversal, efficient insertion/deletion at the beginning or end.\n");
    printf("Disadvantages: Additional memory for backward pointers, more complex implementation.\n\n");

    printf("Example Code:\n");
    printf("\n");
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n\n");

    printf("struct Node {\n");
    printf("    int data;\n");
    printf("    struct Node* next;\n");
    printf("    struct Node* prev;\n");
    printf("};\n\n");

    printf("void displayDoublyLinkedList(struct Node* head) {\n");
    printf("    struct Node* current = head;\n\n");

    printf("    printf(\"Doubly Linked List elements: \");\n");
    printf("    while (current != NULL) {\n");
    printf("        printf(\"%%d \", current->data);\n");
    printf("        current = current->next;\n");
    printf("    }\n");
    printf("    printf(\"\\n\");\n");
    printf("}\n\n");

    printf("int main() {\n");
    printf("    struct Node *head = NULL, *temp, *newNode;\n");
    printf("    int choice, count = 0;\n");
    printf("    while (choice) {\n");
    printf("        newNode = (struct Node *)malloc(sizeof(struct Node));\n");
    printf("        printf(\"Enter the data you want to insert : \");\n");
    printf("        scanf(\"%%d\", &newNode->data);\n");
    printf("        newNode->prev = NULL;\n");
    printf("        newNode->next = NULL;\n");
    printf("        if (head == NULL) {\n");
    printf("            head = temp = newNode;\n");
    printf("        }\n");
    printf("        else {\n");
    printf("            temp->next = newNode;\n");
    printf("            newNode->prev = temp;\n");
    printf("            temp = newNode;\n");
    printf("        }\n");
    printf("        printf(\"\\nDo you want to enter another element?\\n1: continue \\t 0: exit\\n\");\n");
    printf("        scanf(\"%%d\", &choice);\n");
    printf("    }\n");
    printf("    printf(\"Elements in the linked list are:\");\n");
    printf("    temp = head;\n");
    printf("    while (temp != NULL) {\n");
    printf("        printf(\"%%d\\t\", temp->data);\n");
    printf("        temp = temp->next;\n");
    printf("        count++;\n");
    printf("    }\n");
    printf("    printf(\"\\nTotal elements of linked list are : %%d\", count);\n");
    printf("    return 0;\n");
    printf("}\n\n");
    printf("   ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Want to See the Functioning?                      |\n");
    printf("  | Press 1 to see, otherwise Press 0 for Cancel:     |\n");
    printf("  |___________________________________________________|\n");
    printf("Enter Your Choice:\t");
    scanf("%d", &on);
    do {
        switch (on) {
            case 1:
                on= seeDoublyLinkedListFunctioning();
                break;
            case 0:
                printf("\nEnjoy Learning!!\n");
                break;
            default:
            printf("Invalid Choice\n");
            on=0;
                break;
        }
    } while (on != 0);
}








// ------------------------------------------------------------Circular Linkedlist---------------------------------------------------------------------------
void displayCircular(struct node *headc)
{
    int count = 0;
    if (headc == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        tempc = headc;
        while (tempc->nextc != headc)
        {
            printf("%d\t", tempc->datac);
            tempc = tempc->nextc;
            count++;
        }
        printf("%d\t", tempc->datac); // for last element of the list
    }
    printf("\nTotal number of elements in the linked list are : %d", count + 1);
}

void insertionAtBeginningCircular()
{
    if (headc == NULL)
    {
        printf("\nNo memory allocated linked list is empty");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("\nNo memory allocated\n");
            exit(EXIT_FAILURE);
        }
        printf("\nEnter the data you want to insert :");
        scanf("%d", &newNode->datac);
        newNode->nextc = headc;
        headc = newNode;
        tailc->nextc = headc;
    }
    displayCircular(headc);
}
void insertionAtMiddleCircular()
{
    if (headc == NULL)
    {
        printf("\nLinked List is Empty\n");
    }
    else
    {
        int pos, i = 1;
        printf("\nEnter position where element has to be inserted: ");
        scanf("%d", &pos);
        tempc = headc;
        while (i < pos)
        {
            tempc = tempc->nextc;
            i++;
        }
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("\nNo memory allocated\n");
            exit(EXIT_FAILURE);
        }
        printf("\nEnter the data you want to insert :");
        scanf("%d", &newNode->datac);
        newNode->nextc = tempc->nextc;
        tempc->nextc = newNode;
    }
    displayCircular(headc);
}
// Insertion at end we can do it with two ways tailc pointer and by using tempc variable we can use while loop
void insertionAtEndCircular()
{
    if (headc == NULL)
    {
        printf("\nLinkedList is empty");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("\nNo memory allocated\n");
            exit(EXIT_FAILURE);
        }
        printf("\nEnter the data you want to insert :");
        scanf("%d", &newNode->datac);
        tailc->nextc = newNode;
        tailc = newNode;
        tailc->nextc = headc;
    }
    displayCircular(headc);
}
void deletionAtBeginningCircular()
{
    if (headc == NULL)
    {
        printf("\nLinked list is empty.\n");
    }
    else
    {
        tempc = headc;
        headc = tempc->nextc;
        tailc->nextc = headc;
        free(tempc);
    }
    displayCircular(headc);
}
void deletionAtMiddleCircular()
{
    struct node *nextcNode;
    int pos, i = 1;
    printf("\nEnter the position you want to insert");
    scanf("%d", &pos);
    tempc = headc;
    while (i < pos - 1)
    {
        tempc = tempc->nextc;
        i++;
    }
    nextcNode = tempc->nextc;
    tempc->nextc = nextcNode->nextc;
    free(nextcNode);
    displayCircular(headc);
}
void deletionAtEndCircular()
{
    struct node *preNode;
    if (headc == NULL)
    {
        printf("\nLinked list is empty.\n");
    }
    else
    {
        tempc = headc;
        while (tempc->nextc != headc)
        {
            preNode = tempc;
            tempc = tempc->nextc;
        }
        preNode->nextc = headc;
        free(tempc);
    }
    displayCircular(headc);
}

int seeCircularLinkedListFunctioning()
{
    int num, choice,on=1;
    printf("\nEnter the number of elements you want in linked list:");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if(newNode == NULL)
        {
            printf("\nNo memory allocated\n");
            exit(EXIT_FAILURE);
        }
        printf("\nEnter element %d data : ", i);
        scanf("%d", &newNode->datac);
        if (headc == NULL)
        {
            headc = tailc = newNode;
        }
        else
        {
            tailc->nextc = newNode;
            tailc = newNode;
        }
        tailc->nextc = headc;
    }
    displayCircular(headc);
    do
    {

    printf(" ______________________________________\n");
    printf("|           **MENU**                   |\n");
    printf("| 1. Insert At Beginning               |\n");
    printf("| 2. Insert At Specific Position       |\n");
    printf("| 3. Insert At End                     |\n");
    printf("| 4. Delete From Beginning             |\n");
    printf("| 5. Delete From Specific Position     |\n");
    printf("| 6. Delete at End                     |\n");
    printf("| 0. Exit                              |\n");
    printf("|______________________________________|\n");


        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertionAtBeginningCircular();
            break;
        case 2:
            insertionAtMiddleCircular();
            break;
        case 3:
            insertionAtEndCircular();
            break;
        case 4:
            deletionAtBeginningCircular();
            break;
        case 5:
            deletionAtMiddleCircular();
            break;
        case 6:
            deletionAtEndCircular();
            break;
        case 0:
        printf("Enjoy Learning!!\n");
        on=0;
        break;
        default:
            printf("\nInvalid option\n");
        }
    } while (choice != 0);
    return on;
}


// Function to display theory and code for a circular linked list
void displayCircularLinkedList() {
    int on;

    printf("\n----------------------------------------------------------------------------Circular Linked List-----------------------------------------------------------------------------------------------------\n");

    printf("A circular linked list is a type of linked list where the last node points back to the first node, "
           "forming a loop.\n");
    printf("Advantages: Constant-time insertion/deletion at the beginning or end.\n");
    printf("Disadvantages: Difficulty in detecting the end of the list, traversal required for some operations.\n\n");

    printf("\nExample Code:\n");
    printf("\n");
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n\n");

    printf("struct Node {\n");
    printf("    int data;\n");
    printf("    struct Node* next;\n");
    printf("};\n\n");

    printf("void displayCircularLinkedList(struct Node* head) {\n");
    printf("    struct Node* current = head;\n\n");

    printf("    printf(\"Circular Linked List elements: \");\n");
    printf("    do {\n");
    printf("        printf(\"%%d \", current->data);\n");
    printf("        current = current->next;\n");
    printf("    } while (current != head);\n");
    printf("    printf(\"\\n\");\n");
    printf("}\n\n");

    printf("int main() {\n");
    printf("    struct Node *head = NULL, *temp, *newNode, *tail;\n");
    printf("    int num, choice;\n");
    printf("    printf(\"Enter the number of elements you want in linked list:\");\n");
    printf("    scanf(\"%%d\", &num);\n");
    printf("    for (int i = 1; i <= num; i++) {\n");
    printf("        newNode = (struct Node *)malloc(sizeof(struct Node));\n");
    printf("        printf(\"Enter element %%d data : \", i);\n");
    printf("        scanf(\"%%d\", &newNode->data);\n");
    printf("        if (head == NULL) {\n");
    printf("            head = tail = newNode;\n");
    printf("        } else {\n");
    printf("            tail->next = newNode;\n");
    printf("            tail = newNode;\n");
    printf("        }\n");
    printf("        tail->next = head;\n");
    printf("    }\n");
    printf("    displayCircularLinkedList(head);\n");
    printf("    do {\n");
    printf("        printf(\"\\nSelect an operation : \\n\\t1. Insertion at beginning \\n\\t2. Insertion at specific position \\n\\t3. Insertion at end \\n\\t4. Deleting from beginning \\n\\t5. Deleting from a specific position \\n\\t6. Deleting last node\");\n");
    printf("        printf(\"\\n\\nEnter the Choice \\n\");\n");
    printf("        scanf(\"%%d\", &choice);\n");
    printf("        switch (choice) {\n");
    printf("            case 1:\n");
    printf("                insertionAtBeginning();\n");
    printf("                break;\n");
    printf("            case 2:\n");
    printf("                insertionAtMiddle();\n");
    printf("                break;\n");
    printf("            case 3:\n");
    printf("                insertionAtEnd();\n");
    printf("                break;\n");
    printf("            case 4:\n");
    printf("                deletionAtBeginning();\n");
    printf("                break;\n");
    printf("            case 5:\n");
    printf("                deletionAtMiddle();\n");
    printf("                break;\n");
    printf("            case 6:\n");
    printf("                deletionAtEnd();\n");
    printf("                break;\n");
    printf("            default:\n");
    printf("                printf(\"Invalid option\");\n");
    printf("        }\n");
    printf("    } while (choice != 7);\n");
    printf("    return 0;\n");
    printf("}\n");

    printf("   ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Want to See the Functioning?                      |\n");
    printf("  | Press 1 to see, otherwise Press 0 for Cancel:     |\n");
    printf("  |___________________________________________________|\n");
    printf("Enter Your Choice:\t");
    scanf("%d", &on);
    do {
        switch (on) {
            case 1:
                on=seeCircularLinkedListFunctioning();
                break;
            case 0:
                printf("\nEnjoy Learning!!\n");
                break;
            default:
            printf("\nInvalid Choice\n");
            on=0;
                break;
        }
    } while (on != 0);
}




void displayAllLinkedLists() {

    int choice;
    do{
    

    printf(" ________________________________\n");
    printf("|           **MENU**             |\n");
    printf("| 1. Single Linked List          |\n");
    printf("| 2. Double Linked List          |\n");
    printf("| 3. Circular Linked List        |\n");
    printf("| 0. Exit                        |\n");
    printf("|________________________________|\n");

        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

    switch (choice) {
        
        case 0:
            printf("Enjoy Learning!!\n");
            break;
        case 1:
            displaySinglyLinkedList();
            break;
        case 2:
            displayDoublyLinkedList();
            break;
        case 3:
            displayCircularLinkedList();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            choice=0;
    }
}while(choice!=0);
}


//------------------------Linked List Explanation End Here----------------------------------------------------------------------------------------













//------------------------Stack Explanation Starts Here----------------------------------------------------------------------------------------

void display()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}

void push()
{
    int x;

    if (top == SIZE - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d\n", stack[top]);
        top = top - 1;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty!");
    }
    else
    {
        printf("Topmost element of the stack is: %d", stack[top]);
    }
}

int seeStackFunctioning()
{
    int choice,on=1;

    do
    {

  printf(" \n________________________________\n");
    printf("|           **MENU**             |\n");
    printf("| 1. Push                        |\n");
    printf("| 2. Pop                         |\n");
    printf("| 3. Display Elements            |\n");
    printf("| 4. Peek                        |\n");
    printf("| 0. Exit                        |\n");
    printf("|________________________________|\n");

        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 0:
            printf("Enjoy Learning!!\n");
            on=0;
            break;

        default:
            printf("\nInvalid choice!!\n");
        }
    }while(choice!=0);
    return on;
}
// Function to display theory and code for stacks
void displayStack() {
    int on;

   printf("\n-----------------------------------------------------------------------------Stack----------------------------------------------------------------------------------------------------------\n");

    printf("A stack is a Last In, First Out (LIFO) data structure, where elements are added and removed from the same end. "
           "It follows the principle of push (add) and pop (remove).\n");
    printf("Advantages: Simple implementation, efficient for certain algorithms like recursion.\n");
    printf("Disadvantages: Limited access (only the top element), fixed size, and potential stack overflow.\n\n");

    printf("\nExample Code:\n");
    printf("\n");
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n\n");

    printf("#define SIZE 4\n");
    printf("int top = -1, stack[SIZE];\n\n");

    printf("void push();\n");
    printf("void pop();\n");
    printf("void display();\n");
    printf("void peek();\n\n");

    printf("int main() {\n");
    printf("    int choice;\n\n");

    printf("    while (1) {\n");
    printf("        printf(\"\\nPerform operations on the stack:\");\n");
    printf("        printf(\"\\n1.Push the element\\n2.Pop the element\\n3.Display\\n4.Peek\\n5.Exit\");\n");
    printf("        printf(\"\\n\\nEnter the choice: \");\n");
    printf("        scanf(\"%%d\", &choice);\n\n");

    printf("        switch (choice) {\n");
    printf("            case 1:\n");
    printf("                push();\n");
    printf("                break;\n");
    printf("            case 2:\n");
    printf("                pop();\n");
    printf("                break;\n");
    printf("            case 3:\n");
    printf("                display();\n");
    printf("                break;\n");
    printf("            case 4:\n");
    printf("                peek();\n");
    printf("                break;\n");
    printf("            case 5:\n");
    printf("                exit(0);\n");
    printf("            default:\n");
    printf("                printf(\"\\nInvalid choice!!\");\n");
    printf("        }\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void push() {\n");
    printf("    int x;\n\n");

    printf("    if (top == SIZE - 1) {\n");
    printf("        printf(\"\\nOverflow!!\");\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        printf(\"\\nEnter the element to be added onto the stack: \");\n");
    printf("        scanf(\"%%d\", &x);\n");
    printf("        top = top + 1;\n");
    printf("        stack[top] = x;\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void pop() {\n");
    printf("    if (top == -1) {\n");
    printf("        printf(\"\\nUnderflow!!\");\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        printf(\"\\nPopped element: %%d\", stack[top]);\n");
    printf("        top = top - 1;\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void display() {\n");
    printf("    if (top == -1) {\n");
    printf("        printf(\"\\nUnderflow!!\");\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        printf(\"\\nElements present in the stack: \\n\");\n");
    printf("        for (int i = top; i >= 0; --i)\n");
    printf("            printf(\"%%d\\n\", stack[i]);\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void peek() {\n");
    printf("    if (top == -1) {\n");
    printf("        printf(\"Stack is empty!\");\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        printf(\"Topmost element of the stack is: %%d\", stack[top]);\n");
    printf("    }\n");
    printf("}\n\n");

     printf("   ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Want to See the Functioning?                      |\n");
    printf("  | Press 1 to see, otherwise Press 0 for Cancel:     |\n");
    printf("  |___________________________________________________|\n");
    printf("Enter Your Choice:\t");
    scanf("%d", &on);
    do {
        switch (on) {
            case 1:
                on=seeStackFunctioning();
                break;
            case 0:
                printf("\nEnjoy Learning!!\n");
                break;
            default:
            printf("\nInvalid Choice\n");
            on=0;
                break;
        }
    } while (on != 0);
}

//------------------------Stack Explanation End Here----------------------------------------------------------------------------------------












//------------------------Queue Explanation End Here----------------------------------------------------------------------------------------


void enqueue(int x)
{
    if (rear == QSIZE - 1)
    {
        printf("\nQueue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("\nThe dequeued element is %d\n", queue[front]);
        front++;
    }
}

void displayQueuefun()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("\n%d ", queue[i]);
        }
        printf("\n");
    }
}

void peekQueue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Peek value of the Queue is: %d\n", queue[front]);
    }
}

int seeQueueFunctioning()
{
    int choice, x,on=0;
    do{
      
  printf("\n ________________________________\n");
    printf("|           **MENU**             |\n");
    printf("| 1. Enqueue                     |\n");
    printf("| 2. Dequeue                     |\n");
    printf("| 3. Display Elements            |\n");
    printf("| 4. Peek                        |\n");
    printf("| 0. Exit                        |\n");
    printf("|________________________________|\n");

        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to insert: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            displayQueuefun();
            break;
        case 4:
            peekQueue();
            break;
        case 0:
            printf("Enjoy Learning!!\n");
            on=0;
            break;
        default:
            printf("\nInvalid choice!!\n");
        }
    }while(choice!=0);

    return on;
}

// Function to display theory and code for queues

void displayQueue() {
    int on;
    printf("\n----------------------------------------------------------------------------Queue----------------------------------------------------------------------------------------------------------\n");

    printf("\nA queue is a First In, First Out (FIFO) data structure, where elements are added at the rear and removed from the front. "
           "It follows the principle of enqueue (add) and dequeue (remove).\n");
    printf("Advantages: Simple implementation, efficient for managing tasks in a sequential manner.\n");
    printf("Disadvantages: Limited access (only front and rear), fixed size, and potential queue overflow.\n\n");

    printf("\nExample Code:\n");
    printf("\n");
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n\n");

    printf("#define SIZE 5\n");
    printf("int queue[SIZE];\n");
    printf("int front = -1, rear = -1;\n\n");

    printf("void enqueue(int x) {\n");
    printf("    if (rear == SIZE - 1) {\n");
    printf("        printf(\"Queue is full\\n\");\n");
    printf("    }\n");
    printf("    else if (front == -1 && rear == -1) {\n");
    printf("        front = rear = 0;\n");
    printf("        queue[rear] = x;\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        rear++;\n");
    printf("        queue[rear] = x;\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void dequeue() {\n");
    printf("    if (front == -1 && rear == -1) {\n");
    printf("        printf(\"Queue is empty\\n\");\n");
    printf("    }\n");
    printf("    else if (front == rear) {\n");
    printf("        front = rear = -1;\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        printf(\"The dequeued element is %%d\\n\", queue[front]);\n");
    printf("        front++;\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void display() {\n");
    printf("    if (front == -1 && rear == -1) {\n");
    printf("        printf(\"Queue is empty\\n\");\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        for (int i = front; i <= rear; i++) {\n");
    printf("            printf(\"%%d \", queue[i]);\n");
    printf("        }\n");
    printf("        printf(\"\\n\");\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void peek() {\n");
    printf("    if (front == -1 && rear == -1) {\n");
    printf("        printf(\"Queue is empty\\n\");\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        printf(\"Peek value of the Queue is: %%d\\n\", queue[front]);\n");
    printf("    }\n");
    printf("}\n\n");

    printf("int main() {\n");
    printf("    int choice, x;\n\n");

    printf("    while (1) {\n");
    printf("        printf(\"\\nPerform operations on the queue:\");\n");
    printf("        printf(\"\\n1.Enqueue the element\\n2.Dequeue the element\\n3.Display\\n4.Peek\\n5.Exit\");\n");
    printf("        printf(\"\\n\\nEnter the choice: \");\n");
    printf("        scanf(\"%%d\", &choice);\n\n");

    printf("        switch (choice) {\n");
    printf("            case 1:\n");
    printf("                printf(\"Enter the data you want to insert: \");\n");
    printf("                scanf(\"%%d\", &x);\n");
    printf("                enqueue(x);\n");
    printf("                break;\n");
    printf("            case 2:\n");
    printf("                dequeue();\n");
    printf("                break;\n");
    printf("            case 3:\n");
    printf("                display();\n");
    printf("                break;\n");
    printf("            case 4:\n");
    printf("                peek();\n");
    printf("                break;\n");
    printf("            case 5:\n");
    printf("                exit(0);\n");
    printf("            default:\n");
    printf("                printf(\"\\nInvalid choice!!\\n\");\n");
    printf("        }\n");
    printf("    }\n");
    printf("    return 0;\n");
    printf("}\n");



    printf("   ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Want to See the Functioning?                      |\n");
    printf("  | Press 1 for Normal Queue                          |\n");
    printf("  | Press 2 for Circular Queue                        |\n");
    printf("  | Press 0 for Cancel:                               |\n");
    printf("  |___________________________________________________|\n");
    scanf("%d", &on);
    do {
        switch (on) {
            case 1:
                on=seeQueueFunctioning();
                break;
            case 2:
                on=displayCircularQueue();
                break;
            case 0:
                printf("\nEnjoy Learning!!\n");
                break;
            default:
            printf("Invalid Choice");
                break;
        }
    } while (on != 0);
}

// ------------------------------Circular Queue Explanation Starts Here--------------------------------------------------------------------------------------------


void enqueueCircular(int x)
{
    if (frontC == -1 && rear == -1)
    {
        frontC = rearC = 0;
        queueC[rearC] = x;
    }
    else if ((rearC + 1) % CSIZE == frontC)
    {
        printf("Queue is full\n");
    }
    else
    {
        rearC = (rearC + 1) % CSIZE;
        queueC[rearC] = x;
    }
}

void dequeueCircular()
{
    if (frontC == -1 && rearC == -1)
    {
        printf("Queue is empty\n");
    }
    else if (frontC == rearC)
    {
        frontC = rearC = -1;
    }
    else
    {
        printf("The dequeueCirculard element is %d\n", queueC[front]);
        frontC = (frontC + 1) % CSIZE;
    }
}

void displayCircularQ()
{
    int i = frontC;
    if (frontC == -1 && rearC == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while (i != rearC)
        {
            printf("%d ", queueC[i]);
            i = (i + 1) % CSIZE;
        }
        printf("%d ", queueC[rearC]);
    }
}

void peekcircular()
{
    if (frontC == -1 && rearC == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Peek value of the Queue is: %d\n", queueC[frontC]);
    }
}

int seeCircularQueueFunctioning()
{
    int choice, x,on=1;

    
    do{


  printf("\n ________________________________\n");
    printf("|           **MENU**             |\n");
    printf("| 1. Enqueue                     |\n");
    printf("| 2. Dequeue                     |\n");
    printf("| 3. Display Elements            |\n");
    printf("| 4. Peek                        |\n");
    printf("| 0. Exit                        |\n");
    printf("|________________________________|\n");

        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data you want to insert: ");
            scanf("%d", &x);
            enqueueCircular(x);
            break;
        case 2:
            dequeueCircular();
            break;
        case 3:
            displayCircularQ();
            break;
        case 4:
            peekcircular();
            break;
        case 0:
            printf("Enjoy Learning!!\n");
            on=0;
            break;
        default:
            printf("\nInvalid choice!!\n");
        }
    }while(choice!=0);

    return on;
}

int displayCircularQueue() {
    printf("\n-------------------------------------------------------------------Circular Queue----------------------------------------------------------------------------------------------------------\n");
    printf("A Circular Queue is an extended version of a normal queue where the last element of the queue is connected to the first element of the queue forming a circle.\n\n");
    printf("The operations are performed based on FIFO (First In First Out) principle. It is also called ‘Ring Buffer’.\n\n");

    printf("\nCircular Queue:\n");
    printf("In a normal Queue, we can insert elements until the queue becomes full. But once the queue becomes full, we cannot insert the next element even if there is space in front of the queue.\n\n");

    printf("Operations on Circular Queue:\n");
    printf("Front: Get the front item from the queue.\n");
    printf("Rear: Get the last item from the queue.\n");
    printf("enQueue(value): This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at the rear position.\n");
    printf("Check whether the queue is full – [i.e., the rear end is just before the front end in a circular manner].\n");
    printf("If it is full, then display Queue is full.\n");
    printf("If the queue is not full, then insert an element at the end of the queue.\n");
    printf("deQueue(): This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from the front position.\n");
    printf("Check whether the queue is empty.\n");
    printf("If it is empty, then display Queue is empty.\n");
    printf("If the queue is not empty, then get the last element and remove it from the queue.\n\n");

    printf("\nExample Code:\n");
    printf("\n");
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n\n");

    printf("#define SIZE 5\n");
    printf("int queue[SIZE];\n");
    printf("int front = -1, rear = -1;\n\n");

    printf("void enqueue(int x) {\n");
    printf("    if (front == -1 && rear == -1) {\n");
    printf("        front = rear = 0;\n");
    printf("        queue[rear] = x;\n");
    printf("    }\n");
    printf("    else if ((rear + 1) %% SIZE == front) {\n");
    printf("        printf(\"Queue is full\\n\");\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        rear = (rear + 1) %% SIZE;\n");
    printf("        queue[rear] = x;\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void dequeue() {\n");
    printf("    if (front == -1 && rear == -1) {\n");
    printf("        printf(\"Queue is empty\\n\");\n");
    printf("    }\n");
    printf("    else if (front == rear) {\n");
    printf("        front = rear = -1;\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        printf(\"The dequeued element is %%d\\n\", queue[front]);\n");
    printf("        front = (front + 1) %% SIZE;\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void display() {\n");
    printf("    int i = front;\n");
    printf("    if (front == -1 && rear == -1) {\n");
    printf("        printf(\"Queue is empty\\n\");\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        while (i != rear) {\n");
    printf("            printf(\"%%d \", queue[i]);\n");
    printf("            i = (i + 1) %% SIZE;\n");
    printf("        }\n");
    printf("        printf(\"%%d \", queue[rear]);\n");
    printf("    }\n");
    printf("}\n\n");

    printf("void peek() {\n");
    printf("    if (front == -1 && rear == -1) {\n");
    printf("        printf(\"Queue is empty\\n\");\n");
    printf("    }\n");
    printf("    else {\n");
    printf("        printf(\"Peek value of the Queue is: %%d\\n\", queue[front]);\n");
    printf("    }\n");
    printf("}\n\n");

    printf("int main() {\n");
    printf("    int choice, x;\n\n");

    printf("    while (1) {\n");
    printf("        printf(\"\\nPerform operations on the queue:\");\n");
    printf("        printf(\"\\n1.Enqueue the element\\n2.Dequeue the element\\n3.Display\\n4.Peek\\n5.Exit\");\n");
    printf("        printf(\"\\n\\nEnter the choice: \");\n");
    printf("        scanf(\"%%d\", &choice);\n\n");

    printf("        switch (choice) {\n");
    printf("            case 1:\n");
    printf("                printf(\"Enter the data you want to insert: \");\n");
    printf("                scanf(\"%%d\", &x);\n");
    printf("                enqueue(x);\n");
    printf("                break;\n");
    printf("            case 2:\n");
    printf("                dequeue();\n");
    printf("                break;\n");
    printf("            case 3:\n");
    printf("                display();\n");
    printf("                break;\n");
    printf("            case 4:\n");
    printf("                peek();\n");
    printf("                break;\n");
    printf("            case 5:\n");
    printf("                exit(0);\n");
    printf("            default:\n");
    printf("                printf(\"\\nInvalid choice!!\\n\");\n");
    printf("        }\n");
    printf("    }\n");
    printf("    return 0;\n");
    printf("}\n");
    int on;

    printf("   ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Want to See the Functioning?                      |\n");
    printf("  | Press 1 to see, otherwise Press 0 for Cancel:     |\n");
    printf("  |___________________________________________________|\n");
    printf("Enter Your Choice:\t");
    scanf("%d", &on);
    do {
        switch (on) {
            case 1:
                on=seeCircularQueueFunctioning();
                break;
            case 0:
                printf("\nEnjoy Learning!!\n");
                return 0;
                break;
            default:
            printf("\nInvalid Choice\n");
            on=0;
                break;
        }
    } while (on != 0);

    return 2;
}





//------------------------Queue Explanation End Here----------------------------------------------------------------------------------------








//------------------------Tree Explanation End Here----------------------------------------------------------------------------------------







// `````````````````````````````````````````````````````````````Binary tree`````````````````````````````````````````````````````````````````
struct Nodeb* createNodeb(int key) {
    struct Nodeb* newNodeb = (struct Nodeb*)malloc(sizeof(struct Nodeb));
    if(newNodeb == NULL) {
        printf("Memory not allocated\n");
        exit(EXIT_FAILURE);
    }
    newNodeb->key = key;
    newNodeb->left = newNodeb->right = NULL;
    return newNodeb;
}

struct Nodeb* insert(struct Nodeb* root, int key) {
    if (root == NULL)
        return createNodeb(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void inorderTraversal(struct Nodeb* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void displayBTree(struct Nodeb* root, int space) {
    if (root == NULL)
        return;

    space += 5;

    displayBTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    displayBTree(root->left, space);
}

// Main function for testing the binary tree
int seeBinaryTreeFunctioning() {
    struct Nodeb* root = NULL;

    int n, key;
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);

    printf("Enter the data for each Node:\n");
    for (int i = 0; i < n; i++) {
        printf("\nNode %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("\nIn-order Traversal: ");
    inorderTraversal(root);
    printf("\n\nDisplaying the Binary Tree:\n");
    displayBTree(root, 0);

    return 0;
}
int displayBinaryTree()
{
    printf("\n-------------------------------------------------------------------Binary Tree----------------------------------------------------------------------------------------------------------\n");   
    printf("A binary Tree is defined as a Tree data structure with at most 2 children. ");
    printf("Since each element in a binary tree can have only 2 children, we typically name them the left and right child\n");

    printf("\nBinary Tree Representation:\n");
    printf("A Binary tree is represented by a pointer to the topmost node (commonly known as the “root”) of the tree. ");
    printf("If the tree is empty, then the value of the root is NULL. Each node of a Binary Tree contains the following parts:\n");
    printf("    Data\n");
    printf("    Pointer to left child\n");
    printf("    Pointer to right child\n\n");

    printf("\nBasic Operation On Binary Tree:\n");
    printf("    Inserting an element.\n");
    printf("    Removing an element.\n");
    printf("    Searching for an element.\n");
    printf("    Traversing the tree.\n\n");

    printf("\nExample code:\n");
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n\n");

    printf("struct node\n");
    printf("{\n");
    printf("    int data;\n");
    printf("    struct node *left, *right;\n");
    printf("};\n\n");

    printf("struct node *create()\n");
    printf("{\n");
    printf("    int x;\n");
    printf("    struct node *newNode;\n\n");

    printf("    printf(\"Enter the data of the node (-1 for no node):\\n\");\n");
    printf("    scanf(\"%%d\", &x);\n\n");

    printf("    if (x == -1)\n");
    printf("    {\n");
    printf("        return NULL;\n");
    printf("    }\n");
    printf("    else\n");
    printf("    {\n");
    printf("        newNode = (struct node *)malloc(sizeof(struct node));\n");
    printf("        newNode->data = x;\n\n");

    printf("        printf(\"Enter the left child of %%d (or -1 for no left child):\\n\", x);\n");
    printf("        newNode->left = create();\n\n");

    printf("        printf(\"Enter the right child of %%d (or -1 for no right child):\\n\", x);\n");
    printf("        newNode->right = create();\n");
    printf("    }\n");
    printf("    return newNode;\n");
    printf("}\n\n");

    printf("void printInOrder(struct node *root)\n");
    printf("{\n");
    printf("    if (root == NULL)\n");
    printf("    {\n");
    printf("        return;\n");
    printf("    }\n\n");

    printf("    // In-order traversal: Left, Root, Right\n");
    printf("    printInOrder(root->left);\n");
    printf("    printf(\"%%d \", root->data);\n");
    printf("    printInOrder(root->right);\n");
    printf("}\n\n");

    printf("void printPreOrder(struct node *root)\n");
    printf("{\n");
    printf("    if (root == NULL)\n");
    printf("    {\n");
    printf("        return;\n");
    printf("    }\n\n");

    printf("    // Pre-order traversal: Root, Left, Right\n");
    printf("    printf(\"%%d \", root->data);\n");
    printf("    printPreOrder(root->left);\n");
    printf("    printPreOrder(root->right);\n");
    printf("}\n\n");

    printf("void printPostOrder(struct node *root)\n");
    printf("{\n");
    printf("    if (root == NULL)\n");
    printf("    {\n");
    printf("        return;\n");
    printf("    }\n\n");

    printf("    // Post-order traversal: Left, Right, Root\n");
    printf("    printPostOrder(root->left);\n");
    printf("    printPostOrder(root->right);\n");
    printf("    printf(\"%%d \", root->data);\n");
    printf("}\n\n");

    printf("int main()\n");
    printf("{\n");
    printf("    struct node *root = create();\n\n");

    printf("    printf(\"\\nBinary Tree in In-order (Left, Root, Right) Traversal:\\n\");\n");
    printf("    printInOrder(root);\n\n");

    printf("    printf(\"\\nBinary Tree in Pre-order (Root, Left, Right) Traversal:\\n\");\n");
    printf("    printPreOrder(root);\n\n");

    printf("    printf(\"\\nBinary Tree in Post-order (Left, Right, Root) Traversal:\\n\");\n");
    printf("    printPostOrder(root);\n\n");

    printf("    return 0;\n");
    printf("}\n");
    int on;
    printf("\n ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Want to See the Functioning?                      |\n");
    printf("  | Press 1 to see, otherwise Press 0 for Cancel:     |\n");
    printf("  |___________________________________________________|\n");  
    printf("Enter Your Choice:\t");
    scanf("%d", &on);
    do {
        switch (on) {
            case 1:
                on=seeBinaryTreeFunctioning();
                break;
            case 0:
                printf("\nEnjoy Learning!!\n");
                break;
            default:
            printf("\nInvalid Choice\n");
            on=0;
                break;
        }
    } while (on != 0);
  return on;
}
// ```````````````````````````````````````````````````````end binary tree``````````````````````````````````````````````````````````





// --------------------------------------------------------------BST starts here------------------------------------------------------------------

struct Nodebst* newNodebst(int item, int level) {
    struct Nodebst* temp = (struct Nodebst*)malloc(sizeof(struct Nodebst));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    temp->keyb = item;
    temp->level = level;
    temp->leftb = temp->rightb = NULL;
    return temp;
}

struct Nodebst* insertbst(struct Nodebst* Nodebst, int keyb, int level) {
    if (Nodebst == NULL)
        return newNodebst(keyb, level);

    if (keyb < Nodebst->keyb)
        Nodebst->leftb = insertbst(Nodebst->leftb, keyb, level + 1);
    else if (keyb > Nodebst->keyb)
        Nodebst->rightb = insertbst(Nodebst->rightb, keyb, level + 1);

    return Nodebst;
}

struct Nodebst* searchbst(struct Nodebst* root, int keyb) {
    if (root == NULL || root->keyb == keyb)
        return root;

    if (root->keyb < keyb)
        return searchbst(root->rightb, keyb);

    return searchbst(root->leftb, keyb);
}

void printTreeBstStructure(struct Nodebst* root, int space) {
    if (root == NULL)
        return;

    space += 5;

    printTreeBstStructure(root->rightb, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");

    printf("%d(%d)\n", root->keyb, root->level);

    printTreeBstStructure(root->leftb, space);
}

void inorderWithLevel(struct Nodebst* root) {
    if (root != NULL) {
        inorderWithLevel(root->leftb);
        printf("%d(%d) ", root->keyb, root->level);
        inorderWithLevel(root->rightb);
    }
}

void preorderWithLevel(struct Nodebst* Nodebst) {
    if (Nodebst == NULL)
        return;

    printf("%d(%d) ", Nodebst->keyb, Nodebst->level);
    preorderWithLevel(Nodebst->leftb);
    preorderWithLevel(Nodebst->rightb);
}

void postorderWithLevel(struct Nodebst* Nodebst) {
    if (Nodebst == NULL)
        return;

    postorderWithLevel(Nodebst->leftb);
    postorderWithLevel(Nodebst->rightb);
    printf("%d(%d) ", Nodebst->keyb, Nodebst->level);
}

struct Nodebst* deleteNodebst(struct Nodebst* root, int k, int* deletedLevel) {
    if (root == NULL)
        return root;

    if (root->keyb > k) {
        root->leftb = deleteNodebst(root->leftb, k, deletedLevel);
        return root;
    }
    else if (root->keyb < k) {
        root->rightb = deleteNodebst(root->rightb, k, deletedLevel);
        return root;
    }

    *deletedLevel = root->level;

    if (root->leftb == NULL) {
        struct Nodebst* temp = root->rightb;
        free(root);
        return temp;
    }
    else if (root->rightb == NULL) {
        struct Nodebst* temp = root->leftb;
        free(root);
        return temp;
    }
    else {
        struct Nodebst* succParent = root;
        struct Nodebst* succ = root->rightb;

        while (succ->leftb != NULL) {
            succParent = succ;
            succ = succ->leftb;
        }

        if (succParent != root)
            succParent->leftb = succ->rightb;
        else
            succParent->rightb = succ->rightb;

        root->keyb = succ->keyb;

        free(succ);
        return root;
    }
}

void printMenu() {
  printf("\n ________________________________\n");
    printf("|           **MENU**             |\n");
    printf("|                                |\n");
    printf("| 1. Insert Element              |\n");
    printf("| 2. Search Element              |\n");
    printf("| 3. Inorder Traversal           |\n");
    printf("| 4. Preorder Traversal          |\n");
    printf("| 5. Postorder Traversal         |\n");
    printf("| 6. Delete Element              |\n");
    printf("| 7. Print Tree Structure        |\n");
    printf("| 0. Exit                        |\n");
    printf("|________________________________|\n");
    printf("\nEnter your choice: ");
    
}

int seeBinarySearchTreeFunctioning() {
    struct Nodebst* root = NULL;
    int choice, keyb, deletedLevel,on;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to Insert in BST: ");
                scanf("%d", &keyb);
                root = insertbst(root, keyb, 0);
                break;
            case 2:
                printf("Enter key to Search in BST: ");
                scanf("%d", &keyb);
                if (searchbst(root, keyb) == NULL)
                    printf("%d not found\n", keyb);
                else
                    printf("%d found\n", keyb);
                break;
             case 3:
                printf("Inorder Traversal: ");
                inorderWithLevel(root);
                printf("\n");
                break;
            case 4:
                printf("\nPreorder Traversal: ");
                preorderWithLevel(root);
                printf("\n");
                break;
            case 5:
                printf("\nPostorder Traversal: ");
                postorderWithLevel(root);
                printf("\n");
                break;
            case 6:
                printf("\nEnter key to delete: ");
                scanf("%d", &keyb);
                root = deleteNodebst(root, keyb, &deletedLevel);
                printf("Deleted Nodebst %d (Level %d)\n", keyb, deletedLevel);
                break;
            case 7:
                printf("\nPrint Tree Structure:\n");
                printTreeBstStructure(root, 0);
                break;
            case 0:
                printf("\nExiting program.....\n\nProgram Exited Succesfully");
                on=0;
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return on;
}
int displayBinarySearchTree()
{
    printf("------------------------------------------------------------Binary Search Tree----------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\nA binary Tree is defined as a Tree data structure with at most 2 children. ");
    printf("Since each element in a binary tree can have only 2 children, we typically name them the left and right child\n");

    printf("\nBinary Search Tree (BST):\n");
    printf("A Binary Search Tree (BST) is a data structure commonly used to implement efficient searching, insertion, and deletion operations. ");
    printf("The key feature of a BST is that it is a binary tree, where each node has at most two child nodes, and the value of each node is greater than all the values in its left subtree and less than all the values in its right subtree.\n");
    printf("This means that the left subtree of a node contains values that are smaller than the node’s value, and the right subtree contains values that are larger. ");
    printf("Due to this property, BSTs allow for efficient searching by repeatedly dividing the search space in half, making it an important data structure in computer science and many other fields.\n\n");

    printf("\nBST Properties:\n");
    printf("    - The left subtree of a node contains only nodes with keys lesser than the node’s key.\n");
    printf("    - The right subtree of a node contains only nodes with keys greater than the node’s key.\n");
    printf("    - The left and right subtree each must also be a binary search tree.\n");
    printf("    - There must be no duplicate nodes.\n\n");

    printf("\nOperations on Binary Search Tree:\n");
    printf("The four basic operations of BST:\n");
    printf("    - Searching\n");
    printf("    - Insertion\n");
    printf("    - Deletion\n");
    printf("    - Traversals\n\n");

    printf("\nExample code:\n");
    printf("// Code for Binary Search Tree operations\n");
    printf("// (You can implement these functions based on your requirements)\n\n");

    printf("struct node\n");
    printf("{\n");
    printf("    int data;\n");
    printf("    struct node *left, *right;\n");
    printf("};\n\n");

    printf("// Function to search for a key in BST\n");
    printf("struct node* search(struct node* root, int key)\n");
    printf("{\n");
    printf("    // Implementation of searching operation\n");
    printf("}\n\n");

    printf("// Function to insert a new key into BST\n");
    printf("struct node* insert(struct node* root, int key)\n");
    printf("{\n");
    printf("    // Implementation of insertion operation\n");
    printf("}\n\n");

    printf("// Function to delete a key from BST\n");
    printf("struct node* deleteNode(struct node* root, int key)\n");
    printf("{\n");
    printf("    // Implementation of deletion operation\n");
    printf("}\n\n");

    printf("// Traversal functions (In-order, Pre-order, Post-order)\n");
    printf("// You can use these functions to display the content of the BST\n");
    printf("void inOrderTraversal(struct node* root)\n");
    printf("{\n");
    printf("    // Implementation of in-order traversal\n");
    printf("}\n\n");

    printf("void preOrderTraversal(struct node* root)\n");
    printf("{\n");
    printf("    // Implementation of pre-order traversal\n");
    printf("}\n\n");

    printf("void postOrderTraversal(struct node* root)\n");
    printf("{\n");
    printf("    // Implementation of post-order traversal\n");
    printf("}\n\n");

    int on;
    printf("\n ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Want to See the Functioning?                      |\n");
    printf("  | Press 1 to see, otherwise Press 0 for Cancel:     |\n");
    printf("  |___________________________________________________|\n");
    printf("Enter Your Choice:\t");
    scanf("%d", &on);
    do {
        switch (on) {
            case 1:
                on = seeBinarySearchTreeFunctioning();
                break;
            case 0:
                printf("Enjoy Learning!!\n");
                on = 0;
                break;
            default:
                printf("\nInvalid Choice\n");
                on=0;
                break;
        }
    } while (on != 0);
    return on;
}





// Function to display theory and code for trees
void displayTree() {
    printf("--------------------------------------------------------------------Tree----------------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\nA tree is a hierarchical data structure consisting of nodes. "
           "Nodes have a parent-child relationship, and each node can have multiple child nodes.\n");
    printf("Advantages: Efficient search, insertion, and deletion; supports hierarchical relationships.\n");
    printf("Disadvantages: Complex implementation, additional memory for pointers, and potential tree imbalance.\n\n");

    printf("\nA tree data structure is a hierarchical structure that is used to represent and organize data "
           "in a way that is easy to navigate and search. It is a collection of nodes that are connected by "
           "edges and has a hierarchical relationship between the nodes.\n");
    printf("\nThe topmost node of the tree is called the root, and the nodes below it are called the child nodes. "
           "Each node can have multiple child nodes, and these child nodes can also have their own child nodes, "
           "forming a recursive structure.\n");
    printf("\nThis data structure is a specialized method to organize and store data in the computer to be used more effectively. "
           "It consists of a central node, structural nodes, and sub-nodes, which are connected via edges. "
           "We can also say that the tree data structure has roots, branches, and leaves connected with one another.\n\n");

    printf("\n");
    printf("\nBasic Terminologies In Tree Data Structure:\n");
    printf("* Parent Node: The node which is a predecessor of a node is called the parent node of that node. {B} is the parent node of {D, E}.\n");
    printf("* Child Node: The node which is the immediate successor of a node is called the child node of that node. Examples: {D, E} are the child nodes of {B}.\n");
    printf("* Root Node: The topmost node of a tree or the node which does not have any parent node is called the root node. {A} is the root node of the tree. "
           "A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.\n");
    printf("* Leaf Node or External Node: The nodes which do not have any child nodes are called leaf nodes. {K, L, M, N, O, P, G} are the leaf nodes of the tree.\n");
    printf("* Ancestor of a Node: Any predecessor nodes on the path of the root to that node are called Ancestors of that node. {A,B} are the ancestor nodes of the node {E}\n");
    printf("* Descendant: Any successor node on the path from the leaf node to that node. {E,I} are the descendants of the node {B}.\n");
    printf("* Sibling: Children of the same parent node are called siblings. {D,E} are called siblings.\n");
    printf("* Level of a node: The count of edges on the path from the root node to that node. The root node has level 0.\n");
    printf("* Internal node: A node with at least one child is called Internal Node.\n");
    printf("* Neighbour of a Node: Parent or child nodes of that node are called neighbors of that node.\n");
    printf("* Subtree: Any node of the tree along with its descendant.\n");

    printf("\nRepresentation of Tree Data Structure:\n");
    printf("A tree consists of a root and zero or more subtrees T1, T2,- - -, Tk such that there is an edge from the root of the tree to the root of each subtree.\n");

    printf("\nRepresentation of a Node in Tree Data Structure:\n");
    printf("struct Node\n");
    printf("{\n");
    printf("   int data;\n");
    printf("   struct Node *first_child;\n");
    printf("   struct Node *second_child;\n");
    printf("   struct Node *third_child;\n");
    printf("};\n");

    printf("\nTypes of Tree data structures:\n");
    printf("* Binary tree: In a binary tree, each node can have a maximum of two children linked to it. "
           "Some common types of binary trees include full binary trees, complete binary trees, balanced binary trees, "
           "and degenerate or pathological binary trees.\n");
    printf("* Ternary Tree: A Ternary Tree is a tree data structure in which each node has at most three child nodes, "
           "usually distinguished as 'left', 'mid' and 'right'.\n");
    printf("* N-ary Tree or Generic Tree: Generic trees are a collection of nodes where each node is a data structure that consists of records "
           "and a list of references to its children (duplicate references are not allowed). Unlike the linked list, each node stores the address of multiple nodes.\n");

    printf("\nBasic Operation Of Tree Data Structure:\n");
    printf("* Create – create a tree in the data structure.\n");
    printf("* Insert − Inserts data in a tree.\n");
    printf("* Search − Searches specific data in a tree to check whether it is present or not.\n");
    printf("* Traversal:\n");
    printf("* Preorder Traversal – perform Traveling a tree in a pre-order manner in the data structure.\n");
    printf("* In order Traversal – perform Traveling a tree in an in-order manner.\n");
    printf("* Post-order Traversal – perform Traveling a tree in a post-order manner\n");

    int on;

    printf("   ___________________________________________________\n");
    printf("  |                                                   |\n");
    printf("  | Press 1 to see, Binary Tree                       |\n");
    printf("  | Press 2 to see, Binary Search Tree                |\n");
    printf("  | Press 0 for Cancel                                |\n");
    printf("  |___________________________________________________|\n"); 
    printf("Enter Your Choice:\t");
    scanf("%d",&on);
   do {
        switch (on) {
            case 1:
                on=displayBinaryTree();
                break;
            case 2:
                on=displayBinarySearchTree();
                break;
            case 0:
                printf("\nEnjoy Learning!!\n");
                break;
            default:
            printf("\nInvalid Choice\n");
            on=0;
            break;
        }

    } while (on != 0);
}





//------------------------Tree Explanation End Here----------------------------------------------------------------------------------------













int main() {
    int choice;

    do {
        // Display menu
    printf("\n\n\t\t\t\t\t\t\t\tWelcome to Data Structure Learning Tutorials:\n");
printf("\n\n\t\t\t\t\t\t\t\t ________________________________\n");
    printf("\t\t\t\t\t\t\t\t|           **MENU**             |\n");
    printf("\t\t\t\t\t\t\t\t|                                |\n");
    printf("\t\t\t\t\t\t\t\t| 1. Array                       |\n");
    printf("\t\t\t\t\t\t\t\t| 2. Linked List                 |\n");
    printf("\t\t\t\t\t\t\t\t| 3. Stack                       |\n");
    printf("\t\t\t\t\t\t\t\t| 4. Queue                       |\n");
    printf("\t\t\t\t\t\t\t\t| 5. Tree                        |\n");
    printf("\t\t\t\t\t\t\t\t| 0. Exit                        |\n");
    printf("\t\t\t\t\t\t\t\t|________________________________|\n");
        // Get user input
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                displayArray();
                break;
            case 2:
                displayLinkedList();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                displayTree();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}
