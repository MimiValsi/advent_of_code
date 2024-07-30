#include "misc.h"
#include <stdio.h>
#include <string.h>

struct Linked_list {
        char *wire;
        u32 value;
        struct Linked_list *next;
};

struct Linked_list* list_init(char const *wire, u32 value);
struct Linked_list* list_append(struct Linked_list *head, char const *wire, u32 value);
void list_free(struct Linked_list *head);
void list_print(struct Linked_list *head);
bool list_search_key(struct Linked_list *head, char *wire);

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
        if (!head) {
                perror("Could not allocate head");
                exit(EXIT_FAILURE);
        }

        struct Dyn_str dyn_str;
        char *line = NULL;
        // line = get_line(file);
        // dyn_str = line_split(line, " ");
        // head->wire = strdup(dyn_str.str[2]);
        // head->value = atoi(dyn_str.str[0]);
        // head->next = NULL;
        // // free(line);
        // line = get_line(file);
        // dyn_str = line_split(line, " ");
        // head->next->wire = strdup(dyn_str.str[2]);
        // head->next->value = atoi(dyn_str.str[0]);
        // head->next->next = NULL;
        // list_print(head);
        // free(line);
        for (int i = 0; i < 2; i++) {
                line = get_line(file);
                dyn_str = line_split(line, " ");
                // head->wire = strdup(dyn_str.str[2]);
                // head->value = atoi(dyn_str.str[0]);
                // head->next = NULL;
                list_append(head, dyn_str.str[2], atoi(dyn_str.str[0]));
                // if (isdigit(dyn_str.str[0][0])) {
                //         list_append(head, dyn_str.str[2], atoi(dyn_str.str[0]));
                //         // continue;
                // }
                free(line);
        }
        // list_print(head);

        // free(head);
        list_free(head);
        // free(line);
        fclose(file);
        return 0;
}

// Function is meant to be used inside list_append()
// Start/Allocate a new list
struct Linked_list*
list_init(char const *wire, u32 value)
{
        struct Linked_list *new_list = malloc(sizeof(*new_list));
        if (!new_list) {
                perror("Couldn't allocate new list\n");
                return NULL;
        }
        new_list->wire = strdup(wire);
        new_list->value = value;
        new_list->next = NULL;

        return new_list;

}

// Append data to the end of the linked list
struct Linked_list*
list_append(struct Linked_list *head, char const *wire, u32 value)
{

        struct Linked_list *new_list = list_init(wire, value);
        if (!new_list) {
                // I shouldn't do this but will stay for now
                exit(EXIT_FAILURE);
        }

        if (!head) {
                return new_list;
        }

        struct Linked_list *tail = head;
        while (tail->next != NULL) {
                tail = tail->next;
        }

        tail->next = new_list;

        return head;

}

void
list_print(struct Linked_list *head)
{
        // struct Linked_list *current = head;
        while (head) {
                printf("%s = %d\n", head->wire, head->value);
                // NL();
                head = head->next;
        }
}

bool
list_search_key(struct Linked_list *head, char *wire)
{
        struct Linked_list *current = head;

        while (current) {
                if (strcmp(current->wire, wire) == 0) {
                        printf("wire founded\n");
                        printf("%s = %d\n", current->wire, current->value);
                        return true;
                }
                current = current->next;
        }

        printf("No wire founded\n");
        return false;
}

void
list_free(struct Linked_list *head)
{
        struct Linked_list *tmp = NULL;
        while (head) {
                tmp = head;
                head = head->next;
                free(tmp->wire);
                free(tmp);
        }
}

