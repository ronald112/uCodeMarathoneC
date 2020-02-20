#include "header.h"
void mx_errcheck(char *filename, char *x1, char *y1, char *x2, char *y2, int argc) {
    if (argc != 6) {
        write(2, USAGE_MSG, mx_strlen(USAGE_MSG));
        exit(EXIT_FAILURE);
    }
    int map_descriptor = open(filename, O_RDONLY);
  
    if (map_descriptor < 0) {
         write(2, MAP_NEXIST, mx_strlen(MAP_NEXIST));
         close(map_descriptor);
         exit(EXIT_FAILURE);
    }
    map_descriptor = open(filename, O_RDONLY);
    char buf = '\0';
    while (read(map_descriptor, &buf, 1)) {
        if (!mx_valid_char(buf)) {
           write(2, MAP_ERROR, mx_strlen(MAP_ERROR));
           close(map_descriptor);
           exit(EXIT_FAILURE);
        }
    }
    char *map = mx_file_to_str(filename);
    for (int i = 0; i < mx_strlen(map); i++) {
        if (map[i] == '#' && map[i + 1] != ',') {
            if (map[i] == '#' && map[i + 1] != '\n') {
                if (map[i] != '\0') {
                    write(2, MAP_ERROR, mx_strlen(MAP_ERROR));
                    exit(EXIT_FAILURE);
                }
            }
        }
        if (map[i] == ',' && map[i + 1] != '.') {
            if (map[i] == ',' && map[i + 1] != '#') {
                write(2, MAP_ERROR, mx_strlen(MAP_ERROR));
                exit(EXIT_FAILURE);
            }
        }
        if (map[i] == '.' && map[i + 1] != ',') {
            if (map[i] == '.' && map[i + 1] != '\n') {
                write(2, MAP_ERROR, mx_strlen(MAP_ERROR));
                exit(EXIT_FAILURE);
            }
        }
    }
    int ix1 = mx_atoi(x1);
    int iy1 = mx_atoi(y1);
    int ix2 = mx_atoi(x2);
    int iy2 = mx_atoi(y2);
    close(map_descriptor);
    int line = 0;
    int height = 0;
    int length = 0;
    int flag = 1;
    int chars = 0;
    map_descriptor = open(filename, O_RDONLY);
    while (read(map_descriptor, &buf, 1)) {
        chars++;
        if (buf == '\n') {
            flag = 0;
            height++;
            if (line != length) {
                write(2, MAP_ERROR, mx_strlen(MAP_ERROR));
                exit(EXIT_FAILURE);
            }  
            line = 0;
        }
        if (flag && buf != '\n') {
            length++;
        }
        if (buf != '\n')
            line++;
    }
    close(map_descriptor);
    map_descriptor = open(filename, O_RDONLY);

    char *result = malloc((1 + ((length / 2) * height)) * sizeof(char));
    int k = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            read(map_descriptor, &buf, 1);
            if (buf == '#' || buf == '.') {
                result[k] = buf;
                k++;
            }
        }
    }
    if (chars == 0) {
        write(2, MAP_ERROR, mx_strlen(MAP_ERROR));
        exit(EXIT_FAILURE);
    }
    if (close(map_descriptor) < 0) {
        write(2, ERR, mx_strlen(ERR));
        exit(EXIT_FAILURE);
    }
    close(map_descriptor);
    if (ix1 < 0 || iy1 < 0 || ix1 < 0 || iy2 < 0) {
        write(2, OUT_OF_RANGE, mx_strlen(OUT_OF_RANGE));
        close(map_descriptor);
        exit(EXIT_FAILURE);
    }
    else if (ix1 > length / 2 || iy1 > length / 2  || ix1 > length / 2  || iy2 > length / 2) {
        write(2, OUT_OF_RANGE, mx_strlen(OUT_OF_RANGE));
        close(map_descriptor);
        exit(EXIT_FAILURE);
    } 
    else if (ix1 > height || iy1 > height || ix1 > height || iy2 > height) {
        write(2, OUT_OF_RANGE, mx_strlen(OUT_OF_RANGE));
        close(map_descriptor);
        exit(EXIT_FAILURE);
    }
    if (!mx_isdigit(*x1) || !mx_isdigit(*x2) || !mx_isdigit(*y1) || !mx_isdigit(*y2)) {
         write(2, ERR, mx_strlen(ERR));
         close(map_descriptor);
         exit(EXIT_FAILURE);
    }
    if (result[ix1 + iy1 * (length / 2) + iy1] == '#') {
        write(2, ENTRY_IS_OBSTACLE, mx_strlen(ENTRY_IS_OBSTACLE));
        close(map_descriptor);
        exit(EXIT_FAILURE);
    }
    if (result[ix2  + iy2 * (length / 2) + iy2] == '#') {
        write(2, EXIT_IS_OBSTACLE, mx_strlen(EXIT_IS_OBSTACLE));
        close(map_descriptor);
        exit(EXIT_FAILURE);
    }


    free(result);
    free(map);



}
