#include "uls.h"

static t_dir_data *create_node(char *data, t_flag flag, t_catalog *cat) {
	t_dir_data *new_node = NULL;

	if (data && (new_node = (t_dir_data *)malloc(sizeof(t_dir_data)))) {
		new_node->name = mx_strdup(data);
		new_node->path = mx_get_full_path(".", new_node->name);
		// printf("%s\n\n", new_node->path);
		if (flag.is_l == true)
			mx_ladd_to_tdir(new_node, cat, flag);
		new_node->next = NULL;
	}
	return new_node;
}

static void push_back(char *link, t_flag flag, t_catalog *cat) {
	t_dir_data *cur = NULL;
	t_dir_data **list = &cat->dir;

	if (*list == NULL) {
		*list = create_node(link, flag, cat);
	}
	else {
		cur = *list;

		for (; cur->next != NULL; cur = cur->next);
		cur->next = create_node(link, flag, cat);
	}
}

// void mx_make_extra_catalog(t_main *info, char *link) {
// 	t_catalog *head = info->cat;
// 	bool no_exist = true;

// 		printf("==========///=======\n");
// 	while (head) {
// 		if (mx_strcmp(head->c_name, "!!!") == 0) {
// 			push_back(&(head->dir), link);
// 			head->am_files++;
// 			head->dir_data = head->dir;
// 			no_exist = false;
// 		printf("==========///=======\n");
// 			break;
// 		}
// 		head = head->c_next;
// 	}
// 	if (no_exist) {
// 		if(head == NULL) {
// 			info->cat = (t_catalog *)malloc(sizeof(t_catalog));
// 			head = info->cat;
// 		}
// 		else {
// 			head->c_next = (t_catalog *)malloc(sizeof(t_catalog));
// 			head = head->c_next;
// 		}
// 		head->c_name = mx_strdup("!!!");
// 		head->am_files = 1;
// 		head->dir = NULL;
// 		head->c_next = NULL;
// 		push_back(&(head->dir), link);
// 		head->dir_data = head->dir;
// 	}
// }

void mx_make_extra_catalog(t_main *info, char *link) {
	for(t_catalog *head = info->cat; head; head = head->c_next) {
		// printf("%p->%s  %p\n", (void*)head, head->c_name, (void*)head->c_next);
		if(mx_strcmp("!!!", head->c_name) == 0) {
			// printf("***********%s\n", link);
			// printf("%p   %p\n", (void*)head, (void*)head->dir_data);
			// push_back(&head->dir_data, link);
			push_back(link, info->flag, head);
			head->dir_data = head->dir;
			// printf("-----------------\n");
		}
		else if(head->c_next == NULL) {
			// printf("sdfsdfhjksdf\n");
			head->c_next = (t_catalog *)malloc(sizeof(t_catalog));
			head->c_next->c_next = NULL;
			head->c_next->is_dir = true;
			head->c_next->size_of_block = 0;
			head->c_next->max_size_oflink = 0;
			head->c_next->max_size_ofdir = 0;
			head->c_next->dir = NULL;
			head->c_next->dir_data = NULL;
			head->c_next->c_name = mx_strdup("!!!");
		}
	}
}

void mx_del_node(t_main *info) {
	t_catalog *prev = info->cat;
	t_catalog *list = info->cat->c_next ? info->cat->c_next : NULL;

	if (!info->cat->is_dir) {
		info->cat = info->cat->c_next;
		prev = info->cat;
		list = prev->c_next;
	}
	for (; prev && prev->c_next; list = prev->c_next) {
			// printf("÷÷ |- %s %d\n", list->c_name, list->is_dir);
		if (!list->is_dir) {
			prev->c_next = list->c_next;
		}
		else
			prev = prev->c_next;
	}
}

DIR *mx_opendir_info(t_main *info, t_catalog *cat, char *link) {//-----------
	DIR *dir;

	errno = 0;
	// t_catalog *head = info->cat;
// printf("======%p====%s======\n", (void*)info->cat, info->cat->c_next->c_name);
	if ((dir = opendir(link)) == NULL) {
		char *temp = mx_strjoin(info->uls_name, link);

		if (errno != ENOTDIR)
			perror(temp);
		mx_strdel(&temp);
		free(cat->dir);
		cat->dir = NULL;
		cat->dir_data = NULL;
		cat->is_dir = false;
		if (errno == ENOTDIR) {
			// char *name = cat->c_name;  //!!!!!!!!!!!!!!!!!!!!!!
					// // printf("*/*/*/*/*/*/*%s\n", name);
					// if((void *)info->cat == (void *)cat) {
					// 	// printf("*/*/*/*/*/*/*");
					// 	info->cat = cat->c_next;
					// 	free(cat);
					// 	cat = NULL;
					// }
					// else {
					// 	t_catalog *head = info->cat;//!!!!!!!!!!!!!!!!!!!!!
					// 	for (; (void*)head->c_next != (void*)cat; head = head->c_next);
					// 		head->c_next = cat->c_next;
					// 		free(cat);
					// 		cat = NULL;
					// }
			// info->am_dir--;
			// printf("\t\t\t\t1)%s\n", cat->c_name);
			mx_make_extra_catalog(info, cat->c_name);
			// printf("\t\t\t\t2)%s\n\n", cat->c_name);
			// mx_strdel(&cat->c_name);
			// printf("/*/*%s %d*\\*\\\n", cat->c_name, cat->is_dir);
		}
		return dir;
	}
	else {
		return dir;
	}
}

// check if valid close
void mx_closedir_info(t_main *info, DIR *dir, char *link) {
	if (dir && closedir(dir) < 0) {
		char *temp = mx_strjoin(info->uls_name, link);

		errno = EBADF;
		perror(temp);
		exit(1);
	}
}

void mx_get_data_list(t_main *info, t_catalog *cat, char *link) {//-----------
	DIR *directoy = mx_opendir_info(info, cat, link);
	t_dir_data *list = cat->dir;
	struct dirent *temp = NULL;

	if (directoy && (temp = readdir(directoy))) {
		list->data = temp;
		list->name = mx_strdup(list->data->d_name);
		list->path = mx_get_full_path(link, list->name);
		if (info->flag.is_l == true)
			mx_ladd_to_tdir(list, cat, info->flag);
		list->next = NULL;
		cat->am_data++;
	}
	while (directoy && (temp = readdir(directoy))) {
		list->next = (t_dir_data *)malloc(sizeof(t_dir_data));
		list = list->next;
		list->data = temp;
		list->name = mx_strdup(temp->d_name);
		list->path = mx_get_full_path(link, list->name);
		if (info->flag.is_l == true)
			mx_ladd_to_tdir(list, cat, info->flag);
		list->next = NULL;
		cat->am_data++;
	}
	mx_closedir_info(info, directoy, link);
}

//=============================================================================

static int get_max_length(t_dir_data *dir) {
	int max = 0;
	t_dir_data *list = dir;

	while (list) {
		max = mx_strlen(list->name) >= max ? mx_strlen(list->name) : max;
		list = list->next;
	}
	return max;
}

void mx_count_line_for_print(t_main *info) {
	struct winsize w;
	int max_cols;
	int amount;
	t_dir_data *files;
	size_t width;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	width = !info->flag.is_tofile ? w.ws_col : MX_FILE_WS;
	for (t_catalog *head = info->cat; head; head = head->c_next) {				// проделываем для каждой дир, указан. в аргументах
		
		files = info->flag.is_a ? head->dir : head->dir_data;
		amount = info->flag.is_a ? head->am_data : head->am_files;

		head->lines_for_print = 0; 												// обнуляем количество линий для дир
		head->max_length = get_max_length(files);										// находим макимально возможную длину названия файла в дир
		max_cols = (width/(8 - (head->max_length % 8) + head->max_length));				// высчитываем количество колонок
		head->lines_for_print = amount / max_cols;		// высчитвыаем количество линий
		if(head->lines_for_print == 0 || (amount % max_cols) != 0)							// доп проверка на линии
			head->lines_for_print++;
	}
}

//=============================================================================

void mx_print_default(t_catalog *cat) {
	t_catalog *head = cat;
	t_dir_data *list = head->dir_data;

	for (; head; head = head->c_next) {
		list = head->dir_data;
		printf("%s:\n", head->c_name);
		while (list) {
			mx_printstr(list->name);
			mx_printstr("\t");
			list = list->next;
		}
	}
	mx_printchar('\n');
}

//=============================================================================
//================= Sort Part ======================

void mx_swap_cat(t_catalog *a, t_flag flag, t_catalog *b) {
	t_dir_data *tmp_data = a->dir;
	char *tmp_name = a->c_name;
	int tmp = a->am_files;
	bool tmp_is = a->is_dir;

	a->dir = b->dir;
	b->dir = tmp_data;
	tmp_data = a->dir_data;
	a->dir_data = b->dir_data;
	b->dir_data = tmp_data;
	a->c_name = b->c_name;
	b->c_name = tmp_name;
	a->am_files = b->am_files;
	b->am_files = tmp;
	tmp = a->am_data;
	a->am_data = b->am_data;
	b->am_data = tmp;
	a->is_dir = b->is_dir;
	b->is_dir = tmp_is;

	if (flag.is_l == true) {
		long long tmp = a->size_of_block;
		int temp = a->max_lnght_namedir;

		a->size_of_block = b->size_of_block;
		b->size_of_block = tmp;
		tmp = a->max_size_ofdir;
		a->max_size_ofdir = b->max_size_ofdir;
		b->max_size_ofdir = tmp;
		tmp = a->max_size_oflink;
		a->max_size_oflink = b->max_size_oflink;
		b->max_size_oflink = tmp;
		a->max_lnght_namedir = b->max_lnght_namedir;
		b->max_lnght_namedir = temp;
		tmp = a->max_lnght_grpdir;
		a->max_lnght_grpdir = b->max_lnght_grpdir;
		b->max_lnght_grpdir = tmp;
	}
}

void mx_sort_cat_list(t_catalog *start, t_flag flag) {
	int swapped = 1;
	t_catalog *ptr1;
	t_catalog *lptr = NULL;

	if (start == NULL)
		return;
	while (swapped) {
		swapped = 0;
		ptr1 = start;
		while (ptr1->c_next != lptr) {
			if (mx_strcmp(ptr1->c_name, ptr1->c_next->c_name) > 0) {
				mx_swap_cat(ptr1, flag, ptr1->c_next);
				swapped = 1;
			}
			ptr1 = ptr1->c_next;
		}
		lptr = ptr1;
	}
}

void mx_swap_dir(t_dir_data *a, t_dir_data *b) {
	// t_dir_data *temp = a;

	// a = b;
	// b = temp;

	struct dirent *tmp_data = a->data;
	char *tmp_name = a->name;
	struct stat *tmp_buff = a->buff_stat;
	int tmp_size_pwd = a->min_lnght_namedir;

	a->data = b->data;
	b->data = tmp_data;
	a->name = b->name;
	b->name = tmp_name;

	tmp_name = a->path;
	a->path = b->path;
	b->path = tmp_name;
	a->buff_stat = b->buff_stat;
	b->buff_stat = tmp_buff;
	a->min_lnght_namedir = b->min_lnght_namedir;
	b->min_lnght_namedir = tmp_size_pwd;
	tmp_size_pwd = a->min_lnght_grpdir;
	a->min_lnght_grpdir = b->min_lnght_grpdir;
	b->min_lnght_grpdir = tmp_size_pwd;
}

void mx_sort_dir_list(t_dir_data *start) {
	int swapped = 1;
	t_dir_data *ptr1;
	t_dir_data *lptr = NULL;

	if (start == NULL)
		return;
	while (swapped) {
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != lptr) {
			if (mx_strcmp(ptr1->name, ptr1->next->name) > 0) {
				mx_swap_dir(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}
//=============================================================================

static void print_tab(t_catalog *cat, t_dir_data *data) {
	int tab = cat->max_length / 8 + 1;
	int extra = mx_strlen(data->name) / 8;
	// printf("|%s   teb %d   extra %d %p|", data->name, tab, extra, (void*)data->next);

	for (int i = 0; i < (tab - extra); ++i)
		mx_printchar('\t');
}

void mx_print_cat(t_catalog *cat, bool flag_a) {
	t_dir_data *dir = flag_a ? cat->dir : cat->dir_data;
	t_dir_data *tmp = dir;
	t_dir_data *temp = NULL;

	for (int i = 0; i < cat->lines_for_print && dir; i++, dir = dir->next) {
		tmp = dir;
		while(tmp) {
			mx_printstr(tmp->name);
			temp = tmp;
			for (int j = 0; j < cat->lines_for_print && tmp; j++)
				tmp = tmp->next;
			if(tmp)
				print_tab(cat, temp);
		}
		mx_printchar('\n');
	}
}

void mx_print_1(t_catalog *cat, bool a) {
	for (t_dir_data *dir = a ? cat->dir : cat->dir_data; dir; dir = dir->next){
		mx_printstr(dir->name);
		mx_printchar('\n');
	}
}

void mx_print_to_file() {

}

void mx_print(t_main *info) {
	t_catalog *head = info->cat;

	for (; head; head = head->c_next) {
		if (info->am_dir != 1 && mx_strcmp(head->c_name, "!!!") != 0) {
			mx_printstr(head->c_name);
			mx_printstr(":\n");
		}
		if (info->flag.is_l == true) {
			if (head->size_of_block == 0 && info->flag.is_a == false
			&& head->am_data - head->am_files != 0)
				mx_print_totalsize(head);
			mx_print_lflag(head, info->flag);
		}
		else if (!info->flag.is_tofile) {
			info->flag.is_1 ? mx_print_1(head, info->flag.is_a)
			: mx_print_cat(head, info->flag.is_a);
		}
		else
			info->flag.is_C ? mx_print_cat(head, info->flag.is_a)
			: mx_print_1(head, info->flag.is_a);
		if (info->am_dir != 1 && head->c_next)
			mx_printchar('\n');
	}
}

void mx_get_dir_data_from_dir(t_catalog *head) {
	t_dir_data *data = head->dir;
	int i = 0;

	for(; data && *(data->name) == '.'; i++, data = data->next);
	if (mx_strcmp(head->c_name, "!!!") != 0 && head->dir->next->next) {
		head->dir_data = data;
		head->am_files = head->am_data - i;
	}
}

int main(int argc, char *argv[]) {
	t_main *info = (t_main*)malloc(sizeof(t_main));
	//*****************
	t_catalog *head = mx_main_parse_fnc(&argc, argv, info);
	//*****************
	info->flag.is_tofile = !isatty(1);
	//*****************

	for (int i = 1; head; i++, head = head->c_next) {
		if (argc > 1 && mx_strcmp(head->c_name, "!!!") != 0) {
			mx_get_data_list(info, head, head->c_name);
		}
		else if (argc == 1 && mx_strcmp(head->c_name, "!!!") != 0)
			mx_get_data_list(info, head, ".");
		if(head && head->dir) {
			// system("leaks -q uls");

		// printf("==========***=======\n");
			mx_sort_dir_list(head->dir);
			if (mx_strcmp(head->c_name, "!!!") != 0 && head->dir->next->next) {
				head->dir_data = head->dir->next->next;
				head->am_files = head->am_data - 2;
			}
			mx_get_dir_data_from_dir(head);
		}
	}
	// printf("**********************\n");
	mx_sort_cat_list(info->cat, info->flag);
	mx_del_node(info);

	// printf("/*%d %s*\\\n", info->cat->c_next->c_next->is_dir, info->cat->c_next->c_next->c_name);
	// printf("**********************\n");
	// printf("%s %s %p %d\n", info->cat->c_name, info->cat->c_next->c_name, (void*)info->cat->c_next->c_next, info->cat->am_files);
	mx_count_line_for_print(info);//*******************************************
	// printf("===============\n");
	// printf("%d\n", info->am_dir);
	mx_print(info);

	// mx_print_cat(info->cat);//-----------info----------------
	// mx_print_default(info->cat);
	
	// system("leaks -q uls");
	
	// system("ls");
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <time.h>
// #include <sys/stat.h>
// #include <string.h>
// #include <stdlib.h>
// int main() {
//     char *date;
//     int ret;
//     struct stat buf;
//     if ((ret = stat("Makefile", &buf))!=0) {
//         fprintf(stderr, "stat failure error .%d", ret);
//         abort();
//     }
//     date = asctime(localtime(&buf.st_ctime));
//     printf("\n %s\n", date);
//     printf("\n %d mode\n", buf.st_mode);
//     printf("\n %lld size\n", buf.st_size);
// }

///////////////////////////////////////////////////////////////////////////////

// #include <errno.h>
// #include <stdio.h>
// #include <string.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <time.h>
// #include <unistd.h>

// #define TIME_STRING_BUF 50

// /* Пользователь передает buf (минимальной длины TIME_STRING_BUF) вместо

//    использования статического для функции буфера, чтобы избежать применения

//    локальных статических переменных и динамической памяти. Никаких ошибок

//    происходить не должно, поэтому никакой проверки ошибок не делаем. */
// char *timeString (time_t t, char *buf) {
//     struct tm *local;
//     local = localtime(&t);
//     strftime(buf, TIME_STRING_BUF, "%c", local);
//     return buf;
// }


//  /* Отобразить всю информацию, полученную от lstat() по имени
//     файла как единственному параметру. */

// int statFile(const char *file) {
//     struct stat statbuf;
//     char timeBuf[TIME_STRING_BUF];

//     if (lstat(file, &statbuf)) {
//         fprintf(stderr, "не удалось lstat %s: %s ", file,
//         strerror(errno));
//         return 1;
//     }

//     printf("Имя файла : %s\n", file);
//     printf("На устройстве: старший %d младший %d Inode номер: %llu\n" , major(statbuf.st_dev), minor(statbuf.st_dev), statbuf.st_ino);
//     printf("Размер : %-101lld\nTип: %07o\nПрава доступа : %05o\n", statbuf.st_size, statbuf.st_mode & S_IFMT, statbuf.st_mode &~(S_IFMT));
//     printf("Владелец : %d Группа : %d\nКоличество ссылок : %d\n", statbuf.st_uid, statbuf.st_gid, statbuf.st_nlink);
//     printf("Время создания : %s\n", timeString(statbuf.st_ctime, timeBuf));
//     printf("Время модификации : %s\n", timeString(statbuf.st_mtime, timeBuf));
//     printf("Время доступа : %s\n", timeString (statbuf.st_atime, timeBuf));
//     return 0;
// }

// int main(int argc, const char **argv) {
//     int i;
//     int rc = 0 ;
// /* Вызвать statFile() для каждого имени файла,
// переданного в командной строке. */
//     for (i = 1; i < argc; i++) {
// /* Если statFile() сбоит, rc будет содержать не ноль.*/
//         rc |= statFile(argv[i]);
// /* это печатает пробел между позициями,
//    но не за последней */
//         if ((argc - i) > 1)
//             printf (" ");
//     }
//  return rc;
// }

///////////////////////////////////////////////////////////////////////////////

// int main(int argc, char *argv[])
// {
//     int a = 2;

//     // a <<= 2;

//     printf("%d\n", a|8);
//     return 0;
// }


//============Макросы типа===============
/*
* #define MX_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
* #define MX_ISCHR(mode) (((mode) & S_IFMT) == S_IFCHR)
* #define MX_ISBLK(mode) (((mode) & S_IFMT) == S_IFBLK)
* #define MX_ISFIFO(mode) (((mode) & S_IFMT) == S_IFFIFO)
* #define MX_ISLNK(mode) (((mode) & S_IFMT) == S_IFLNK)
* #define MX_ISSOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)
**/
