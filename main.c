#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inisiasi stack dan queue
typedef struct Node
{
    char imigran[20];
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} Stack;

typedef struct
{
    Node *head;
    Node *tail;
} Queue;

// Silakan manfaatkan template kode tutorial modul
// berikut jika dirasa mempermudah pengerjaan

// cek kondisi stack kosong
int isStackEmpty(Stack *stack)
{
    return stack->head == NULL;
}

// memindahkan data file ke dalam stack
void push(Stack *stack, const char *new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->imigran, new_data);
    new_node->next = stack->head;
    stack->head = new_node;
}

// Next, mengambil data paling atas stack
char *pop(Stack *stack)
{
    char *ret_val = NULL;
    Node *temp = stack->head;
    if (temp != NULL)
    {
        ret_val = (char *)malloc(strlen(temp->imigran) + 1);
        strcpy(ret_val, temp->imigran);
        stack->head = temp->next;
        free(temp);
    }
    return (ret_val);
}

// untuk debugging
void printStack(Stack *stack)
{
    Node *current = stack->head;
    int i = 1;
    while (current != NULL)
    {
        printf("%d %s\n", i, current->imigran);
        current = current->next;
        i++;
    }
    printf("\n");
}

// cek kondisi queue kosong
int isQueueEmpty(Queue *queue)
{
    return queue->head == NULL;
}

// Next, memasukkan data ke akhir queue
void enqueue(Queue *queue, const char *new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->imigran, new_data);
    new_node->next = NULL;
    if (!isQueueEmpty(queue))
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    else
    {
        queue->tail = new_node;
        queue->head = new_node;
    }
}

// Done, menghapus data di awal queue
char *dequeue(Queue *queue)
{
    char *ret_val = NULL;
    Node *temp = queue->head;
    if (temp != NULL)
    {
        ret_val = (char *)malloc(strlen(temp->imigran) + 1);
        strcpy(ret_val, temp->imigran);
        queue->head = temp->next;
        if (temp == queue->tail)
            queue->tail = NULL;
        free(temp);
    }
    return ret_val;
}

// Observe, print isi queue
void printQueue(Queue *queue)
{
    Node *current = queue->head;
    int i = 1;
    while (current != NULL)
    {
        printf("%d %s\n", i, current->imigran);
        current = current->next;
        i++;
    }
}

int main()
{
    // inisiasi
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    // Input
    char file[255];
    // file
    printf("Masukkan hari: ");
    scanf("%s", &file);
    FILE *stream = fopen(file, "r");
    if (stream == NULL)
    {
        printf("Hari libur!\n");
        return 0;
    }
    // data
    char line[255];
    char *token;
    int i = 0;
    while (fgets(line, 255, stream))
    {
        token = strtok(line, "\n");
        push(stack, token);
    }
    fclose(stream);

    // uncomment untuk lihat isi stack
    // printStack(stack);

    // Program
    int jumlah = 0;
    char perintah[8];
    printf("\n>> ");
    scanf("%s", &perintah);
    while (strcmp(perintah, "Rest"))
    {
        if (!strcmp(perintah, "Next"))
        {
            if (isStackEmpty(stack))
            {
                printf("Pengunjung habis!\n");
            }
            else
            {
                enqueue(queue, pop(stack));
            }
        }
        if (!strcmp(perintah, "Done"))
        {
            if (isQueueEmpty(queue))
            {
                printf("Pos kosong!\n");
            }
            else
            {
                dequeue(queue);
                jumlah++;
            }
        }
        if (!strcmp(perintah, "Observe"))
        {
            printQueue(queue);
        }
        if (!strcmp(perintah, "Monitor"))
        {
            printf("Jumlah imigran adalah %d\n", jumlah);
        }

        printf("\n>> ");
        scanf("%s", &perintah);
    }
    printf("Selesai");

    return 0;
}
