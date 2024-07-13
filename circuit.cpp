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

std::vector<State> HALF_ADDER(Logic &x, Logic &y){
	std::vector<State> output;
	output.push_back(XOR(x,y));
	output.push_back(AND(x,y));
	return output;
}
std::vector<State> HALF_ADDER(Logic &x, State y){
	std::vector<State> output;
	output.push_back(XOR(x,y));
	output.push_back(AND(x,y));
	return output;
}
std::vector<State> HALF_ADDER(State x, Logic &y){
	std::vector<State> output;
	output.push_back(XOR(x,y));
	output.push_back(AND(x,y));
	return output;
}
std::vector<State> HALF_ADDER(State x, State y){
	std::vector<State> output;
	output.push_back(XOR(x,y));
	output.push_back(AND(x,y));
	return output;
}

std::vector<State> FULL_ADDER(Logic &x, Logic &y, State carry_in = State::Low){
	std::vector<State> output;
	output.push_back((XOR(XOR(x,y), carry_in)));
	output.push_back(OR(AND(XOR(x,y), carry_in), AND(x,y)));
	return output;
}
std::vector<State> FULL_ADDER(Logic &x, State y, State carry_in = State::Low){
	std::vector<State> output;
	output.push_back((XOR(XOR(x,y), carry_in)));
	output.push_back(OR(AND(XOR(x,y), carry_in), AND(x,y)));
	return output;
}
std::vector<State> FULL_ADDER(State x, Logic &y, State carry_in = State::Low){
	std::vector<State> output;
	output.push_back((XOR(XOR(x,y), carry_in)));
	output.push_back(OR(AND(XOR(x,y), carry_in), AND(x,y)));
	return output;
}
std::vector<State> FULL_ADDER(State x, State y, State carry_in = State::Low){
	std::vector<State> output;
	output.push_back((XOR(XOR(x,y), carry_in)));
	output.push_back(OR(AND(XOR(x,y), carry_in), AND(x,y)));
	return output;
}

std::vector<State> ADDER_BIT_4(Logic &a, Logic &b, Logic &c, Logic &d, Logic &a1, Logic &b1, Logic &c1, Logic &d1, State carry_in){
	std::vector<State> output;
	std::vector<State> adder_1_output = FULL_ADDER(d, d1, carry_in);
	std::vector<State> adder_2_output = FULL_ADDER(c, c1, adder_1_output[1]);
	std::vector<State> adder_3_output = FULL_ADDER(b, b1, adder_2_output[1]);
	std::vector<State> adder_4_output = FULL_ADDER(a, a1, adder_3_output[1]);

	// 1101
	output.push_back(adder_1_output[0]); // 1,0,0,0
	output.push_back(adder_2_output[0]); // 1,1,0,0
	output.push_back(adder_3_output[0]); // 0,1,1,0
	output.push_back(adder_4_output[0]); // 1,0,1,1
	output.push_back(adder_4_output[1]); // 1

	// 1011 || Carry_out = 1
	return output;
}
std::vector<State> ADDER_BIT_4(State a, State b, State c, State d, State a1, State b1, State c1, State d1, State carry_in){
	std::vector<State> output;
	std::vector<State> adder_1_output = FULL_ADDER(d, d1, carry_in);
	std::vector<State> adder_2_output = FULL_ADDER(c, c1, adder_1_output[1]);
	std::vector<State> adder_3_output = FULL_ADDER(b, b1, adder_2_output[1]);
	std::vector<State> adder_4_output = FULL_ADDER(a, a1, adder_3_output[1]);

	// 1101
	output.push_back(adder_1_output[0]); // 1,0,0,0
	output.push_back(adder_2_output[0]); // 1,1,0,0
	output.push_back(adder_3_output[0]); // 0,1,1,0
	output.push_back(adder_4_output[0]); // 1,0,1,1
	output.push_back(adder_4_output[1]); // 1

	// 1011 || Carry_out = 1
	return output;
}
