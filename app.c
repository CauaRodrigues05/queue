#include "include.h"

#define TABLES_MAX 6

int client_queue_to_table(table_t** tables, client_t** clients, int client_id)
{
    table_t* temp = *tables;
    while(temp != NULL)
    {
        if(temp->client == NULL)
        {
            insert_client(&(temp->client), client_id);
            remove_client(clients);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void main()
{
    table_t* tables = NULL;
    client_t* clients = NULL;
    int client_count = 0;

    for(int i = 0; i < TABLES_MAX; i++)
    {
        insert_table(&tables, i);
    }
    int option = -1;
    while(option >= -1 && option < 4)
    {
        print_client(clients);
        printf("\n");
        print_table(tables);
        printf("\n");
        printf("0- Adicionar cliente a fila; 1- Expulsar cliente da mesa\n");
        scanf("%i", &option);

        switch (option)
        {
        case 0:
            int client_id;
            client_id = client_count;
            if(insert_client(&clients, client_count))
            {
                printf("Cliente adicionado com sucesso\n");
                client_count++;
            }
            else
            {
                printf("Não foi possivel adicionar o cliente\n");
                break;
            }

            client_queue_to_table(&tables, &clients, client_id);
            break;
        case 1:
            int table_id;
            printf("Insira o 'id' da mesa\n");
            scanf("%i", &table_id);
            printf("\n");

            table_t* table_ref = get_table(&tables, table_id);
            if(table_ref == NULL)
            {
                printf("Mesa nao encontrada\n");
                break;
            }
            client_t* client_ref = table_ref->client;
            if(remove_table_client(&tables, table_id))
            {
                free(client_ref);
                client_ref = NULL;
                client_t* client_queue_ref = get_client(&clients);
                if(client_queue_ref == NULL)
                {
                    printf("Nenhum cliente esperando na fila\n");
                    break;
                }
                client_queue_to_table(&tables, &clients, client_queue_ref->id);
            }
            printf("Cliente da mesa %i foi expulso\n", table_id);
        default:
            break;
        }
    }
    remove_all_tables(&tables);
    remove_all_clients(&clients);

    return;
}