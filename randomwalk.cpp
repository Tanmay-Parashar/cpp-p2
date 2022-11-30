#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<graphics.h>
#include<random>

int main()
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_CreateWindowAndRenderer(50*20 ,50*20,0,&window,&renderer);
	SDLL_RenderSetScale(renderer,20,20);
	
	int x = 30;
	int y = 30;
	
	std::random_device dev;
	std::uniform_int_distribution<uint8_t> nd(0,4);
	
	while(true)
	{
	    uint8_t dir = nd(dev);
	    
	    switch(dir)
	    {
	    	case 0:
	    		x -= 1;
	    		y -= 1;
	    		break;
	    	case 1:
	    		x += 1;
	    		y += 1;
	    		break;
	    	case 2:
	    		x += 1;
	    		y += 1;
	    		break;
	    	case 3:
	    		x -= 1;
	    		y -= 1;
	    		break;
		}
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		SDL_SetRenderDrawPoint(renderer, x,y);
		SDL_RenderPresent(renderer);
		
		if(x>50 || x<0 || y>50 || y<0)
		{
			x = 30;
			y = 30;
		}
	    SDL_Delay(50);
	}
}
