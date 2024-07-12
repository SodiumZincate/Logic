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
		Logic(State);
		Logic();
		void init(State);

		State operator*(Logic);
		State operator*(State);
		friend State operator*(State, Logic);
		friend State operator*(State, State);

		State operator+(Logic);
		State operator+(State);
		friend State operator+(State, Logic);
		friend State operator+(State, State);

		State operator!();

		State XOR(Logic x);
		State XOR(State x);
		friend State XOR(State, Logic);
		friend State XOR(State, State);
};
