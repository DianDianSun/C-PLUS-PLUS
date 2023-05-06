#include <iostream>
using namespace std;
class Point{
private:
	int x;
	int y;
public:
	void setXY(int X,int Y){
		x = X;
		y = Y;
	}
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
};
class Circle{
private:
	int x;
	int y;
	int r;
public:
	void setXYR(int X,int Y,int R){
		x = X;
		y = Y;
		r = R;
	}
	void JudgePointIfInCircle(Point point){
		int tmp1 = point.getX()*point.getX()+point.getY()*point.getX();
		int tmp2 = tmp1-x*x + y*y;
		if(tmp2>0){
			cout<<"圆上"<<endl;
		}
	}
};
int main() {
	
	
	return 0;
}