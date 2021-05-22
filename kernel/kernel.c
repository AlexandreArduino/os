extern printc;
void _start()
{
    char *ptr = 0xB8000;
    *ptr = 'O';
    while(1);
}