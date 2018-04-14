#define BITWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int a[1 + N/BITWORD];
void set(int i )
{
	a[i>>SHIFT] |= (1 << (i & MASK));
}

void clr(int i)
{
	a[i>>SHIFT] &= ~(1 << (i & MASK));
}

int test001(int i)
{
	return a[i>>SHIFT] & (1 << (i & MASK));
}