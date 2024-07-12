#include<iostream>
#include<vector>
#include<cmath>
// #include<string>

class Logic{
	public:
		int state;
		int operator*(Logic x){
			return state && x.state;
		}
		int operator+(Logic x){
			return state || x.state;
		}
		int operator+(int x){
			return state || x;
		}
		friend int operator+(Logic x);
		Logic(int x){
			state = x;
		}
		Logic(){
			state = 0;
		}
		void init(int x){
			state = x;
		}
};

int operator+(int x, Logic y){
	return x || y.state;
}

int main(int argc, char* argv[])
{
	// int i =cols;
	int no_of_bits = std::stoi(argv[1]);

	int rows = (int)pow(2,no_of_bits);
	int cols = no_of_bits;

	int input[rows][cols];
	int input_temp[cols][rows];

	int i,j,k;

	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			input[i][j] = 0;
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
				input_temp[i][j] = 1;
			}
			else{
				input_temp[i][j] = 0;
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

	Logic a,b,c;
	for(i=0; i<rows; i++){
		a.init(input[i][0]);
		b.init(input[i][1]);
		c.init(input[i][2]);
		std::cout << a+b+c << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
