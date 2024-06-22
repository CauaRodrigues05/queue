#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "client.h"

typedef struct table
{
    int id;
    client_t *client;
    struct table *next;
} table_t;

table_t *allocate_table(int id);
void insert_table(table_t** tables, int id);
table_t* get_table(table_t** tables, int id);
void print_table(table_t* tables);
int remove_table_client(table_t** tables, int id);
void remove_table(table_t** tables);
void remove_all_tables(table_t** tables);

#endif