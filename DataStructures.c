#include <stdio.h> 
#include <stdlib.h> 
// Structure to represent a node in the BST 
struct Node  
{ 
}; 
int data; 
struct Node* left; 
struct Node* right; 
// Function to initialize an empty BST 
struct Node* initializeBST()  
{ 
return NULL; 
} 
// Function to insert a node into the BST 
struct Node* insertNode(struct Node* root, int value)  
{ 
if (root == NULL)  
{ 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = value; 
newNode->left = newNode->right = NULL; 
return newNode; 
} 
if (value < root->data)  
{ 
root->left = insertNode(root->left, value);
}  
    else if (value > root->data)  
    { 
        root->right = insertNode(root->right, value); 
    } 
 
    return root; 
} 
 
// Function to find the minimum value in the BST 
int findMinimum(struct Node* root)  
{ 
    if (root == NULL)  
    { 
        printf("The BST is empty.\n"); 
        return -1; 
    } 
 
    while (root->left != NULL)  
    { 
        root = root->left; 
    } 
 
    return root->data; 
} 
 
// Function to find the maximum value in the BST 
int findMaximum(struct Node* root)  
{ 
    if (root == NULL)  
    { 
        printf("The BST is empty.\n"); 
        return -1; 
    } 
 
    while (root->right != NULL)
 { 
        root = root->right; 
    } 
 
    return root->data; 
} 
 
// Function to delete a node from the BST 
struct Node* deleteNode(struct Node* root, int value)  
{ 
    if (root == NULL)  
    { 
        printf("Value %d not found in the BST.\n", value); 
        return root; 
 } 
 
    if (value < root->data)  
    { 
        root->left = deleteNode(root->left, value); 
    }  
    else if (value > root->data)  
    { 
        root->right = deleteNode(root->right, value); 
    }  
    else  
    { 
        if (root->left == NULL)  
        { 
            struct Node* temp = root->right; 
            free(root); 
            return temp; 
        }  
        else if (root->right == NULL)  
        { 
            struct Node* temp = root->left; 
            free(root); 
            return temp; 
        } 
 
        struct Node* temp = root->right; 
        while (temp->left != NULL)  
        { 
            temp = temp->left; 
        } 
 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
 
    return root; 
} 
 
// Function to display the BST in inorder traversal 
void displayInorder(struct Node* root)  
{ 
    if (root == NULL)  
    { 
        return; 
    } 
 
    displayInorder(root->left); 
    printf("%d ", root->data); 
    displayInorder(root->right); 
}
int main()  
{ 
    struct Node* root = initializeBST(); 
 
    while (1)  
    { 
        printf("\nBinary Search Tree Menu:\n"); 
        printf("1. Insert a node\n"); 
        printf("2. Delete a node\n"); 
        printf("3. Find Minimum\n"); 
        printf("4. Find Maximum\n"); 
        printf("5. Display Inorder Traversal\n"); 
        printf("6. Exit\n"); 
 
        int choice, value; 
 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice)  
        { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                root = insertNode(root, value); 
                break; 
 
            case 2: 
                printf("Enter value to delete: "); 
                scanf("%d", &value); 
                root = deleteNode(root, value); 
                break; 
 
            case 3: 
                printf("Minimum value: %d\n", findMinimum(root)); 
                break; 
 
            case 4: 
                printf("Maximum value: %d\n", findMaximum(root)); 
                break; 
 
            case 5: 
                printf("Inorder Traversal: "); 
                displayInorder(root); 
                printf("\n"); 
                break; 
 
            case 6: 
                exit(0);
default: 
printf("Invalid choice. Try again.\n"); 
break; 
} 
} 
return 0; 
} 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Define the structure for a song node 
struct Song { 
char title[100]; 
char artist[100]; 
struct Song* next; 
}; 
// Function to create a new song node 
struct Song* createSong(const char* title, const char* artist) { 
struct Song* newSong = (struct Song*)malloc(sizeof(struct Song)); 
if (newSong == NULL) { 
printf("Memory allocation failed.\n"); 
return NULL; 
} 
strncpy(newSong->title, title, sizeof(newSong->title)); 
strncpy(newSong->artist, artist, sizeof(newSong->artist)); 
newSong->next = NULL; 
return newSong; 
}
// Function to add a song to the end of the playlist 
struct Song* addSong(struct Song* playlist, const char* title, const char* artist) { 
struct Song* newSong = createSong(title, artist); 
if (newSong == NULL) { 
return playlist; 
} 
if (playlist == NULL) { 
playlist = newSong; 
playlist->next = playlist; // Circular link to itself 
} else { 
struct Song* current = playlist; 
while (current->next != playlist) { 
current = current->next; 
} 
current->next = newSong; 
newSong->next = playlist; 
} 
return playlist; 
} 
// Function to skip to the next song 
struct Song* skipToNext(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
return playlist; 
} 
playlist = playlist->next; // Move to the next song 
return playlist; 
} 
// Function to remove the currently playing song 
struct Song* removeCurrentSong(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
return playlist; 
} 
if (playlist->next == playlist) { 
// Only one song in the playlist 
free(playlist); 
return NULL; 
} 
struct Song* current = playlist; 
while (current->next != playlist) {
current = current->next; 
} 
struct Song* temp = playlist; 
current->next = playlist->next; // Remove the current song from the circular list 
playlist = playlist->next; // Move to the next song 
free(temp); 
return playlist; 
} 
// Function to display the currently playing song 
void displayCurrentSong(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
} else { 
printf("Currently Playing: %s by %s\n", playlist->title, playlist->artist); 
} 
} 
// Function to display the entire playlist 
void displayPlaylist(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
return; 
} 
struct Song* current = playlist; 
do { 
printf("%s by %s\n", current->title, current->artist); 
current = current->next; 
} while (current != playlist); 
} 
int main() { 
struct Song* playlist = NULL; 
int choice; 
char title[100], artist[100]; 
while (1) { 
printf("\nMenu:\n"); 
printf("1. Add a Song\n"); 
printf("2. Skip to Next Song\n"); 
printf("3. Remove Currently Playing Song\n"); 
printf("4. Display Currently Playing Song\n"); 
printf("5. Display Playlist\n"); 
printf("6. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice);
current = current->next; 
} 
struct Song* temp = playlist; 
current->next = playlist->next; // Remove the current song from the circular list 
playlist = playlist->next; // Move to the next song 
free(temp); 
return playlist; 
} 
// Function to display the currently playing song 
void displayCurrentSong(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
} else { 
printf("Currently Playing: %s by %s\n", playlist->title, playlist->artist); 
} 
} 
// Function to display the entire playlist 
void displayPlaylist(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
return; 
} 
struct Song* current = playlist; 
do { 
printf("%s by %s\n", current->title, current->artist); 
current = current->next; 
} while (current != playlist); 
} 
int main() { 
struct Song* playlist = NULL; 
int choice; 
char title[100], artist[100]; 
while (1) { 
printf("\nMenu:\n"); 
printf("1. Add a Song\n"); 
printf("2. Skip to Next Song\n"); 
printf("3. Remove Currently Playing Song\n"); 
printf("4. Display Currently Playing Song\n"); 
printf("5. Display Playlist\n"); 
printf("6. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice);
#include <stdio.h> 
#include <stdlib.h> 
// Define the structure for a queue node 
struct QueueNode { 
int data; 
struct QueueNode* next; 
}; 
// Define the circular queue structure 
struct CircularQueue { 
struct QueueNode* front; 
struct QueueNode* rear; 
}; 
// Function to create an empty circular queue 
struct CircularQueue* createCircularQueue() { 
struct 
CircularQueue* 
CircularQueue)); 
if (queue == NULL) { 
queue 
= 
printf("Memory allocation failed.\n"); 
return NULL; 
} 
queue->front = NULL; 
queue->rear = NULL; 
return queue; 
} 
(struct 
// Function to check if the circular queue is empty 
int isEmpty(struct CircularQueue* queue) { 
return (queue->front == NULL); 
} 
// Function to enqueue an element into the circular queue 
void enqueue(struct CircularQueue* queue, int value) { 
struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode)); 
if (newNode == NULL) { 
printf("Memory allocation failed.\n"); 
return; 
} 
newNode->data = value; 
newNode->next = NULL; 
if (isEmpty(queue)) { 
// If the queue is empty, set both front and rear to the new node 
queue->front = newNode; 
queue->rear = newNode; 
newNode->next = newNode; // Circular link to itself 
} else { 
// Link the new node to the rear and update the rear 
newNode->next = queue->front; // Circular link 
queue->rear->next = newNode; 
queue->rear = newNode; 
} 
} 
// Function to dequeue an element from the circular queue 
int dequeue(struct CircularQueue* queue) { 
if (isEmpty(queue)) { 
printf("Queue is empty. Cannot dequeue.\n"); 
return -1; // Return a sentinel value for an empty queue 
} 
int removedValue; 
struct QueueNode* temp = queue->front; 
if (queue->front == queue->rear) { 
// If there is only one element in the queue 
removedValue = temp->data; 
queue->front = NULL; 
queue->rear = NULL; 
free(temp); 
} else { 
// Remove and update the front of the queue 
removedValue = temp->data; 
queue->front = temp->next; 
queue->rear->next = queue->front; // Circular link 
free(temp); 
}
 return removedValue; 
} 
 
// Function to display the elements in the circular queue 
void displayQueue(struct CircularQueue* queue) { 
    if (isEmpty(queue)) { 
        printf("Queue is empty.\n"); 
        return; 
    } 
 
    struct QueueNode* current = queue->front; 
    printf("Circular Queue: "); 
    do { 
        printf("%d -> ", current->data); 
        current = current->next; 
    } while (current != queue->front); 
    printf(" (front)\n"); 
} 
 
int main() { 
    struct CircularQueue* queue = createCircularQueue(); 
    int choice, value; 
 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Enqueue\n"); 
        printf("2. Dequeue\n"); 
        printf("3. Display Queue\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter a value to enqueue: "); 
                scanf("%d", &value); 
                enqueue(queue, value); 
                break; 
            case 2: 
                value = dequeue(queue); 
                if (value != -1) { 
                    printf("Dequeued value: %d\n", value); 
                } 
                break; 
            case 3: 
                displayQueue(queue); 
                break; 
            case 4: 
                // Clean up and exit
while (!isEmpty(queue)) { 
dequeue(queue); 
} 
free(queue); 
return 0; 
default: 
printf("Invalid choice. Please try again.\n"); 
} 
} 
return 0;
}
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_URL_LENGTH 100 
// Structure for a node in the stack 
typedef struct Node { 
char url[MAX_URL_LENGTH]; 
struct Node* next; 
} Node; 
// Structure for the stack 
typedef struct { 
Node* top; 
} Stack; 
// Function to initialize an empty stack 
void initialize(Stack* stack) { 
stack->top = NULL; 
} 
// Function to push a URL onto the stack 
void push(Stack* stack, const char* url) { 
Node* newNode = (Node*)malloc(sizeof(Node)); 
if (newNode == NULL) { 
printf("Memory allocation failed.\n"); 
return; 
} 
strncpy(newNode->url, url, MAX_URL_LENGTH); 
newNode->next = stack->top; 
stack->top = newNode; 
} 
// Function to pop a URL from the stack 
void pop(Stack* stack) { 
if (stack->top == NULL) { 
printf("No more URLs in the history.\n"); 
return; 
} 
Node* temp = stack->top; 
stack->top = stack->top->next; 
free(temp); 
} 
// Function to display the current URL 
void displayCurrentURL(Stack* stack) { 
if (stack->top == NULL) { 
printf("No URL currently loaded.\n"); 
} else { 
printf("Current URL: %s\n", stack->top->url); 
} 
} 
int main() { 
Stack historyStack; 
initialize(&historyStack); 
int choice; 
char url[MAX_URL_LENGTH]; 
while (1) { 
printf("\nMenu:\n"); 
printf("1. Visit a URL\n"); 
printf("2. Go Back\n"); 
printf("3. Display Current URL\n"); 
printf("4. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice);
switch (choice) { 
case 1: 
printf("Enter URL to visit: "); 
scanf("%s", url); 
push(&historyStack, url); 
break; 
case 2: 
pop(&historyStack); 
break; 
case 3: 
displayCurrentURL(&historyStack); 
break; 
case 4: 
// Clean up and exit the program 
while (historyStack.top != NULL) { 
pop(&historyStack); 
} 
return 0; 
default: 
printf("Invalid choice. Please try again.\n"); 
} 
} 
return 0; 
}