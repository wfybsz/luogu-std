//It will return (a ^ b) mod c

long long fp(int a,int b,int m){
	int t = 1;
	while(b){
		if(b & 1)
			t = t * a % m;
		b >>= 1;
		a = a * a % m;
	}
	return t;
}
