#include "table.h"

table_t *allocate_table(int id)
{
    table_t *table = NULL;
    table = (table_t *)malloc(sizeof(table_t));
    if (table == NULL) return NULL;
    table->id = id;
    table->client = NULL;
    table->next = NULL;
    return table;
}

void insert_table(table_t **tables, int id)
{
    table_t* new_table = NULL;
    new_table = allocate_table(id);
    if(!new_table) return;
    new_table->next = *tables;
    *tables = new_table;
}

table_t* get_table(table_t** tables, int id)
{
    table_t* temp = *tables;
    if(temp == NULL) return NULL;
    while(temp && temp->id != id) temp = temp->next;
    return temp;
}

void print_table(table_t* tables)
{
    if(!tables) return;
    printf("Table id: %i, Client id: %i\n", tables->id, tables->client ? tables->client->id : -1);
    print_table(tables->next);
}

int remove_table_client(table_t** tables, int id)
{
    table_t* temp = *tables;
    while(temp)
    {
        if(temp->id == id)
        {
            temp->client = NULL;
            break;
        }
        temp = temp->next;
    }
    if(!temp) return 0;
    return 1;
}

void remove_table(table_t** tables)
{
    table_t* temp = *tables;
    if(temp == NULL) return;
    *tables = temp->next;
    remove_all_clients(&temp->client);
    free(temp);
}

void remove_all_tables(table_t** tables)
{
    while(*tables) remove_table(tables);
}