#include "client.h"

client_t* allocate_client(int id)
{

    client_t* client = NULL;
    client = (client_t*)malloc(sizeof(client_t));
    if(!client) return NULL;
    client->id = id;
    client->next = NULL;
    return client;
}

int insert_client(client_t** clients, int id)
{
    client_t* client = NULL;
    client = allocate_client(id);
    if(client == NULL) return 0;
    client->next = *clients;
    *clients = client;
    return 1;
}

client_t* get_client(client_t** clients)
{
    client_t* temp = *clients;
    if(!temp) return NULL;
    while(temp->next) temp =  temp->next;
    return temp;
}

void print_client(client_t* clients)
{
    if(!clients) return;
    printf("Client id: %i\n", clients->id);
    print_client(clients->next);
}

void remove_client(client_t** clients)
{
    client_t* temp = *clients;
    client_t* prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    
    free(temp);
    if(prev == NULL) *clients = NULL;
    else prev->next = NULL;
}

void remove_all_clients(client_t** clients)
{
    while(*clients) remove_client(clients);
}