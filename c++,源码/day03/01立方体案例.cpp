#include <iostream>
using namespace std;

class Cube{
private:
	int ml;
	int mw;
	int mh;
public:
	//初始化变量
	void init(){
		ml = 0;
		mw = 0;
		mh = 0;
	}
	
	//set
	void setl(int l){
		ml = l;
	}
	void setw(int w){
		mw = w;
	}
	void seth(int h){
		mh = h;
	}
	//get
	int getl(){
		return ml;
	}
	int getw(){
		return mw;
	}
	int geth(){
		return mh;
	}
	
	int caculateS(){
		return (2*mh*ml+2*mh*mw+2*mw*ml);
	}
	int caculateV(){
		return mh*ml*mw;
	}
	bool CompareCube(Cube &cube){
		if(getl() == cube.getl()&& getw() == cube.getw() && geth() == cube.geth()){
			return true;
		}else{
			return false;
		}
	}
};
int main() {
	
	Cube c1,c2;
	c1.seth(20);
	c1.setl(10);
	c1.setw(20);
	c2.seth(20);
	c2.setl(20);
	c2.setw(20);
	cout << (bool)c1.CompareCube(c2)<<endl;
	
	return 0;
}