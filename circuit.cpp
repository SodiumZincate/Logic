#include "circuit.h"

Logic::Logic(State x){
	state = x;
}
Logic::Logic(){
	state = State::Low;
}
void Logic::init(State x){
	state = x;
}

State Logic::operator*(Logic x){
	return static_cast<State>(static_cast<int>(state) && static_cast<int>(x.state));
}
State Logic::operator*(State x){
	return static_cast<State>(static_cast<int>(state) && static_cast<int>(x));
}
State operator*(State x, Logic y){
	return static_cast<State>(static_cast<int>(x) && static_cast<int>(y.state));
}
State operator*(State x, State y){
	return static_cast<State>(static_cast<int>(x) && static_cast<int>(y));
}

State AND(Logic &x, Logic &y){
	return static_cast<State>(static_cast<int>(x.state) && static_cast<int>(y.state));
}
State AND(Logic &x, State y){
	return static_cast<State>(static_cast<int>(x.state) && static_cast<int>(y));
}
State AND(State x, Logic &y){
	return static_cast<State>(static_cast<int>(x) && static_cast<int>(y.state));
}
State AND(State x, State y){
	return static_cast<State>(static_cast<int>(x) && static_cast<int>(y));
}


State Logic::operator+(Logic x){
	return static_cast<State>(static_cast<int>(state) || static_cast<int>(x.state));
}
State Logic::operator+(State x){
	return static_cast<State>(static_cast<int>(state) || static_cast<int>(x));
}
State operator+(State x, Logic y){
	return static_cast<State>(static_cast<int>(x) || static_cast<int>(y.state));
}
State operator+(State x, State y){
	return static_cast<State>(static_cast<int>(x) || static_cast<int>(y));
}

State OR(Logic &x, Logic &y){
	return static_cast<State>(static_cast<int>(x.state) || static_cast<int>(y.state));
}
State OR(Logic &x, State y){
	return static_cast<State>(static_cast<int>(x.state) || static_cast<int>(y));
}
State OR(State x, Logic &y){
	return static_cast<State>(static_cast<int>(x) || static_cast<int>(y.state));
}
State OR(State x, State y){
	return static_cast<State>(static_cast<int>(x) || static_cast<int>(y));
}


State Logic::operator!(){
	return static_cast<State>(!static_cast<int>(state));
}


State XOR(Logic &x, Logic &y){
	return static_cast<State>(!(x.state*y.state)*(x.state+y.state));
}
State XOR(Logic &x, State y){
	return static_cast<State>(!(x.state*y)*(x.state+y));
}
State XOR(State x, Logic &y){
	return static_cast<State>(!(x*y.state)*(x+y.state));
}
State XOR(State x, State y){
	return static_cast<State>(!(x*y)*(x+y));
}

std::vector<State> ADDER_BIT_2(Logic &x, Logic &y, State carry_in = State::Low){
	std::vector<State> output;
	output.push_back((XOR(XOR(x.state,y.state), carry_in)));
	output.push_back(OR(AND(XOR(x.state,y.state), carry_in), AND(x.state,y.state)));
	return output;
}
std::vector<State> ADDER_BIT_2(Logic &x, State y, State carry_in = State::Low){
	std::vector<State> output;
	output.push_back((XOR(XOR(x.state,y), carry_in)));
	output.push_back(OR(AND(XOR(x.state,y), carry_in), AND(x.state,y)));
	return output;
}
std::vector<State> ADDER_BIT_2(State x, Logic &y, State carry_in = State::Low){
	std::vector<State> output;
	output.push_back((XOR(XOR(x,y.state), carry_in)));
	output.push_back(OR(AND(XOR(x,y.state), carry_in), AND(x,y.state)));
	return output;
}
std::vector<State> ADDER_BIT_2(State x, State y, State carry_in = State::Low){
	std::vector<State> output;
	output.push_back((XOR(XOR(x,y), carry_in)));
	output.push_back(OR(AND(XOR(x,y), carry_in), AND(x,y)));
	return output;
}

// std::vector<State> ADDER_BIT_4(Logic &x, Logic &y, State carry_in){
// 	std::vector<State> output;
// 	output.push_back((XOR(XOR(x,y), carry_in)));
// 	output.push_back(OR(AND(XOR(x,y), carry_in), AND(x,y)));
// 	return output;
// }