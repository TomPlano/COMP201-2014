// Handle input
#ifndef MEMORY_CONTROLLER_H
#define MEMORY_CONTROLLER_H
class Controller {
public:
    Controller() {
        model = new Model(8,8);
        view = new View;
    }
	~Controller(){
		delete model;
		delete view;
	} 
    // Event loop
    void loop();
private:
    Model * model;
    View * view;
};
#endif