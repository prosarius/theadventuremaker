#include "../h/Graphics.h"

using namespace std;
Graphics::Graphics(Screen* screen) : screen(screen), debug(false){
	this->window = NULL;
	this->renderer = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL_Init failed" << endl;
		return;
	}
	this->window = SDL_CreateWindow( "Mayas Traum",
		   	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen->getWidth(),
			screen->getHeight(), SDL_WINDOW_SHOWN );
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
    this->screen->sortScreenObjects();
	for (auto object: this->screen->getScreenObjects())
		this->drawScreenObject(object);
    if (this->debug)
        for (auto e: this->screen->graph.getEdges())
            SDL_RenderDrawLine(this->renderer, e.getBegin().getX(), e.getBegin().getY(), e.getEnd().getX(), e.getEnd().getY());
	this->present();
}
void Graphics::drawBackground() {
	SDL_Rect rect = {0, 0, this->screen->getWidth(), this->screen->getHeight()};
	SDL_RenderCopy(this->renderer, this->getTextureFromPath(this->screen->getBackgroundPath()), NULL, &rect);
}
SDL_Texture* Graphics::getTextureFromPath(const string &texturePath) {
	if(!this->textures.count(texturePath))
		this->textures.insert(pair<string, SDL_Texture*>(texturePath, IMG_LoadTexture(this->renderer, texturePath.c_str())));
	return this->textures.at(texturePath);
}
void Graphics::clear() {
	SDL_RenderClear(this->renderer);
}
void Graphics::drawScreenObject(ScreenObject* screenObject) {
	SDL_Rect rect = {
		int(screenObject->getPosX() - screenObject->getRenderWidth() * screenObject->getPivotX()),
		int(screenObject->getPosY() - screenObject->getRenderHeight() * screenObject->getPivotY()),
		int(screenObject->getRenderWidth()),
		int(screenObject->getRenderHeight()) };
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
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            running = false;
                            break;
                        case SDL_SCANCODE_D:
                            if (this->debug)
                                this->debug = false;
                            else
                                this->debug = true;
                            break;
                        default:
                            break;
                    }
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(event.button.button == SDL_BUTTON_LEFT) {
					//	cout << "Mousebuttonevent incoming" << endl;
						this->screen->getPlayer()->startRunning();
						this->screen->getPlayer()->setTarget(float(event.motion.x), float(event.motion.y));
					}
					break;
				case SDL_QUIT:
					//cout << "quit" << endl;
					running = false;
					break;
			}
		}
		this->draw();
		this->screen->getPlayer()->tick();
		//cout << "check new Position: (" << this->screen->getPlayer()->getPosX() << " | " << this->screen->getPlayer()->getPosY() << ")" << endl;
		SDL_Delay(10);
	}
}
