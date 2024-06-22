#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct client
{
    int id;
    struct client *next;
} client_t;

client_t* allocate_client(int id);
int insert_client(client_t **clients, int id);
client_t* get_client(client_t** clients);
void print_client(client_t* clients);
void remove_client(client_t **clients);
void remove_all_clients(client_t **clients);


#endif