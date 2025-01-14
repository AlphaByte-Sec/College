#include <iostream>
#include <cstring>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    char name[100];
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* tail = NULL;

void insertNode( char name[100] )
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    strcpy( newNode->name, name );
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if ( head == NULL )
    {
        printf( "[==Membuat Head Baru==]\n" );
        head = newNode;
        tail = newNode; 
    }
    
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter( char find[100], char name[100] )
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    strcpy( newNode->name, name );
    newNode->next = NULL;
    newNode->prev = NULL;
    
    Node* ptr = head;
    
    if ( strcmp(tail->name, find) == 0 )
    {
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        while ( strcmp(ptr->name, find) != 0 )
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void printNode( Node* node )
{
    cout << "[" << node->name << "] --> alamat Ptr " << node << " --> Next Ptr " << node->next << "\n";
}

void printForward()
{
    Node* ptr = head;

    printf( "\nList Data Cetak Maju:\n" );

    if ( head == NULL )
    {
        printf( "Empty!\n" );
    }

    else
    {
        while ( ptr != NULL )
        {
            printNode( ptr );
            ptr = ptr->next;
        }
    }
}

void printBackward()
{
    Node* ptr = tail;

    printf( "\nList Data Cetak Mundur:\n" );
    
    if ( tail == NULL )
    {
        printf( "Empty!\n" );
    }
    
    else
    {
        while ( ptr != NULL )
        {
            printNode( ptr );
            ptr = tail;
        }
    }
}

void printLinkedList()
{
    printForward();
    printf( "\n" );
    printBackward();
}

Node* searchNode( char find[100] )
{
    Node* ptr = head;
    
    while ( strcmp(ptr->name, find) != 0  )
    {
        ptr = ptr->next;
        if ( ptr == NULL )
        {
            return NULL;
        }
    }

    return ptr;
}

int main()
{
    printf( "--SOAL 6--\n" );
    printf( "Entry Serial Data\n\n" );
 
    char input[100];
    char find[100];
    char newInput[100];

    int i = 1;
    do
    {
        printf( "Data ke %d: ", i );
        gets( input );
        
        if ( strlen(input) > 0 )
        {
            insertNode( input );
            ++i;
        }
    } while( strlen(input) > 0 );
    
    printf( "\nJumlah Data: %d\n", (i-1) );
    
    //printLinkedList();

    do {
        printf( "Data yang anda cari: " ); 
        gets( find );
        
        if ( strlen(find) > 0 )
        {
            Node* findNode = searchNode( find );

            if ( findNode == NULL )
            {
                printf( "Data tidak ditemukan!\n" );
            }
            
            else
            {
                cout << "\nData " << findNode->name << " ada pada alamat " << findNode << "\n";
				
				cout << "Data yang disisipkan: ";
				gets( newInput );
				
				insertAfter( find, newInput );
                
                printLinkedList();
            }
        }
    } while( strlen(find) > 0 );
    
    return 0;
}