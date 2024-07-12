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

State Logic::operator!(){
	return static_cast<State>(!static_cast<int>(state));
}