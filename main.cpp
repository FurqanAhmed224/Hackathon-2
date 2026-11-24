// okay with my phone project, going to start of by doing these tasks
// initalizing raylib, loading all the png's i have under phoneAssets
// basically setting up how its done in the example code

// configure the project: cmake -B build
// compile: cmake --build build
// run: ./build/main

// commiting to github
 // git add .
 // git commit -m "what i want to say"
 // git push

#include <iostream>
#include "raylib.h"
#include "App.h"

using namespace std;

int main() {

    // open a window 
    InitWindow(1400,800,"Window");

    SetTargetFPS(30); // setting FPS

    // need to load all images in the project
    // CITATION: all images were uploaded from the web

    Texture2D Phonephoto = LoadTexture("phoneAssets/phone.png"); // loading the phone texture
    Texture2D chatPhoto = LoadTexture("phoneAssets/chat.png"); // loading the phone texture
    Texture2D healthPhoto = LoadTexture("phoneAssets/health.png"); // loading the phone texture
    Texture2D mapPhoto = LoadTexture("phoneAssets/maps.png"); // loading the phone texture
    Texture2D musicPhoto = LoadTexture("phoneAssets/music.png"); // loading the phone texture
    Texture2D shopPhoto = LoadTexture("phoneAssets/shop.png"); // loading the phone texture
    Texture2D instagramInterface = LoadTexture("phoneAssets/instagram.png"); // loading the instagram interface
    Texture2D healthInterface = LoadTexture("phoneAssets/appleHealth.png"); // interface png still needed
    Texture2D mapsInterface = LoadTexture("phoneAssets/googleMaps.png"); // interface png still needed
    Texture2D musicInterface = LoadTexture("phoneAssets/appleMusic.png"); // interface png still needed
    Texture2D shopInterface = LoadTexture("phoneAssets/shopify.png"); // interface png still needed

    // checking if images are loaded successfully

    if(Phonephoto.id == 0){
        CloseWindow();
        return -1;
    }

    if(chatPhoto.id == 0){
        CloseWindow();
        return -1;
    }

    if(healthPhoto.id == 0){
        CloseWindow();
        return -1;
    }

    if(mapPhoto.id == 0){
        CloseWindow();
        return -1;
    }

    if(musicPhoto.id == 0){
        CloseWindow();
        return -1;
    }

    if(shopPhoto.id == 0){
        CloseWindow();
        return -1;
    }

    if(instagramInterface.id == 0){
        CloseWindow();
        return -1;
    }

    // these variables basically control which screen will be pushed/displayed
     int currentScreen = 0; // phonescreen or instagramInterface?
     bool showLocationPrompt = false; // permission popup
     bool locationPermissionAnswered = false; // user makes decision
     bool locationPermissionGranted = false; // stores what deceision user makes
     int continueStep = 0; // the continue box and stuff

     App apps[5] = {
        App("Instagram", "Posts, likes, and interactions", "Personal interests and social connections"),
        App("Health", "Steps, heart rate, and activity records", "Daily habits and physical activity"),
        App("Google Maps", "Location history, searches, and routes", "Home, work, and frequently visited places"),
        App("Spotify", "Listening history and favorite songs", "Music preferences and interests"),
        App("Shopify", "Purchase history and shopping activity", "Shopping habits and consumer preferences")
    };

    // got to keep hte window run until user closes

    while(!WindowShouldClose()){



        BeginDrawing(); // new drawing
        ClearBackground(BLACK);
        
        if(currentScreen == 0){ // when its 0, its in the phone home interface, when it goes to 1, it will click the specific app its on
            Rectangle sourcePhone = { 0, 0, (float)Phonephoto.width, (float)Phonephoto.height };
            Rectangle sourceChat = { 0, 0, (float)chatPhoto.width, (float)chatPhoto.height };
            Rectangle sourceHealth = { 0, 0, (float)healthPhoto.width, (float)healthPhoto.height };
            Rectangle sourceMap = { 0, 0, (float)mapPhoto.width, (float)mapPhoto.height };
            Rectangle sourceMusic = { 0, 0, (float)musicPhoto.width, (float)musicPhoto.height };
            Rectangle sourceShop = { 0, 0, (float)shopPhoto.width, (float)shopPhoto.height };

            Rectangle phoneDest   = { 250, 150, 500, 500 };
            Rectangle chatDest   = { 420, 260, 50, 50};
            Rectangle healthDest   = { 530, 260, 50, 50};
            Rectangle mapDest   = { 420, 360, 50, 50};
            Rectangle musicDest   = { 530, 360, 50, 50};
            Rectangle shopDest   = { 475, 460, 50, 50};

            // draws the phone and app icons
            DrawTexturePro(Phonephoto, sourcePhone, phoneDest, {0, 0}, 0.0f, WHITE);
            DrawTexturePro(chatPhoto, sourceChat, chatDest, {0, 0}, 0.0f, WHITE);
            DrawTexturePro(healthPhoto, sourceHealth, healthDest, {0, 0}, 0.0f, WHITE);
            DrawTexturePro(mapPhoto, sourceMap, mapDest, {0, 0}, 0.0f, WHITE);
            DrawTexturePro(musicPhoto, sourceMusic, musicDest, {0, 0}, 0.0f, WHITE);
            DrawTexturePro(shopPhoto, sourceShop, shopDest, {0, 0}, 0.0f, WHITE);
            
             // ok next I need to click any app in my template, for the first one I will just work with instagram, and finsih all neccessary steps for this one
        
            Vector2 mouse = GetMousePosition(); // vector2 is a raylib data type storing x and y values

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse,chatDest)){ // detecting if mouse was clicked, and making sure it touches instagram
                std::cout << "X: " << mouse.x << " Y: " << mouse.y << endl;
                currentScreen = 1;
            }

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse,healthDest)){ // now detecting when mouse clicks the healh app
                std::cout << "X: " << mouse.x << " Y: " << mouse.y << endl;
                currentScreen = 2;
            }

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse,mapDest)){ // now detecting when mouse clicks the map app
                std::cout << "X: " << mouse.x << " Y: " << mouse.y << endl;
                currentScreen = 3;
            }

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse,musicDest)){ // now detecting when mouse clicks the music app
                std::cout << "X: " << mouse.x << " Y: " << mouse.y << endl;
                currentScreen = 4;
            }

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse,shopDest)){ // now detecting when mouse clicks the shopn app
                std::cout << "X: " << mouse.x << " Y: " << mouse.y << endl;
                currentScreen = 5;
            }
        }
            // instagram screen, basically when the app is pressed, currentscreen switches to 1, which load this if statement
        if(currentScreen == 1){
             // instagram interface clicked

             Vector2 mouse = GetMousePosition(); // vector2 is a raylib data type storing x and y values
             Rectangle createPostButton = {480,548,40,40}; // clickabale area for instagram

             Rectangle sourceInstagram = {0,0,(float)instagramInterface.width,(float)instagramInterface.height};
             Rectangle instagramDest = {402,221,198,371};
             DrawTexturePro(instagramInterface,sourceInstagram,instagramDest,{0,0},0.0f,WHITE);

             if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse, createPostButton)){ // detecting if mouse was clicked, and making sure it touches instagram
                showLocationPrompt = true; // permission prompt should appear
             }

             // adding the permission prompt
            if(showLocationPrompt == true){

                Rectangle allowButton = {435,390,55,30};
                Rectangle denyButton = {495,390,75,30};

                //allow
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse, allowButton)){ // detecting if mouse was clicked, and making sure it touches instagram
                    locationPermissionGranted = true;
                    locationPermissionAnswered = true;
                    continueStep = 0;
                    showLocationPrompt = false; // permission prompt should appear

                    std::cout << "John Doe has allowed location access" << endl;
            }
                     
            // denied prompt
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse, denyButton)){ // detecting if mouse was clicked, and making sure it touches instagram
                locationPermissionGranted = false;
                locationPermissionAnswered = true;
                continueStep = 0;
                showLocationPrompt = false; // permission prompt should appear

                //testing

                std::cout << "John doe has denied location access." << endl;
            }


                DrawRectangle(420,330,160,130,LIGHTGRAY);
                DrawText("Allow Location?",420,345,16,BLACK);

                DrawRectangle(435,390,55,30,GREEN);
                DrawText("Allow",442,398,12,WHITE);

                DrawRectangle(495,390,75,30,RED);
                DrawText("Dont Allow",497,398,10,WHITE);
            }

            
            // privacy insight panel
            DrawRectangle(800,150,550,500,WHITE);
            DrawRectangleLines(800,150,550,500,GRAY);

            DrawText("Privacy Insights",830,175,28,DARKBLUE);
            DrawText("INSTAGRAM - JOHN DOE",830,215,16,DARKGRAY);

            // navigation buttons
            Rectangle backButton = {830,590,100,35};
            Rectangle nextButton = {1220,590,100,35};

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

                if(CheckCollisionPointRec(mouse,backButton) && continueStep > 0){
                    continueStep--;
                }

                if(CheckCollisionPointRec(mouse,nextButton) && continueStep < 2){
                    continueStep++;
                }
            }

            // stage 1: permission
            if(continueStep == 0){

                DrawText("01 - PERMISSION",830,270,20,DARKBLUE);

                if(locationPermissionAnswered == false){
                    DrawText("LOCATION ACCESS: PENDING",830,320,18,ORANGE);
                    DrawText("Instagram is requesting access to",830,365,17,BLACK);
                    DrawText("John's device location.",830,390,17,BLACK);
                    DrawText("Choose Allow or Don't Allow on the phone.",830,455,15,DARKGRAY);
                }
                else if(locationPermissionGranted == true){
                    DrawText("LOCATION ACCESS: GRANTED",830,320,18,GREEN);
                    DrawText("John allowed Instagram to access",830,365,17,BLACK);
                    DrawText("his device location through this",830,390,17,BLACK);
                    DrawText("permission.",830,415,17,BLACK);
                }
                else{
                    DrawText("LOCATION ACCESS: DENIED",830,320,18,RED);
                    DrawText("John restricted Instagram from",830,365,17,BLACK);
                    DrawText("accessing his device location",830,390,17,BLACK);
                    DrawText("through this permission.",830,415,17,BLACK);
                }
            }

            // stage 2: possible inferences
            else if(continueStep == 1){

                DrawText("02 - POSSIBLE INFERENCES",830,270,20,DARKBLUE);

                if(locationPermissionGranted == true){
                    DrawText("Repeated location records could",830,330,17,BLACK);
                    DrawText("help reveal patterns such as:",830,355,17,BLACK);
                    DrawText("- Frequently visited places",830,410,17,BLACK);
                    DrawText("- Possible home and work locations",830,440,17,BLACK);
                    DrawText("- Daily movement patterns",830,470,17,BLACK);
                }
                else{
                    DrawText("Location access through this",830,330,17,BLACK);
                    DrawText("permission is restricted.",830,355,17,BLACK);
                    DrawText("However, other information such as",830,410,17,BLACK);
                    DrawText("public photos and posts could still",830,440,17,BLACK);
                    DrawText("provide clues about location.",830,470,17,BLACK);
                }
            }

            // stage 3: privacy impact
            else if(continueStep == 2){

                DrawText("03 - PRIVACY IMPACT",830,270,20,DARKBLUE);

                if(locationPermissionGranted == true){
                    DrawText("POTENTIAL BENEFIT",830,330,18,DARKGREEN);
                    DrawText("Location-based features can provide",830,360,16,BLACK);
                    DrawText("useful services and recommendations.",830,385,16,BLACK);

                    DrawText("PRIVACY CONSIDERATION",830,440,18,DARKBLUE);
                    DrawText("Repeated records can reveal personal",830,470,16,BLACK);
                    DrawText("patterns. Access and sharing depend",830,495,16,BLACK);
                    DrawText("on the app's actual practices.",830,520,16,BLACK);
                }
                else{
                    DrawText("PRIVACY BENEFIT",830,330,18,DARKGREEN);
                    DrawText("One source of location information",830,360,16,BLACK);
                    DrawText("has been restricted.",830,385,16,BLACK);

                    DrawText("LIMITATION",830,440,18,DARKBLUE);
                    DrawText("This does not guarantee complete",830,470,16,BLACK);
                    DrawText("anonymity. Other information could",830,495,16,BLACK);
                    DrawText("still reveal details about John.",830,520,16,BLACK);
                }
            }

            // navigation controls
            DrawRectangleRec(backButton,LIGHTGRAY);
            DrawText("BACK",855,600,15,BLACK);

            DrawRectangleRec(nextButton,BLUE);
            DrawText("NEXT",1248,600,15,WHITE);

            DrawText(TextFormat("%d / 3",continueStep+1),1075,600,16,DARKGRAY);

        }

        EndDrawing();
    }

    // CITATION: used chatgpt: getting an error for "cout is ambigious", chatgpt said just use std before cout, Im guessing because of the raylib header

    UnloadTexture(Phonephoto);
    std:: cout << endl << endl << endl;
    std::cout << "more can happen in the terminal after the window is closed ..." << endl;

    UnloadTexture(chatPhoto);
    std::cout << endl << endl << endl;
    std::cout << "more can happen in the terminal after the window is closed ..." << endl;

    UnloadTexture(healthPhoto);
    std::cout << endl << endl << endl;
    std::cout << "more can happen in the terminal after the window is closed ..." << endl;

    UnloadTexture(mapPhoto);
    std::cout << endl << endl << endl;
    std::cout << "more can happen in the terminal after the window is closed ..." << endl;

    UnloadTexture(musicPhoto);
    std::cout << endl << endl << endl;
    std::cout << "more can happen in the terminal after the window is closed ..." << endl;

    UnloadTexture(shopPhoto);

    UnloadTexture(instagramInterface);

    CloseWindow();
    std::cout << endl << endl << endl;
    std::cout << "more can happen in the terminal after the window is closed ..." << endl;


    return 0;
}