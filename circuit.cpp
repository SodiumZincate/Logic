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