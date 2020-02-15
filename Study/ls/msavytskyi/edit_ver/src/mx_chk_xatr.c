#include "uls.h"

void mx_add_xatr(char *path, char **result) {
    ssize_t xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
    acl_t acl = acl_get_file(path, ACL_TYPE_EXTENDED);

    if (xattr < 0)
        *result = mx_addstr(*result, "+");
    else if (xattr > 0)
        *result = mx_addstr(*result, "@");
    else if (acl != NULL)
        *result = mx_addstr(*result, "+");
    else
        *result = mx_addstr(*result, " ");
    acl_free(acl);
    acl = NULL;
}
