#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
namespace trie{
	template<classT,size_t CHILD_MAX>
	struct nod{
		Treserved;
		nod<T,CHILD_MAX>*child[CHILD_MAX];
		nod(){
			memset(this,0,sizeof*this);
		}
		~nod(){
			for(unsignedi=0; i<CHILD_MAX; i++)
				deletechild[i];
		}
		void Traversal(char*str,unsignedindex){
			unsignedi;
			for(i=0; i<index; i++)
				cout<<str[i];
			cout<<'\t'<<reserved<<endl;
			for(i=0; i<CHILD_MAX; i++){
				if(child[i]){
					str[index]=i;
					child[i]->Traversal(str,index+1);
				}
			}
			return;
		}
	};
	template<classT,size_t CHILD_MAX=127>
	classtrie{
private:
		nod<T,CHILD_MAX>root;
public:
		nod<T,CHILD_MAX>*AddStr(char*str);
		nod<T,CHILD_MAX>*FindStr(char*str);
		boolDeleteStr(char*str);
		void Traversal()
		{
			char str[100];
			root.Traversal(str,0);
		}
	};
	template<classT,size_tCHILD_MAX>
	nod<T,CHILD_MAX>*trie<T,CHILD_MAX>::AddStr(char*str)
	{
		nod<T,CHILD_MAX>*now=&root;
		do
		{
			if(now->child[*str]==NULL)
				now->child[*str]=newnod<T,CHILD_MAX>;
			now=now->child[*str];
		}
		while(*(++str)!='\0');
		return now;
	}
	template<classT,size_tCHILD_MAX>
	nod<T,CHILD_MAX>*trie<T,CHILD_MAX>::FindStr(char*str)
	{
		nod<T,CHILD_MAX>*now=&root;
		do
		{
			if(now->child[*str]==NULL)
				return NULL;
			now=now->child[*str];
		}
		while(*(++str)!='\0');
		returnnow;
	}
	template<classT,size_tCHILD_MAX>
	bool trie<T,CHILD_MAX>::DeleteStr(char*str){
		nod<T,CHILD_MAX>**nods=new nod<T,CHILD_MAX>*[strlen(str)];
		intsnods=1;
		nod<T,CHILD_MAX>*now=&root;
		nods[0]=&root;
		do{
			if(now->child[*str]==NULL)
				returnfalse;
			nods[snods++]=now=now->child[*str];
		}while(*(++str)!='\0');
		snods--;
		while(snods>0){
			for(unsigned i=0; i<CHILD_MAX; i++)
				if(nods[snods]->child[i]!=NULL)
					return true;
			delete nods[snods];
			nods[--snods]->child[*(--str)]=NULL;
		}
		return true;
	}
}
