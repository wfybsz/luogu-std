void print(int x){
	if(x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}
