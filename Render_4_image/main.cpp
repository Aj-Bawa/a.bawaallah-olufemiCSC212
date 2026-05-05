#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Cross", 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    // Load 4 different images
    SDL_Texture* img1 = IMG_LoadTexture(renderer, "image1.png");
    SDL_Texture* img2 = IMG_LoadTexture(renderer, "image2.png");
    SDL_Texture* img3 = IMG_LoadTexture(renderer, "image3.png");
    SDL_Texture* img4 = IMG_LoadTexture(renderer, "image4.png");

    float size = 150.0f;
    float cx = 400.0f;
    float cy = 300.0f;

    SDL_FRect top = { cx - size / 2, cy - size * 1.5f, size, size };
    SDL_FRect left = { cx - size * 1.5f, cy - size / 2.0f, size, size };
    SDL_FRect right = { cx + size / 2.0f, cy - size / 2.0f, size, size };
    SDL_FRect bottom = { cx - size / 2, cy + size / 2.0f, size, size };

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderTexture(renderer, img1, NULL, &top);
        SDL_RenderTexture(renderer, img2, NULL, &right);
        SDL_RenderTexture(renderer, img3, NULL, &bottom);
        SDL_RenderTexture(renderer, img4, NULL, &left);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(img1);
    SDL_DestroyTexture(img2);
    SDL_DestroyTexture(img3);
    SDL_DestroyTexture(img4);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
