inline void read(int &x){
	x = 0;
	char c = getchar();
	while('0' > c || c > '9')
		c = getchar();
	while('0' <= c && c <= '9'){
		x = (x << 3) + (x << 1) + (c ^ 48);
		x = getchar();
	}
}
