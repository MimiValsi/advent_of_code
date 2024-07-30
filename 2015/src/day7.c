#include "misc.h"
#include <stdio.h>
#include <string.h>

struct Linked_list {
        char *wire;
        u32 value;
        struct Linked_list *next;
};

struct Linked_list* list_init(char const *wire, u32 value);
struct Linked_list *list_append(struct Linked_list *head, char *wire, u32 value);
void list_free(struct Linked_list *head);
void list_print(struct Linked_list *head);
void list_search_key(struct Linked_list *head, char *wire);

/* ll   AND  ld   ->   dl
 * [0]  [1]  [2]  [3]  [4]
 *
 * 123  ->   x
 * [0]  [1]  [2]
 * */

int main(void)
{
        // FILE *file = fopen("data/day7.txt", "r");
        FILE *file = fopen("data/test.txt", "r");
        if (!file) {
                printf("File does not exist\n");
                fclose(file);
                exit(EXIT_FAILURE);
        }
        struct Linked_list *head = malloc(sizeof(*head));

        struct Dyn_str dyn_str;
        char *line = NULL;
        for (int i = 0; i < 2; i++) {
                line = get_line(file);
                dyn_str = line_split(line, " ");
                if (isdigit(dyn_str.str[0][0])) {
                        list_append(head, dyn_str.str[2], atoi(dyn_str.str[0]));
                        // continue;
                }
                free(line);
        }
        // list_print(head);

        // free(head);
        list_free(head);
        // free(line);
        fclose(file);
        return 0;
}

struct Linked_list*
list_init(char const *wire, u32 value)
{
        struct Linked_list *head = malloc(sizeof(*head));
        if (!head) {
                perror("Couldn't allocated new list");
                exit(EXIT_FAILURE);
        }

        head->wire = strdup(wire);
        head->value = value;
        head->next = NULL;

        return head;

}

struct Linked_list*
list_append(struct Linked_list *head, char *wire, u32 value)
{
        struct Linked_list *new_list = list_init(wire, value);

        if (!head) {
                return new_list;
        }

        struct Linked_list *tail = head;
        while (tail->next) {
                tail = tail->next;
        }

        tail->next = new_list;

        return head;
}

void
list_print(struct Linked_list *head)
{
        // struct Linked_list *current = head;
        while (head->next) {
                printf("%s = %d\n", head->wire, head->value);
                // NL();
                head = head->next;
        }
}

void
list_search_key(struct Linked_list *head, char *wire)
{
        struct Linked_list *current = head;

        while (current) {
                if (strcmp(current->wire, wire) == 0) {
                        printf("wire founded\n");
                        printf("%s = %d\n", current->wire, current->value);
                        return;
                }
                current = current->next;
        }

        printf("No wire founded\n");
}

void
list_free(struct Linked_list *head)
{
        struct Linked_list *tmp = NULL;
        while (head->next) {
                tmp = head;
                head = head->next;
                free(tmp->wire);
                free(tmp);
        }
}

