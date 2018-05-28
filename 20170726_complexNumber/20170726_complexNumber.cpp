#include <iostream>
#include <iomanip>
using namespace std;

class complex_number{
	private:
		double re;
		double im;
	public:
		complex_number(){
			re=0;
			im=0;
		}
		complex_number(double real,double image){
			re=real;
			im=image;
		}
		complex_number operator+(const complex_number c){
			return complex_number(re+c.re,im+c.im);
		}
		complex_number operator-(const complex_number c){
			return complex_number(re-c.re,im-c.im);
		}
		complex_number operator*(const complex_number c){
			return complex_number(re*c.re-im*c.im,im*c.re+re*c.im);
		}
		complex_number operator/(const complex_number c){
			return complex_number((re*c.re+im*c.im)/(c.re*c.re+c.im*c.im),
				(im*c.re-re*c.im)/(c.re*c.re+c.im*c.im));
		}
		void print_num(){
			if(int((re+0.04)*10)!=0){
				 cout<<setprecision(1)<<re;
				 if(int((im+0.04)*10)>0){
				 	cout<<"+";
				 }
			}		
			if(int((im+0.04)*10)!=0){
				 cout<<setprecision(1)<<im<<"i";
			}
			if(int((re+0.04)*10)==0&&int((im+0.04)*10)==0){
				cout<<"0.0";
			}
		}
};

int main(){
	double a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	complex_number c1(a1,b1),c2(a2,b2);
	cout.setf(ios::fixed);
	
	cout<<"(";
	c1.print_num();
	cout<<") + (";
	c2.print_num();
	cout<<") = ";
	(c1+c2).print_num();
	cout<<endl;
	
	cout<<"(";
	c1.print_num();
	cout<<") - (";
	c2.print_num();
	cout<<") = ";
	(c1-c2).print_num();
	cout<<endl;
	
	cout<<"(";
	c1.print_num();
	cout<<") * (";
	c2.print_num();
	cout<<") = ";
	(c1*c2).print_num();
	cout<<endl;
	
	cout<<"(";
	c1.print_num();
	cout<<") / (";
	c2.print_num();
	cout<<") = ";
	(c1/c2).print_num();
}
