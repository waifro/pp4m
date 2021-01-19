/* Private Project Four Me */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "pp4m_ttf.h"

SDL_Color PP4M_WHITE = {255, 255, 255, 255};

void pp4m_TTF_Init(void) {

    TTF_Init();

    return;

}

void pp4m_TTF_Quit(void) {

    TTF_Quit();

    return;

}

SDL_Texture *pp4m_TTF_TextureFont(SDL_Renderer *renderer, char filename[256], int size, SDL_Rect *rectsrc, float x, float y, char text[1024]) {

    TTF_Font *font = NULL;

    font = TTF_OpenFont(filename, size);

    SDL_Surface *surface = TTF_RenderText_Solid(font, text, PP4M_WHITE);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    rectsrc->x = x;
    rectsrc->y = y;
    SDL_QueryTexture(texture, NULL, NULL, &rectsrc->w, &rectsrc->h);

    return texture;

}

/*                                         Copyright (c) 2021 @richardwaifro //
#                                                                                                                                                    #
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), #
# to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, #
# and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:         #
# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.                     #
#                                                                                                                                                    #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,                                                                                    #
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                                                                #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.                                                                                              #
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,                                                                        #
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,                                                     #
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                                            #
#                                                                                                                                                    #
/#                                         Copyright (c) 2021 @richardwaifro */
