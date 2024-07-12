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

		State operator*(Logic x);
		State operator*(State x);
		friend State operator*(State, Logic);
		friend State operator*(State, State);

		State operator+(Logic x);
		State operator+(State x);
		friend State operator+(State, Logic);
		friend State operator+(State, State);

		State operator!();
};
