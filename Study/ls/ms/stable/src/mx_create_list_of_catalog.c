#include "uls.h"

t_catalog *mx_create_list_of_catalog(int amount) {
	t_catalog *head = (t_catalog *)malloc(sizeof(t_catalog));
	t_catalog *node = head;

	head->c_next = NULL;
	for(int i = 1; i < amount; i++) {
		node->c_next = (t_catalog *)malloc(sizeof(t_catalog));
		node = node->c_next;
		node->c_next = NULL;
	}
	return head;
}
