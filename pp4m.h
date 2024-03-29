/* Private Project Four Me */

#ifndef _PP4M_H
#define _PP4M_H

#define MOVED(a) a*10 // move up of digits

#include <time.h>
#include <stdbool.h>

#if __has_include(<SDL2/SDL.h>)

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

extern SDL_Color PP4M_BLACK;

extern SDL_Color PP4M_GREY_LIGHT;
extern SDL_Color PP4M_GREY_NORMAL;
extern SDL_Color PP4M_GREY_HEAVY;
extern SDL_Color PP4M_GREY_DARK;

extern SDL_Color PP4M_WHITE;

extern SDL_Color PP4M_RED;
extern SDL_Color PP4M_GREEN;
extern SDL_Color PP4M_BLUE;

extern SDL_Color PP4M_YELLOW;
extern SDL_Color PP4M_PINK;
extern SDL_Color PP4M_CYAN;

typedef struct {
    char text[1024];
    SDL_Rect rect;
    SDL_Color color;
    TTF_Font *font;
    SDL_Surface *surface;
    SDL_Texture *texture;
} PP4M_SDL;

#endif // __has_include

typedef enum {

    WINDOW,
    WINDOW_FULLSCREEN,
    WINDOW_RESIZABLE

} PP4M_WINDOW_SIZE;

typedef struct _pp4m_link_t {
    void *ptr;
    struct _pp4m_link_t *next;
} PP4M_HOOK;

typedef struct {
    int *x;
    int *y;
    int *w;
    int *h;
} PP4M_HOOK_RECT;

#if __has_include(<SDL2/SDL.h>)

SDL_Renderer *pp4m_Init(SDL_Window *window, char *title, int width, int height, PP4M_WINDOW_SIZE size);
void pp4m_Quit(SDL_Window *window, SDL_Renderer *renderer);

#endif // __has_include

void pp4m_GetDateAndTime(char *dst);
clock_t pp4m_LimitFramerate(clock_t framepersec);
clock_t pp4m_DeltaFramerate(void);
bool pp4m_FramerateTimer(int val, int *old, int delta_clock);
int pp4m_SecondsTick(void) ;
int pp4m_Framerate(void);

PP4M_HOOK *pp4m_HOOK_Init(void);
int pp4m_HOOK_Size(PP4M_HOOK *head);
void pp4m_HOOK_Next(PP4M_HOOK *head, void *ptr);
void pp4m_HOOK_AttachHead(PP4M_HOOK **head, void *ptr);
void pp4m_HOOK_RemoveHead(PP4M_HOOK **head);
void pp4m_HOOK_Remove(PP4M_HOOK *head);

int pp4m_p_itod(int foo);
int pp4m_p_itodv(int index);
int pp4m_p_int_index(int foo, int index);

#endif // _PP4M_H

/* 2022 @waifro */
