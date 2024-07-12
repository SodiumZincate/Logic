#include<iostream>
#include<vector>
#include<cmath>
// #include<string>

enum Bool{
	False = 0,
	True = 1
};

class Logic{
	public:
		Bool state;
		Bool operator*(Logic x){
			return static_cast<Bool>(static_cast<int>(state) && static_cast<int>(x.state));
		}
		Bool operator*(Bool x){
			return static_cast<Bool>(static_cast<int>(state) && static_cast<int>(x));
		}
		friend Bool operator*(Logic x);

		Bool operator+(Logic x){
			return static_cast<Bool>(static_cast<int>(state) || static_cast<int>(x.state));
		}
		Bool operator+(Bool x){
			return static_cast<Bool>(static_cast<int>(state) || static_cast<int>(x));
		}
		friend Bool operator+(Bool, Logic);
		friend Bool operator+(Bool, Bool);

		Bool operator!(){
			return static_cast<Bool>(!static_cast<int>(state));
		}

		Logic(Bool x){
			state = x;
		}
		Logic(){
			state = Bool::False;
		}
		void init(Bool x){
			state = x;
		}
};

Bool operator+(Bool x, Logic y){
	return static_cast<Bool>(static_cast<int>(x) || static_cast<int>(y.state));
}
Bool operator+(Bool x, Bool y){
	return static_cast<Bool>(static_cast<int>(x) || static_cast<int>(y));
}
Bool operator*(Bool x, Logic y){
	return static_cast<Bool>(static_cast<int>(x) && static_cast<int>(y.state));
}

int main(int argc, char* argv[])
{
	// int i =cols;
	int no_of_bits = std::stoi(argv[1]);

	int rows = (int)pow(2,no_of_bits);
	int cols = no_of_bits;

	Bool input[rows][cols];
	Bool input_temp[cols][rows];

	int i,j,k;

	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			input[i][j] = Bool::False;
		}
	}

	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			std:: cout << "input[" << i << "][" << j << "]: " << input[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for(i=0; i<cols; i++){
		for(j=0; j<rows; j++){
			input_temp[i][j] = input[j][i];
		}
	}

	for(i=0; i<cols; i++){
		for(j=0; j<rows; j++){
			std:: cout << "input[" << i << "][" << j << "]: " << input_temp[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	bool is_one = true;
	for(i=0; i<cols; i++){
		int c = 0;
		static int counter = (int)pow(2, cols-1);
		for(j=0; j<rows; j++){
			if(c % counter == 0 && is_one == true){
				is_one = false;
			}
			else if(c % counter == 0 && is_one == false){
				is_one = true;
			}
			if(is_one){
				input_temp[i][j] = Bool::True;
			}
			else{
				input_temp[i][j] = Bool::False;
			}
			c++;
		}
		counter/=2;
	}

	for(i=0; i<cols; i++){
		for(j=0; j<rows; j++){
			std:: cout << "input[" << i << "][" << j << "]: " << input_temp[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			input[i][j] = input_temp[j][i];
		}
	}

	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			std:: cout << "input[" << i << "][" << j << "]: " << input[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	Logic a,b,c,d,e,f,g,h;
	for(i=0; i<rows; i++){
		a.init(input[i][0]);
		b.init(input[i][1]);
		c.init(input[i][2]);
		d.init(input[i][3]);
		e.init(input[i][4]);
		f.init(input[i][5]);
		g.init(input[i][6]);
		h.init(input[i][7]);
		// std::cout << (a*b)+(a+b) << std::endl;
		std::cout << (a*b)+(a+b) << std::endl;
	}

	return 0;
}
