#include "../../TinyEngine.h"
#include "effects.h"

int main( int argc, char* args[] ) {

	Tiny::window("Shader Effects Example", 1000, 1000);

	Tiny::event.handler = [](){ /* ... */ };

	Tiny::view.interface = interfaceFunc;

	//Load the Sprite
	Billboard sprite(1200, 800, false);
	sprite.raw(image::load("canyon.png"));

	//Shaders
	Shader effect("shader/effect.vs", "shader/effect.fs", {"in_Quad", "in_Tex"});

	//Render Pipeline
	Tiny::view.pipeline = [&](){

		//Render Billboard to Screen
		Tiny::view.target(color::black);

		effect.use();	//Setup Shader
		effect.uniform("index", ind);
		effect.uniform("res", res);
		effect.uniform("bits", bits);

		//Add the Texture
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sprite.texture);
		effect.uniform("imageTexture", 0);
		effect.uniform("model", sprite.model);

		sprite.render(); //Render Sprite

	};

	Tiny::loop([&](){
		/* Absolutely Nothing! */
	});

	Tiny::quit();

	return 0;
}
