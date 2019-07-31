string add(string a,string b){
	string ans;
	int na[L] = {0},nb[L] = {0};
	int la = a.size(),lb = b.size();
	for(int i = 0;i < la;i++)
		na[la - 1 - i] = a[i] - '0';
	for(int i = 0;i < lb;i++)
		nb[lb - 1 - i] = b[i] - '0';
	int lmax = la > lb?la:lb;
	for(int i = 0;i < lmax;i++)
		na[i] += nb[i],na[i + 1] += na[i] / 10,na[i] %= 10;
	if(na[lmax])
		lmax++;
	for(int i = lmax - 1;i >= 0;i--)
		ans += na[i] + '0';
	return ans;
}

string sub(string a,string b){
	string ans;
	int na[L] = {0},nb[L] = {0};
	int la = a.size(),lb = b.size();
	for(int i = 0;i < la;i++)
		na[la - 1 - i] = a[i] - '0';
	for(int i = 0;i < lb;i++)
		nb[lb - 1 - i] = b[i] - '0';
	int lmax = la > lb?la:lb;
	for(int i = 0;i < lmax;i++){
		na[i] -= nb[i];
		if(na[i] < 0)
			na[i] += 10,na[i + 1]--;
	}
	while(!na[--lmax] && lmax > 0);
	lmax++;
	for(int i = lmax - 1;i >= 0;i--)
		ans += na[i] + '0';
	return ans;
}

string mul(string a,string b){
	string s;
	int na[L];
	int nb[L];
	int nc[L];
	int La = a.size();
	int Lb = b.size();
	fill(na,na + L,0);
	fill(nb,nb + L,0);
	fill(nc,nc + L,0);
	for(int i = La - 1;i >= 0;i--)
		na[La - i] = a[i] - '0';
	for(int i = Lb - 1;i >= 0;i--)
		nb[Lb - i] = b[i] - '0';
	for(int i = 1;i <= La;i++)
		for(int j = 1;j <= Lb;j++)
			nc[i + j - 1] += na[i] * nb[j];
	for(int i = 1;i <= La + Lb;i++){
		nc[i + 1] += nc[i] / 10;
		nc[i] %= 10;
	}
	if(nc[La + Lb]) 
		s += nc[La + Lb] + '0';
	for(int i = La + Lb - 1;i >= 1;i--)
		s += nc[i] + '0';
	return s;
}

string Mul(string a,int b){
	string ans;
	int La = a.size();
	fill(na,na + L,0);
	for(int i = La - 1;i >= 0;i--)
		na[La - i - 1] = a[i] - '0';
	int w = 0;
	for(int i = 0;i < La;i++){
		na[i] = na[i] * b + w;
		w = na[i] / 10;
		na[i] = na[i] % 10;
	}
	while(w){
		na[La++] = w % 10;
		w /= 10;
	}
	La--;
	while(La >= 0) 
		ans += na[La--] + '0';
	return ans;
}

int sub(int *a,int *b,int La,int Lb){
	if(La < Lb)
		return -1;
	if(La == Lb)
		for(int i = La - 1;i >= 0;i--)
			if(a[i] > b[i])
				break;
			else if(a[i] < b[i])
				return -1;
	for(int i = 0;i < La;i++){
		a[i] -= b[i];
		if(a[i] < 0){
			a[i] += 10;
			a[i + 1]--;
		}
	}
	for(int i = La - 1;i >= 0;i--)
		if(a[i])
			return i + 1;
	return 0;
}

string div(string n1,string n2,int nn){
	string s,v;
	int a[L],b[L],r[L];
	int La = n1.size(),Lb = n2.size();
	int i,tp = La;
	fill(a,a + L,0);
	fill(b,b + L,0);
	fill(r,r + L,0);
	for(int i = La - 1;i >= 0;i--)
		a[La - i - 1] = n1[i] - '0';
	for(int i = Lb - 1;i >= 0;i--)
		b[Lb - i - 1] = n2[i] - '0';
	if(La < Lb ||(La == Lb && n1 < n2))
		return n1;
	int t = La - Lb;
	for(int i = La - 1;i >= 0;i--)
		if(i >= t)
			b[i] = b[i - t];
		else
			b[i] = 0;
	Lb = La;
	for(int j = 0;j <= t;j++){
		int temp;
		while((temp = sub(a,b + j,La,Lb - j)) >= 0){
			La = temp;
			r[t - j]++;
		}
	}
	for(int i = 0;i < L - 10;i++){
		r[i + 1] += r[i] / 10;
		r[i] %= 10;
	}
	while(!r[i])
		i--;
	while(i >= 0)
		s += r[i--] + '0';
	i = tp;
	while(!a[i])
		i--;
	while(i >= 0)
		v += a[i--] + '0';
	if(v.empty())
		v = "0";
	if(nn == 1)
		return s;
	if(nn == 2)
		return v;
}
