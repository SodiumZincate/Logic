#pragma once

#include<iostream>
#include<vector>
#include<cmath>

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

		friend State AND(Logic&, Logic&);
		friend State AND(Logic&, State);
		friend State AND(State, Logic&);

		State operator+(Logic);
		State operator+(State);
		friend State operator+(State, Logic);
		friend State operator+(State, State);

		friend State OR(Logic&, Logic&);
		friend State OR(Logic&, State);
		friend State OR(State, Logic&);

		State operator!();

		friend State XOR(Logic&, Logic&);
		friend State XOR(Logic&, State);
		friend State XOR(State, Logic&);
		
		friend std::vector<State> ADDER_BIT_2(Logic&, Logic&, State);
		friend std::vector<State> ADDER_BIT_2(Logic&, State, State);
		friend std::vector<State> ADDER_BIT_2(State, Logic&, State);
		
		// friend std::vector<State> ADDER_BIT_4(Logic&, Logic&, State = State::Low);
};

State OR(State, State);
State AND(State, State);
State XOR(State, State);
std::vector<State> ADDER_BIT_2(State, State, State);