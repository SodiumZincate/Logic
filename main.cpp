#include "circuit.h"

int main(int argc, char* argv[])
{
	if(argc != 2){
		std::cout << "To execute: ./main <Number of Bits(1-8)>\nExample: ./main 2" << std::endl;
		std::exit(1);
	}

	int no_of_bits = std::stoi(argv[1]);

	int rows = (int)pow(2,no_of_bits);
	int cols = no_of_bits;

	State input[rows][cols];
	State input_temp[cols][rows];

	int i,j,k;

	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			input[i][j] = State::Low;
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

	State is_one = High;
	for(i=0; i<cols; i++){
		int c = 0;
		static int counter = (int)pow(2, cols-1);
		for(j=0; j<rows; j++){
			if(c % counter == 0 && is_one == High){
				is_one = Low;
			}
			else if(c % counter == 0 && is_one == Low){
				is_one = High;
			}
			if(is_one){
				input_temp[i][j] = State::High;
			}
			else{
				input_temp[i][j] = State::Low;
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
		State carry_in = State::High;
		State sum, carry_out;
		sum = XOR(XOR(a,b), carry_in);
		carry_out = OR(AND(XOR(a,b), carry_in), AND(a,b));
		std::cout << "Sum: " << sum << std::endl;
		std::cout << "Carry Out: " << carry_out << std::endl;
	}

	return 0;
}