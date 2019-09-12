#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
	int val;
	vector<int>chlidren;
	Node(int v):val(v) {}
};

class UnSet
{
public:
	int *father;
	UnSet(int n): capacity(n){
		father = new int[n];
		for (int i = 0;i < n ;i++)
			father[i] = i;
	}
	~UnSet(){
		delete[] father;
	}
	int find(int i){
		return (father[i] == i) ? i : (father[i] = find(father[i]));
	}
	void unionSet(int a,int b){
		a = find(a);
		b = find(b);
		father[b] = a;
	}
	int size(){
		return capacity;
	}
private:
	int capacity;
};

class LCA{
public:
	LCA(Node tree[],int n): fatSet(n){
		hasVisit = new bool[n];
		memset(hasVisit,false,n * sizeof(bool));
		this->tree = tree;
	}
	map<pair<int,int>,int>calLCA(vector<pair<int,int> >& query){
		map<int,set<int> >queryMap;
		map<pair<int,int>,int>result;
		for (int i =0;i< query.size();i++){
			int u = query[i].first;
			int v = query[i].second;
			set<int>temp;
			if (queryMap.count(u) == 0)
				queryMap[u] = temp;
			if (queryMap.count(v) == 0)
				queryMap[v] = temp;
			queryMap[u].insert(v);
			queryMap[v].insert(u);
		}
		tarjan(0,queryMap,result);
		return result;
	}
	void tarjan(int u,map<int,set<int> >& queryMap,map<pair<int,int>,int>& result){
		fatSet.father[u] = u;
		hasVisit[u] = true;
		cout<<"Visit "<<u<<endl;
		for (set<int>::iterator it = queryMap[u].begin();it != queryMap[u].end();it++){
			int v = *it;
			if (hasVisit[*it]){
				pair<int,int>temp(v,u);
				result[temp] = fatSet.find(v);
			}
		}
		for (int i = 0;i < tree[u].chlidren.size();i++){
			int v = tree[u].chlidren[i];
			if (false == hasVisit[v]){
				tarjan(v,queryMap,result);
				fatSet.unionSet(u,v);
			}
		}
	}
private:
	bool *hasVisit;
	UnSet fatSet;
	Node *tree;
};

int main()
{
	Node testTree[5] = {0,0,0,0,0};
	testTree[0].chlidren.push_back(1); 
	testTree[0].chlidren.push_back(2); 
	testTree[1].chlidren.push_back(3); 
	testTree[1].chlidren.push_back(4); 
	vector<pair<int,int> >query;
	pair<int,int>a(2,3),b(3,4),c(4,1);
	query.push_back(a);
	query.push_back(b);
	query.push_back(c);
	LCA l(testTree,5);
	map<pair<int,int>,int>ret = l.calLCA(query);
	cout<<"Result: ";
	for (map<pair<int,int>,int>::iterator it = ret.begin();it != ret.end();it++)
		cout<<it->first.first<<","<<it->first.second<<"->"<<it->second<<"\t";  
	putchar('\n');
	return 0;
}
