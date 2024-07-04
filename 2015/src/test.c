#include <stdio.h>
#include <string.h>
#include "../misc/misc.h"


typedef struct Map {
        char *key;
        u16 value;
        struct Map *next;
} Map_t;

void map_push(Map_t *head, char *str, u16 value);
void map_print(Map_t *head);
void map_free(Map_t *head);
Map_t* map_search_key(Map_t *head, char *str);

int main(void)
{
        Map_t *head = malloc(sizeof(Map_t));
        if (!head) {
                return -1;
        }
        char *s = malloc(5);
        // s = "Mike";
        // s = strdup("Mike");
        strcpy(s, "Mike");
        printf("%s\n", s);
        free(s); // <-- invalide pointer error

        head->key = "Mimi";
        head->value = 1;
        printf("head.key = %s\n", head->key);
        printf("head.value = %d\n", head->value);

        free(head);



        // head->key = "Mike";
        // head->value = 10;
        // head->next = NULL;

        // map_push(head, "Baboue", 20);
        // map_push(head, "Babou", 30);
        // map_push(head, "Aure", 70);

        // Map_t *tmp = map_search_key(head, "Baboue");
        // printf("tmp->key = %s\n", tmp->key);
        // printf("tmp->value = %d\n\n", tmp->value);
        //
        // map_print(head);
        //
        // map_free(head);
        // free(head);

        return 0;
}

void
map_push(Map_t *head, char *str, u16 value)
{
        Map_t *current = head;

        while (current->next != NULL) {
                current = current->next;
        }

        current->next = malloc(sizeof(Map_t));
        current->next->key = str;
        // strcpy(current->next->key, str);
        current->next->value = value;
        current->next->next = NULL;
}

void
map_print(Map_t *head)
{
        Map_t *current = head;

        while (current != NULL) {
                printf("current->key = %s\n", current->key);
                printf("current->value = %d\n", current->value);
                NL();
                current = current->next;
        }
}

Map_t*
map_search_key(Map_t *head, char *str)
{
        Map_t *current = head;

        while (current->next != NULL) {
                if (strcmp(current->key, str) == 0) {
                // if (current->key == str) {
                        return current;
                }
                current = current->next;
        }

        return NULL;
}

void
map_free(Map_t *head)
{
        Map_t *tmp;
        while (head != NULL) {
                tmp = head;
                head = head->next;
                free(tmp);
        }
}
