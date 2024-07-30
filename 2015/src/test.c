#include "misc.h"

struct Linked_list {
        char *key;
        u16 value;
        struct Linked_list *next;
};

struct Linked_list* list_init(struct Linked_list *head, char const *str, u16 value);
void list_push(struct Linked_list *head, char *str, u16 value);
void list_free(struct Linked_list *head);
void list_print(struct Linked_list *head);
void list_search_key(struct Linked_list *head, char *str);

int main(void)
{
        // char **str = malloc(2);
        // for (int i = 0; i < 1; i++) {
        //         *str= malloc(2);
        // }
        // struct Linked_list *head = NULL;
        // head = list_init(head, "mimi", 1);
        // list_push(head, "mike", 2);
        // list_print(head);
        // NL();
        // list_search_key(head, "mi");
        //
        // list_free(head);
        return 0;
}

struct Linked_list*
list_init(struct Linked_list *head, char const *str, u16 value)
{
        head = malloc(sizeof(*head));
        head->key = strdup(str);
        head->value = value;
        head->next = NULL;

        return head;

}

void
list_push(struct Linked_list *head, char *str, u16 value)
{
        struct Linked_list *current = head;

        while (current->next) {
                current = current->next;
        }

        current->next = malloc(sizeof(*current));
        current->next->key = strdup(str);
        current->next->value = value;
        current->next->next = NULL;
}

void
list_print(struct Linked_list *head)
{
        struct Linked_list *current = head;
        while (current) {
                printf("%s = %d\n", current->key, current->value);
                // NL();
                current = current->next;
        }
}

void
list_search_key(struct Linked_list *head, char *str)
{
        struct Linked_list *current = head;

        while (current) {
                if (strcmp(current->key, str) == 0) {
                        printf("key founded\n");
                        printf("%s = %d\n", current->key, current->value);
                        return;
                }
                current = current->next;
        }

        printf("No key founded\n");
}

void
list_free(struct Linked_list *head)
{
        struct Linked_list *tmp = NULL;
        while (head) {
                tmp = head;
                head = head->next;
                free(tmp->key);
                free(tmp);
        }
}
