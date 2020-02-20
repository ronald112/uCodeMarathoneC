#include "uls.h"

char *mx_default(char *directory, int amount) {
	DIR *direct = opendir(directory);
	struct dirent *dir_read = NULL;
	char *flag_1 = NULL;

	if (amount > 0) {
		flag_1 = mx_strjoin(flag_1, directory);
		flag_1 = mx_strjoin(flag_1, ":\n");
	}
	while ((dir_read = readdir(direct)) != NULL) {
		if(mx_strcmp(dir_read->d_name, ".")
			&& mx_strcmp(dir_read->d_name, "..")){
			flag_1 = mx_strjoin(flag_1, dir_read->d_name);
			flag_1 = mx_strjoin(flag_1, "\t");
		}
	}
	closedir(direct);
	return flag_1;
}



// int main(int argc, char *argv[]) {
// 	char *res = NULL;

// 	if(argc == 1) {
// 		perror("usage: uls [-l] [file ...]\n");
// 		exit(0);
// 	}
// 	if (mx_strcmp(argv[1], "-1") == 0)
// 		res = mx_flag_1();
// 	printf("%s\n", res);
// 	return 0;
// }

// int main(int argc, char *argv[]) {
// 	char *data = NULL;

// 	if (argc == 1)
// 		data = mx_default(".", 0);
// 	else if (argc == 2)
// 		data = mx_default(argv[1], 0);
// 	else {
// 		for (int i = 1; argv[i]; i++) {
// 			data = mx_strjoin(data, mx_default(argv[i], argc - 1));
// 			data = mx_strjoin(data, "\n");
// 		}
// 	}
// 	printf("%s\n", data);
// 	return 0;
// }
