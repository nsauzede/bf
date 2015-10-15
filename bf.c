#include <stdio.h>
#include <string.h>

#define GETOP() *pc++

int main()
{
//	printf( "hello brainfuck\n");
#if 0
#define PSIZE 200
	char prog[PSIZE], *pc = prog, c;
	memset( prog, EOF, sizeof( prog));
	fgets( prog, sizeof( prog) - 1, stdin);
#else
//#define PROG ""
//#define PROG ",."
#define PROG "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."
	char prog[] = PROG "\xff", *pc = prog, c;
#endif
#define SIZE 32768
	int buf[SIZE], *ptr = buf;
	memset( buf, 0, sizeof( buf));
	int end = 0;
	while (!end)
	{
		c = GETOP();
		if (c == EOF)
		{
			end = 1;
			break;
		}
		printf("read '%c' ptr=%p buf=", c, ptr);
		int i;
		for (i = 0; i < 4; i++)
		{
			printf( "%d ", buf[i]);
		}
		printf( "\n");
		switch (c)
		{
			case '>':
				++ptr;
				break;
			case '<':
				--ptr;
				break;
			case '+':
				++*ptr;
				break;
			case '-':
				--*ptr;
				break;
			case '.':
//				printf( "put\n");
				putchar( *ptr);
				break;
			case ',':
//				printf( "get\n");
				*ptr = getchar();
				break;
			case '[':
				if (!*ptr)
				{
					char c2;
					while (1)
					{
						c2 = GETOP();
						if (c2 == EOF)
						{
							end = 1;
							break;
						}
						if (c2 == ']')
							break;
					}
				}
				break;
			case ']':
				break;
			default:
				break;
		}
	}
	return 0;
}
