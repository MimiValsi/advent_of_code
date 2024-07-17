#include "../misc/misc.h"
#include <stdlib.h>
#include <string.h>

struct Link_list {
        char *key;
        u16 value;
        struct Link_list *next;
};

struct Link_list* map_init(struct Link_list *head, char const *str, u16 value);
void map_push(struct Link_list *head, char *str, u16 value);
void map_free(struct Link_list *head);
void map_print(struct Link_list *head);
struct Link_list* map_search_key(struct Link_list *head, char *str);

int main(void)
{
        struct Link_list *head = NULL;
        head = map_init(head, "mimi", 1);
        // map_print(head);

        map_free(head);
        return 0;
}

struct Link_list*
map_init(struct Link_list *head, char const *str, u16 value)
{
        head = malloc(sizeof(*head));
        head->key = strdup(str);
        head->value = value;

        return head;

}

void
map_push(struct Link_list *head, char *str, u16 value)
{
        head = malloc(sizeof(*head));
        struct Link_list *current = head;

        while (current->next) {
                current = current->next;
        }

        current->next = malloc(sizeof(*current));
        current->next->key = malloc(64);
        strcpy(current->next->key, str);
        current->next->value = value;
        current->next->next = NULL;
}

void
map_print(struct Link_list *head)
{
        struct Link_list *current = head;
        while (current) {
                printf("current->key = %s\n", current->key);
                printf("current->value = %d\n", current->value);
                // NL();
                current = current->next;
        }
}

struct Link_list*
map_search_key(struct Link_list *head, char *str)
{
        struct Link_list *current = head;

        while (current->next != NULL) {
                if (strcmp(current->key, str) == 0) {
                        return current;
                }
                current = current->next;
        }

        return NULL;
}

void
map_free(struct Link_list *head)
{
        struct Link_list *tmp = NULL;
        while (head) {
                tmp = head;
                head = head->next;
                free(tmp->key);
                free(tmp);
        }
}
