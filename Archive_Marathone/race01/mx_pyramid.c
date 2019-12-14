void mx_printchar(char c);

void print_line(int l, char *a)
{
    for(int i = 0; i < l; i++)
    {
        mx_printchar(*a);
    }
}
void mx_pyramid(int n)
{
    char space = ' ';
    char line = '_';
    char slash = '/';
    char stick = '|';
    char bslash = '\\';
    int b = -1;
    int c = 0;
    if(n % 2 == 0 && n > 1)
    {
        if(n>=2){
            print_line((n*2)/2 -1 , &space);
            mx_printchar(slash);
            mx_printchar(bslash);
            mx_printchar('\n');
            for(int i = (n*2)/2 - 2; i > 0; i--)
            {
                print_line(i, &space);
                mx_printchar(slash);
                print_line(b += 2, &space);
                mx_printchar(bslash);
                if (i >= n/2  )
                {
                    print_line(++c, &space);
                    mx_printchar(bslash);
                    mx_printchar('\n');
                }
                else 
                {
                    print_line(c--, &space);
                    mx_printchar(stick);
                    mx_printchar('\n');
                }
            }
            mx_printchar(slash);
            print_line(2*n - 3, &line);
            mx_printchar(bslash);
            mx_printchar(stick);
            mx_printchar('\n');
        }
    }
}
