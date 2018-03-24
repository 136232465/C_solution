//find the common numbers between two sortted arrays a[N],b[M];

class Solution{
public:
	vector<int> findcommon(vector<int> a,vector<int> b){
		for (int i = 0; i < a.size(); ++i){
			int e = binarysearch(b,a[i])
			if(e != -1){
				res.push_back(e);
			}
		}
	}
private:
	int help binarysearch(vector<int> a,int i){
		if (a == NULL){
			return -1;
		}
		int m = a.size()/2;
		if(i < a[m]){
			 return binarysearch(vector<int>(a.begin(),a.begin()+m),i);
		}
		else if (i > a[m]){
			return binarysearch(vector<int>(a.begin()+m,a.end()),i)
		} else {
			return a[m];
		}
	}
	
}

//上面是for a{
	binarysearch b
}

方法二：
int i=0 ，j=0
while(i<a.size()&& j < b.size())
(a[i] < a[j])？++i:++j;

方法三；
unordered_set hashset;
for (auto i : b){
	hashset.insert(i)
}
for (auto j : a){
	hashset.find(j)
}




