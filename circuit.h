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
		State operator*(Logic x);
		State operator*(State x);
		friend State operator*(State, Logic);
		friend State operator*(State, State);

		State operator+(Logic x);
		State operator+(State x);
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
