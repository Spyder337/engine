#include <iostream>
#include <string>
#include <Rendering/GameWindow.hpp>

using namespace std;

int main(){
	cout << "Hello World!" << endl;
	GameWindow* win = new GameWindow("Test", 1100, 700);
	win->Start();
	win->Stop();
	return 0;
}