#include<cstdio>
#include<cmath>
const int maxn=11;
int count=0;
int n,hashTable[maxn]={false},P[maxn];
void generateP(int index){
	if(index==n+1){			//递归边界，如果能到这一步说明前面都成功了 
		count++;
		for(int i=0;i<index;i++){
			printf("%d",P[i]);
		}
		printf("\n");
		return;
	}
	for(int x=1;x<=n;x++){	//从第1到第n行逐行遍历 
		if(hashTable[x]==false){	//如果第x行还没有皇后
			bool flag=true; 	//flag为true表示当前的皇后不会和之前的皇后冲突
			for(int pre=1;pre<index;pre++){	//遍历之前的皇后 
			//第index列皇后的行号为x，第pre列皇后的行号为P[pre]
				if(abs(index-pre)==abs(x-P[pre])){
					flag=false;	//与之前的皇后在一条对角线，冲突
					break; 
				} 
			} 
		if(flag){	//如果可以把皇后放在第x行 
			P[index]=x;	//令第index列皇后的行号为x 
			hashTable[x]=true;	//第x行已被占用 
			generateP(index+1);	//递归处理第index+1行皇后 
			hashTable[x]=false; //递归完毕，还原第x行为未占用		 
			}
		} 
	}
}

int main(){
	n=5;
	generateP(1);
	printf("count=%d",count);
	return 0;
}
