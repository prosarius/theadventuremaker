#include "../h/Graphics.h"

using namespace std;
Graphics::Graphics(Screen* screen) : screen(screen) {
	this->window = NULL;
	this->renderer = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL_Init failed" << endl;
		return;
	}
	this->window = SDL_CreateWindow( "Mayas Traum",
		   	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900,
			SDL_WINDOW_SHOWN );
	if(!this->window) {
		cerr << "Window Creation failed" << endl;
		return;
	}
	this->renderer = SDL_CreateRenderer(this->window, -1,
			SDL_RENDERER_ACCELERATED);
	if(!this->renderer) {
		cerr << "Renderer Creation failed" << endl;
		return;
	}
	this->mainEvent = new SDL_Event();
}

void Graphics::draw() {
	this->clear();
	this->drawBackground();
	//this->screen->getPlayer()->tick();
	for(auto object: this->screen->getScreenObjects()) {
		this->drawScreenObject(object);
	}
	this->present();
}
void Graphics::drawBackground() {
	SDL_Rect rect = {0, 0, this->screen->getWidth(), this->screen->getHeight()};
	SDL_RenderCopy(this->renderer, this->getTextureFromPath(this->screen->getBackgroundPath()), NULL, &rect);
}
SDL_Texture* Graphics::getTextureFromPath(string path) {
	if(!this->textures.count(path))
		this->textures.insert(pair<string, SDL_Texture*>(path, IMG_LoadTexture(this->renderer, path.c_str())));
	return this->textures.at(path);
}
void Graphics::clear() {
	SDL_RenderClear(this->renderer);
}
void Graphics::drawScreenObject(ScreenObject* screenObject) {
	SDL_Rect rect = {
		int(screenObject->getPosX()),
		int(screenObject->getPosY()),
		int(screenObject->getWidth()),
		int(screenObject->getHeight()) };
	screenObject->getActiveAnimation()->tick();
	SDL_RenderCopy(this->renderer, this->getTextureFromPath(screenObject->getActiveAnimation()->getActiveImage()), NULL, &rect);
}
void Graphics::present() {
	SDL_RenderPresent(this->renderer);
}
Graphics::~Graphics() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
}
void Graphics::run() {
	bool running = true;

	while(running) {
		this->draw();
		SDL_Event event;
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_KEYDOWN:
					if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					   	running = false;
						cout << "escape" << endl;
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(event.button.button == SDL_BUTTON_LEFT) {
						cout << "Mousebuttonevent incoming" << endl;
						this->screen->getPlayer()->startRunning();
						this->screen->getPlayer()->setTarget(float(event.motion.x), float(event.motion.y));
					}
					break;
				case SDL_QUIT:
					cout << "quit" << endl;
					running = false;
					break;
			}
		}
		this->draw();
		this->screen->getPlayer()->tick();
		cout << "check new Position: (" << this->screen->getPlayer()->getPosX() << " | " << this->screen->getPlayer()->getPosY() << ")" << endl;
		SDL_Delay(10);
	}
}
