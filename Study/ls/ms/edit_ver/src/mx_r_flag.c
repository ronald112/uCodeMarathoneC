#include "uls.h"

void mx_r_flag(t_main *info, t_catalog *cat, char *link) {
	DIR *directoy = mx_opendir_info(info, cat, link);
	t_dir_data *list = cat->dir;
	struct dirent *temp = NULL;
	t_catalog *cat_local = NULL;
	t_catalog *head = NULL;
	printf("[[Debug]]\n");

	// printf("%p\n", (void *)directoy);

	if (directoy && (temp = readdir(directoy))) {
		put_data(temp, info, list, cat, link);
	printf("[[Debug]]\n");
		if(MX_ISDIR(list->buff_stat->st_mode)) {
	printf("[[Debug]]\n");
			cat_local = (t_catalog *)malloc(sizeof(t_catalog));
			cat_local->c_name = list->name;
			head = cat_local;
			cat_local->c_next = NULL;
		}
	}
	while (directoy && (temp = readdir(directoy))) {
		list->next = (t_dir_data *)malloc(sizeof(t_dir_data));
		list = list->next;
		put_data(temp, info, list, cat, link);
		if(MX_ISDIR(list->buff_stat->st_mode)) {
			cat_local->c_next = (t_catalog *)malloc(sizeof(t_catalog));
			cat_local = cat_local->c_next;
			cat_local->c_name = list->name;
			cat_local->c_next = NULL;
		}
	}
	mx_sort_cat_list(info->cat, info->flag);
	for(int i = 0; head; head = head->c_next) {
		printf("%d\n", i++);
		mx_r_flag(info, head, head->c_name);
		mx_print_1(head, info->flag.is_a);
		printf("\n---------\n");
	}
	mx_closedir_info(info, directoy, link);
}
