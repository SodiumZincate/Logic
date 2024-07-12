#include<iostream>
#include<vector>
#include<cmath>
// #include<string>

enum State{
	Low = 0,
	High = 1
};

class Logic{
	private:
		State state;
	public:
		State operator*(Logic x){
			return static_cast<State>(static_cast<int>(state) && static_cast<int>(x.state));
		}
		State operator*(State x){
			return static_cast<State>(static_cast<int>(state) && static_cast<int>(x));
		}
		friend State operator*(State x, Logic y);

		State operator+(Logic x){
			return static_cast<State>(static_cast<int>(state) || static_cast<int>(x.state));
		}
		State operator+(State x){
			return static_cast<State>(static_cast<int>(state) || static_cast<int>(x));
		}
		friend State operator+(State, Logic);
		friend State operator+(State, State);

		State operator!(){
			return static_cast<State>(!static_cast<int>(state));
		}

		Logic(State x){
			state = x;
		}
		Logic(){
			state = State::Low;
		}
		void init(State x){
			state = x;
		}
};

State operator+(State x, Logic y){
	return static_cast<State>(static_cast<int>(x) || static_cast<int>(y.state));
}
State operator+(State x, State y){
	return static_cast<State>(static_cast<int>(x) || static_cast<int>(y));
}
State operator*(State x, Logic y){
	return static_cast<State>(static_cast<int>(x) && static_cast<int>(y.state));
}
State operator*(State x, State y){
	return static_cast<State>(static_cast<int>(x) && static_cast<int>(y));
}

int main(int argc, char* argv[])
{
	// int i =cols;
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
		// std::cout << (a*b)+(a+b) << std::endl;
		std::cout << !((a*b)*(a+b)) << std::endl;
	}

	return 0;
}
