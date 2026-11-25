// Hackathon #2: Liguangye You, Aiden Samuels, Furqan Ahmed

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

    InitWindow(1400, 800, "Digital Footprint");
    SetTargetFPS(30); // setting FPS

    // need to load all images in the project
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

        // putting the app icons into an array so I can access them using a loop easier
    Texture2D appIcons[5] = {chatPhoto, healthPhoto, mapPhoto, musicPhoto, shopPhoto};

    // putting all the app interfaces into an array in the same order
    Texture2D appInterfaces[5] = {instagramInterface, healthInterface, mapsInterface, musicInterface, shopInterface};

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
    int currentScreen = 0;
    int continueStep = 0;  // keeps track of which privacy insights page user is viewing

    // instagram permission variables
    bool showLocationPrompt = false;
    bool locationPermissionAnswered = false;
    bool locationPermissionGranted = false;

    // permission variables for the other apps
    bool showAppPrompt[5] = {false, false, false, false, false};
    bool appPromptAnswered[5] = {false, false, false, false, false};
    bool appPromptGranted[5] = {false, false, false, false, false};

    // this checks which apps user has opened
    bool appUsed[5] = {false, false, false, false, false};

    // app information
    App apps[5] = {
        App("Instagram", "Posts, likes, and interactions","Personal interests and social connections"),

        App("Apple Health", "Steps, heart rate, and activity records","Daily habits and physical activity"),

        App("Google Maps", "Location history, searches, and routes","Home, work, and frequently visited places"),

        App("Apple Music", "Listening history and favorite songs","Music preferences and interests"),

        App("Shopify", "Browsing activity, purchases, and shopping activity","Shopping habits and consumer preferences")
    };

    // this is the main phone position on the home screen
    Rectangle phoneDest = {175, 75, 650, 650};

    // app PNGs already contain their own phone frame
    // position the app interface between the two information panels
    Rectangle interfaceDest = {385, 75, 390, 650};

    // buttons inside the shifted app interfaces
    Rectangle homeButton = {557, 644, 49, 49};
    Rectangle createPostButton = {558, 586, 48, 48};

    // positions for the larger app icons on the home screen
    Rectangle appDest[5] = {{396, 218, 65, 65},{539, 218, 65, 65},{396, 348, 65, 65},{539, 348, 65, 65},{468, 478, 65, 65}
    };

    // button to open the final reflection
    Rectangle reflectionButton = {1110, 610, 210, 30};

    // got to keep hte window run until user closes
    while (!WindowShouldClose()) {

        BeginDrawing(); // new drawing

        Vector2 mouse = GetMousePosition();
        bool mouseClicked = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        ClearBackground(BLACK);

        // home screen
        if (currentScreen == 0) { // when its 0, its in the phone home interface, when it goes to 1, it will click the specific app its on

            Rectangle sourcePhone = {0, 0, (float)Phonephoto.width, (float)Phonephoto.height};

            // draw the main phone
            DrawTexturePro(Phonephoto, sourcePhone, phoneDest,{0, 0}, 0.0f, WHITE);

            // draw all five app icons
            for (int i = 0; i < 5; i++) {

                Rectangle sourceIcon = {0, 0, (float)appIcons[i].width,(float)appIcons[i].height};

                DrawTexturePro(appIcons[i], sourceIcon, appDest[i],{0, 0}, 0.0f, WHITE);
            }

            // this is the task panel on the top left
            DrawRectangle(20, 150, 140, 500, WHITE);
            DrawRectangleLines(20, 150, 140, 500, GRAY);

            DrawText("YOUR TASK", 30, 175, 17, DARKBLUE);
            DrawLine(30, 205, 150, 205, LIGHTGRAY);

            DrawText("Explore all five", 30, 230, 11, BLACK);
            DrawText("apps on John's", 30, 248, 11, BLACK);
            DrawText("phone.", 30, 266, 11, BLACK);

            DrawText("Review the data", 30, 310, 11, BLACK);
            DrawText("each app collects", 30, 328, 11, BLACK);
            DrawText("and the requests", 30, 346, 11, BLACK);
            DrawText("it makes.", 30, 364, 11, BLACK);

            DrawText("Choose whether", 30, 408, 11, BLACK);
            DrawText("to allow or deny", 30, 426, 11, BLACK);
            DrawText("each request.", 30, 444, 11, BLACK);

            DrawText("Read the privacy", 30, 488, 11, BLACK);
            DrawText("insights to see", 30, 506, 11, BLACK);
            DrawText("what John's data", 30, 524, 11, BLACK);
            DrawText("could reveal.", 30, 542, 11, BLACK);

            DrawLine(30, 570, 150, 570, LIGHTGRAY);

            DrawText("Complete all 5", 30, 590, 11, DARKBLUE);
            DrawText("to unlock the", 30, 608, 11, DARKBLUE);
            DrawText("final reflection.", 30, 626, 11, DARKBLUE);

            // this is the main privacy insights panel
            DrawRectangle(800, 150, 550, 500, WHITE);
            DrawRectangleLines(800, 150, 550, 500, GRAY);

            DrawText("John's Digital Footprint", 830, 175, 28, DARKBLUE);
            DrawText("JOHN DOE - OVERALL PRIVACY INSIGHTS",830, 215, 15, DARKGRAY);

            int appsOpened = 0;

            // count how many apps John opened
            for (int i = 0; i < 5; i++) {
                if (appUsed[i] == true) {
                    appsOpened++;
                }
            }

            DrawText("APPS EXPLORED:", 830, 255, 19, DARKBLUE);

            if (appsOpened == 0) {
                DrawText("0 / 5", 1000, 255, 19, DARKBLUE);
            }
            else if (appsOpened == 1) {
                DrawText("1 / 5", 1000, 255, 19, DARKBLUE);
            }
            else if (appsOpened == 2) {
                DrawText("2 / 5", 1000, 255, 19, DARKBLUE);
            }
            else if (appsOpened == 3) {
                DrawText("3 / 5", 1000, 255, 19, DARKBLUE);
            }
            else if (appsOpened == 4) {
                DrawText("4 / 5", 1000, 255, 19, DARKBLUE);
            }
            else {
                DrawText("5 / 5", 1000, 255, 19, DARKBLUE);
            }

            // show this message before John opens any apps
            if (appsOpened == 0) {

                DrawText("Your digital footprint starts here.",830, 320, 19, BLACK);

                DrawText("Explore the apps on the phone to see",830, 365, 17, DARKGRAY);

                DrawText("what information they may collect and",830, 390, 17, DARKGRAY);

                DrawText("what that information could reveal.",830, 415, 17, DARKGRAY);

                DrawText("Your choices will appear here as you",830, 475, 16, DARKBLUE);

                DrawText("explore each app.", 830, 500, 16, DARKBLUE);
            }

            // show information from apps already explored
            else {

                DrawText("APPS EXPLORED AND YOUR CHOICES",830, 300, 17, DARKBLUE);

                int yPosition = 335;

                for (int i = 0; i < 5; i++) {

                    if (appUsed[i] == true) {

                        // display the app name
                        if (i == 0) {
                            DrawText("Instagram", 830, yPosition, 15, BLACK);
                        }
                        else if (i == 1) {
                            DrawText("Apple Health", 830, yPosition, 15, BLACK);
                        }
                        else if (i == 2) {
                            DrawText("Google Maps", 830, yPosition, 15, BLACK);
                        }
                        else if (i == 3) {
                            DrawText("Apple Music", 830, yPosition, 15, BLACK);
                        }
                        else {
                            DrawText("Shopify", 830, yPosition, 15, BLACK);
                        }

                        // check the permission decision
                        if (i == 0) {

                            if (!locationPermissionAnswered) {
                                DrawText("Decision: Not answered",1050, yPosition, 13, ORANGE);
                            }
                            else if (locationPermissionGranted) {
                                DrawText("Decision: Allowed",1050, yPosition, 13, GREEN);
                            }
                            else {
                                DrawText("Decision: Denied",1050, yPosition, 13, RED);
                            }
                        }
                        else {

                            if (!appPromptAnswered[i]) {
                                DrawText("Decision: Not answered",1050, yPosition, 13, ORANGE);
                            }
                            else if (appPromptGranted[i]) {
                                DrawText("Decision: Allowed",1050, yPosition, 13, GREEN);
                            }
                            else {
                                DrawText("Decision: Denied",1050, yPosition, 13, RED);
                            }
                        }

                        yPosition += 32;
                    }
                }

                DrawLine(830, 505, 1320, 505, LIGHTGRAY);

                DrawText("WHAT COULD THIS REVEAL?",830, 520, 17, DARKBLUE);

                if (appsOpened == 1) {
                    DrawText("One app can reveal information about",830, 550, 14, BLACK);
                    DrawText("a person's interests or habits.",830, 572, 14, BLACK);
                }
                else {
                    DrawText("Separate app data can create a broader",830, 550, 14, BLACK);
                    DrawText("picture of John's interests, routines,",830, 572, 14, BLACK);
                    DrawText("and personal habits.",830, 594, 14, BLACK);
                }
            }

            // show the final reflection button after all five apps are explored
            if (appsOpened == 5) {

                DrawRectangleRec(reflectionButton, DARKBLUE);
                DrawText("VIEW FINAL REFLECTION",1120, 618, 13, WHITE);

                if (mouseClicked &&CheckCollisionPointRec(mouse, reflectionButton)) {

                    currentScreen = 6;
                }
            }

            // open an app using the app icon array
            for (int i = 0; i < 5; i++) {

                if (mouseClicked &&
                    CheckCollisionPointRec(mouse, appDest[i])) {

                    currentScreen = i + 1;
                    appUsed[i] = true;
                    continueStep = 0;

                    std::cout << apps[i].getAppName() << endl;
                    std::cout << apps[i].getInformationCollected() << endl;
                    std::cout << apps[i].getPossibleInference() << endl;
                }
            }
        }

        // Instagram screen
        else if (currentScreen == 1) {

            Rectangle sourceInstagram = { 0, 0, (float)appInterfaces[0].width, (float)appInterfaces[0].height
            };

            // only draw the Instagram PNG
            // it already has its own phone frame
            DrawTexturePro(appInterfaces[0], sourceInstagram,interfaceDest, {0, 0}, 0.0f, WHITE);

            // show the instructions
            DrawRectangle(30, 150, 330, 205, WHITE);
            DrawRectangleLines(30, 150, 330, 205, GRAY);

            DrawText("WHAT TO DO", 55, 175, 21, DARKBLUE);
            DrawText("Click the plus button at the bottom.",55, 225, 15, BLACK);
            DrawText("Review the location request.",55, 255, 15, BLACK);
            DrawText("Choose Allow or Don't Allow.", 55, 280, 15, BLACK);
            DrawText("Tap the circular home button to return home.",55, 315, 12, BLACK);

            // clicking the plus button opens the location request
            if (mouseClicked && CheckCollisionPointRec(mouse, createPostButton) &&!locationPermissionAnswered &&!showLocationPrompt) {

                showLocationPrompt = true;
            }

            // show the location permission popup
            if (showLocationPrompt) {

                Rectangle allowButton = {510, 450, 55, 30};
                Rectangle denyButton = {570, 450, 75, 30};

                if (mouseClicked && CheckCollisionPointRec(mouse, allowButton)) {

                    locationPermissionGranted = true;
                    locationPermissionAnswered = true;
                    continueStep = 0;
                    showLocationPrompt = false;

                    std::cout << "John Doe has allowed location access." << endl;
                }
                else if (mouseClicked && CheckCollisionPointRec(mouse, denyButton)) {

                    locationPermissionGranted = false;
                    locationPermissionAnswered = true;
                    continueStep = 0;
                    showLocationPrompt = false;

                    std::cout << "John Doe has denied location access." << endl;
                }

                DrawRectangle(490, 320, 170, 180, LIGHTGRAY);
                DrawRectangleLines(490, 320, 170, 180, GRAY);

                DrawText("Allow Location?", 500, 333, 15, BLACK);
                DrawText("Instagram wants access", 500, 360, 12, BLACK);
                DrawText("to John's device location.", 500, 378, 12, BLACK);
                DrawText("This can support location-", 500, 405, 11, DARKGRAY);
                DrawText("based features and posts.", 500, 420, 11, DARKGRAY);

                DrawRectangleRec(allowButton, GREEN);
                DrawText("Allow", 517, 458, 12, WHITE);

                DrawRectangleRec(denyButton, RED);
                DrawText("Dont Allow", 572, 458, 10, WHITE);
            }

            // Instagram privacy insights
            DrawRectangle(800, 150, 550, 500, WHITE);
            DrawRectangleLines(800, 150, 550, 500, GRAY);

            DrawText("Privacy Insights", 830, 175, 28, DARKBLUE);
            DrawText("INSTAGRAM - JOHN DOE", 830, 215, 16, DARKGRAY);

            Rectangle backButton = {830, 590, 100, 35};
            Rectangle nextButton = {1220, 590, 100, 35};

            // navigate through the privacy insights
            if (mouseClicked && !showLocationPrompt) {

                if (CheckCollisionPointRec(mouse, backButton) && continueStep > 0) {
                    continueStep--;
                }
                else if (CheckCollisionPointRec(mouse, nextButton) && continueStep < 2) {
                    continueStep++;
                }
            }

            // first page: permission
            if (continueStep == 0) {

                DrawText("01 - PERMISSION", 830, 270, 20, DARKBLUE);

                if (!locationPermissionAnswered) {
                    DrawText("LOCATION ACCESS: PENDING", 830, 320, 18, ORANGE);
                    DrawText("Instagram is requesting access to",830, 365, 17, BLACK);
                    DrawText("John's device location.",830, 390, 17, BLACK);
                    DrawText("Choose Allow or Don't Allow on the phone.",830, 455, 15, DARKGRAY);
                }
                else if (locationPermissionGranted) {
                    DrawText("LOCATION ACCESS: GRANTED", 830, 320, 18, GREEN);
                    DrawText("John allowed Instagram to access", 830, 365, 17, BLACK);
                    DrawText("his device location through this",830, 390, 17, BLACK);
                    DrawText("permission.", 830, 415, 17, BLACK);
                }
                else {
                    DrawText("LOCATION ACCESS: DENIED", 830, 320, 18, RED);
                    DrawText("John restricted Instagram from",830, 365, 17, BLACK);
                    DrawText("accessing his device location",830, 390, 17, BLACK);
                    DrawText("through this permission.",830, 415, 17, BLACK);
                }
            }

            // second page: possible inferences
            else if (continueStep == 1) {

                DrawText("02 - POSSIBLE INFERENCES", 830, 270, 20, DARKBLUE);

                if (locationPermissionGranted) {
                    DrawText("Location access can support features", 830, 330, 16, BLACK);
                    DrawText("that use John's device location.",830, 355, 16, BLACK);
                    DrawText("Other clues may reveal:",830, 410, 17, BLACK);
                    DrawText("- Places he frequently visits", 830, 440, 16, BLACK);
                    DrawText("- Locations he shares in posts",830, 470, 16, BLACK);
                    DrawText("- Possible daily routines", 830, 500, 16, BLACK);
                }
                else {
                    DrawText("Location access through this",830, 330, 16, BLACK);
                    DrawText("permission has been restricted.",830, 355, 16, BLACK);
                    DrawText("However, other clues may remain:",830, 410, 16, BLACK);
                    DrawText("- Public location-tagged posts", 830, 440, 16, BLACK);
                    DrawText("- Photos of recognizable places", 830, 470, 16, BLACK);
                    DrawText("- Repeated posting patterns",830, 500, 16, BLACK);
                }
            }

            // third page: privacy impact
            else if (continueStep == 2) {

                DrawText("03 - PRIVACY IMPACT", 830, 270, 20, DARKBLUE);

                if (locationPermissionGranted) {
                    DrawText("POTENTIAL BENEFIT", 830, 330, 18, DARKGREEN);
                    DrawText("Location features can make posts",830, 360, 16, BLACK);
                    DrawText("and content more relevant.",830, 385, 16, BLACK);
                    DrawText("PRIVACY CONSIDERATION", 830, 440, 18, DARKBLUE);
                    DrawText("Location clues can reveal personal",830, 470, 16, BLACK);
                    DrawText("routines and frequently visited places.",830, 495, 16, BLACK);
                    DrawText("Think carefully about what you share.",830, 520, 15, BLACK);
                }
                else {
                    DrawText("PRIVACY BENEFIT", 830, 330, 18, DARKGREEN);
                    DrawText("Denying access limits one source", 830, 360, 16, BLACK);
                    DrawText("of location information.",830, 385, 16, BLACK);
                    DrawText("LIMITATION", 830, 440, 18, DARKBLUE);
                    DrawText("Photos, posts, and other clues can",830, 470, 16, BLACK);
                    DrawText("still reveal places John visits.", 830, 495, 16, BLACK);
                    DrawText("Privacy requires more than one choice.", 830, 520, 15, BLACK);
                }
            }

            DrawRectangleRec(backButton, LIGHTGRAY);
            DrawText("BACK", 855, 600, 15, BLACK);

            DrawRectangleRec(nextButton, BLUE);
            DrawText("NEXT", 1248, 600, 15, WHITE);

            if (continueStep == 0) {
                DrawText("1 / 3", 1075, 600, 16, DARKGRAY);
            }
            else if (continueStep == 1) {
                DrawText("2 / 3", 1075, 600, 16, DARKGRAY);
            }
            else {
                DrawText("3 / 3", 1075, 600, 16, DARKGRAY);
            }
        }

        // Health, Maps, Apple Music, and Shopify screens
        else if (currentScreen >= 2 && currentScreen <= 5) {

            int appIndex = currentScreen - 1; // converting the screen number into the correct array index

            Rectangle sourceInterface = {0, 0, (float)appInterfaces[appIndex].width,(float)appInterfaces[appIndex].height
            };

            // only draw the selected app PNG
            // do not draw Phonephoto here because the PNG has its own phone
            DrawTexturePro(appInterfaces[appIndex], sourceInterface,interfaceDest, {0, 0}, 0.0f, WHITE);

            Rectangle actionButton = {0, 0, 0, 0};

            // set the action button position for each shifted app interface
            if (currentScreen == 2) {actionButton = {414, 521, 321, 114};
            }
            else if (currentScreen == 3) {actionButton = {628, 531, 107, 114};
            }
            else {
                actionButton = {414, 557, 321, 114};
            }

            // show instructions depending on the app
            DrawRectangle(30, 150, 330, 205, WHITE);
            DrawRectangleLines(30, 150, 330, 205, GRAY);

            DrawText("WHAT TO DO", 55, 175, 21, DARKBLUE);

            if (currentScreen == 2) {
                DrawText("Click the Sharing Button.",55, 225, 15, BLACK);
                DrawText("Review what information John", 55, 255, 15, BLACK);
                DrawText("would share, then choose an option.",55, 280, 15, BLACK);
            }
            else if (currentScreen == 3) {
                DrawText("Click the updates button.",55, 225, 15, BLACK);
                DrawText("Review the location history",55, 255, 15, BLACK);
                DrawText("request, then choose an option.",55, 280, 15, BLACK);
            }
            else if (currentScreen == 4) {
                DrawText("Click Share Listening Activity.", 55, 225, 15, BLACK);
                DrawText("Review the listening activity", 55, 255, 15, BLACK);
                DrawText("request, then choose an option.", 55, 280, 15, BLACK);
            }
            else {
                DrawText("Click the arrow beside the setting.", 55, 225, 15, BLACK);
                DrawText("Review the shopping activity", 55, 255, 15, BLACK);
                DrawText("request, then choose an option.",55, 280, 15, BLACK);
            }

            DrawText("Tap the circular home button to return home.", 55, 315, 12, BLACK);

            // click the app action to open its popup
            if (mouseClicked &&CheckCollisionPointRec(mouse, actionButton) &&!appPromptAnswered[appIndex] &&!showAppPrompt[appIndex]) {

                showAppPrompt[appIndex] = true;
            }

            // show the permission popup
            if (showAppPrompt[appIndex]) {

                Rectangle allowButton = {510, 450, 55, 30};
                Rectangle denyButton = {570, 450, 75, 30};

                if (mouseClicked && CheckCollisionPointRec(mouse, allowButton)) {

                    appPromptGranted[appIndex] = true;
                    appPromptAnswered[appIndex] = true;
                    showAppPrompt[appIndex] = false;
                    continueStep = 0;

                    std::cout << apps[appIndex].getAppName()<< ": John allowed the request." << endl;
                }
                else if (mouseClicked && CheckCollisionPointRec(mouse, denyButton)) {

                    appPromptGranted[appIndex] = false;
                    appPromptAnswered[appIndex] = true;
                    showAppPrompt[appIndex] = false;
                    continueStep = 0;

                    std::cout << apps[appIndex].getAppName()<< ": John denied the request." << endl;
                }

                DrawRectangle(490, 320, 170, 180, LIGHTGRAY);
                DrawRectangleLines(490, 320, 170, 180, GRAY);

                // health permission explanation
                if (currentScreen == 2) {
                    DrawText("Share Health Data?", 500, 333, 13, BLACK);
                    DrawText("Share selected activity", 500, 360, 11, BLACK);
                    DrawText("records and heart-rate trends", 500, 378, 10, BLACK);
                    DrawText("with a trusted person?", 500, 396, 11, BLACK);
                    DrawText("This may help monitor John's", 500, 414, 10, DARKGRAY);
                    DrawText("well-being, but is sensitive data.", 500, 430, 9, DARKGRAY);
                }
                else if (currentScreen == 3) {
                    DrawText("Save Location History?", 500, 333, 12, BLACK);
                    DrawText("Save places John visits", 500, 360, 11, BLACK);
                    DrawText("and routes he takes to his", 500, 378, 11, BLACK);
                    DrawText("location history?", 500, 396, 11, BLACK);
                    DrawText("This can help review past trips,", 500, 414, 10, DARKGRAY);
                    DrawText("but may reveal daily routines.", 500, 430, 10, DARKGRAY);
                }
                else if (currentScreen == 4) {
                    DrawText("Share Listening Activity?", 500, 333, 12, BLACK);
                    DrawText("Let selected friends see", 500, 360, 11, BLACK);
                    DrawText("what John listens to?", 500, 378, 11, BLACK);
                    DrawText("Sharing can help friends", 500, 396, 11, DARKGRAY);
                    DrawText("discover music, but may reveal", 500, 414, 10, DARKGRAY);
                    DrawText("personal interests.", 500, 430, 10, DARKGRAY);
                }
                else {
                    DrawText("Shopping Activity?", 500, 333, 13, BLACK);
                    DrawText("Use browsing and purchase", 500, 360, 11, BLACK);
                    DrawText("activity for personalized", 500, 378, 11, BLACK);
                    DrawText("recommendations?", 500, 396, 11, BLACK);
                    DrawText("This may improve suggestions,", 500, 414, 10, DARKGRAY);
                    DrawText("but uses shopping behavior.", 500, 430, 10, DARKGRAY);
                }

                DrawRectangleRec(allowButton, GREEN);
                DrawText("Allow", 517, 458, 12, WHITE);

                DrawRectangleRec(denyButton, RED);
                DrawText("Dont Allow", 572, 458, 10, WHITE);
            }

            // individual app privacy insights panel
            DrawRectangle(800, 150, 550, 500, WHITE);
            DrawRectangleLines(800, 150, 550, 500, GRAY);

            DrawText("Privacy Insights", 830, 175, 28, DARKBLUE);

            if (currentScreen == 2) {
                DrawText("APPLE HEALTH - JOHN DOE", 830, 215, 16, DARKGRAY);
            }
            else if (currentScreen == 3) {
                DrawText("GOOGLE MAPS - JOHN DOE", 830, 215, 16, DARKGRAY);
            }
            else if (currentScreen == 4) {
                DrawText("APPLE MUSIC - JOHN DOE", 830, 215, 16, DARKGRAY);
            }
            else {
                DrawText("SHOPIFY - JOHN DOE", 830, 215, 16, DARKGRAY);
            }

            Rectangle backButton = {830, 590, 100, 35};
            Rectangle nextButton = {1220, 590, 100, 35};

            // navigate through the privacy insights
            if (mouseClicked && !showAppPrompt[appIndex]) {

                if (CheckCollisionPointRec(mouse, backButton) &&
                    continueStep > 0) {
                    continueStep--;
                }
                else if (CheckCollisionPointRec(mouse, nextButton) &&
                         continueStep < 2) {
                    continueStep++;
                }
            }

            // first page: data choice
            if (continueStep == 0) {

                DrawText("01 - DATA CHOICE", 830, 270, 20, DARKBLUE);

                if (!appPromptAnswered[appIndex]) {
                    DrawText("REQUEST: PENDING", 830, 320, 18, ORANGE);
                    DrawText("John has not made a decision yet.",830, 365, 16, BLACK);
                    DrawText("Select the action on the phone", 830, 395, 16, BLACK);
                    DrawText("to review the request.", 830, 420, 16, BLACK);
                }
                else if (appPromptGranted[appIndex]) {
                    DrawText("REQUEST: ALLOWED", 830, 320, 18, GREEN);
                    DrawText("John agreed to the requested",830, 365, 16, BLACK);
                    DrawText("sharing or data-use setting.",830, 390, 16, BLACK);
                }
                else {
                    DrawText("REQUEST: DENIED", 830, 320, 18, RED);
                    DrawText("John chose not to allow this", 830, 365, 16, BLACK);
                    DrawText("sharing or data-use setting.",830, 390, 16, BLACK);
                }
            }

            // second page: possible inferences
            else if (continueStep == 1) {

                DrawText("02 - POSSIBLE INFERENCES", 830, 270, 20, DARKBLUE);

                if (currentScreen == 2) {
                    DrawText("Health information may reveal:", 830, 330, 16, BLACK);
                    DrawText("- Fitness and activity habits", 830, 375, 16, BLACK);
                    DrawText("- Changes in heart-rate patterns",830, 405, 16, BLACK);
                    DrawText("- Daily routines",830, 435, 16, BLACK);
                }
                else if (currentScreen == 3) {
                    DrawText("Location records may reveal:",830, 330, 16, BLACK);
                    DrawText("- Frequently visited places", 830, 375, 16, BLACK);
                    DrawText("- Possible home and work areas",830, 405, 16, BLACK);
                    DrawText("- Daily travel routines", 830, 435, 16, BLACK);
                }
                else if (currentScreen == 4) {
                    DrawText("Listening activity may suggest:", 830, 330, 16, BLACK);
                    DrawText("- Music preferences",830, 375, 16, BLACK);
                    DrawText("- Favorite genres and artists",830, 405, 16, BLACK);
                    DrawText("- Changing listening habits", 830, 435, 16, BLACK);
                }
                else {
                    DrawText("Shopping activity may reveal:", 830, 330, 16, BLACK);
                    DrawText("- Product interests", 830, 375, 16, BLACK);
                    DrawText("- Shopping preferences", 830, 405, 16, BLACK);
                    DrawText("- Potential spending patterns", 830, 435, 16, BLACK);
                }

                if (!appPromptGranted[appIndex]) {
                    DrawText("Denying this request limits this", 830, 490, 15, DARKGRAY);
                    DrawText("specific use of the information.", 830, 515, 15, DARKGRAY);
                }
            }

            // third page: privacy impact
            else if (continueStep == 2) {

                DrawText("03 - PRIVACY IMPACT", 830, 270, 20, DARKBLUE);

                if (currentScreen == 2) {
                    DrawText("POTENTIAL BENEFIT", 830, 330, 18, DARKGREEN);
                    DrawText("A trusted person may help monitor",830, 360, 15, BLACK);
                    DrawText("John's well-being.", 830, 385, 15, BLACK);
                    DrawText("PRIVACY CONSIDERATION", 830, 440, 18, DARKBLUE);
                    DrawText("Health information is sensitive.",830, 470, 15, BLACK);
                    DrawText("John should consider who can", 830, 495, 15, BLACK);
                    DrawText("access the information.",830, 520, 15, BLACK);
                }
                else if (currentScreen == 3) {
                    DrawText("POTENTIAL BENEFIT", 830, 330, 18, DARKGREEN);
                    DrawText("Saved routes can help John review", 830, 360, 15, BLACK);
                    DrawText("past trips and revisit places.",830, 385, 15, BLACK);
                    DrawText("PRIVACY CONSIDERATION", 830, 440, 18, DARKBLUE);
                    DrawText("A location history could expose", 830, 470, 15, BLACK);
                    DrawText("home, work, and daily routines.", 830, 495, 15, BLACK);
                }
                else if (currentScreen == 4) {
                    DrawText("POTENTIAL BENEFIT", 830, 330, 18, DARKGREEN);
                    DrawText("Sharing music can help friends", 830, 360, 15, BLACK);
                    DrawText("discover songs and artists.", 830, 385, 15, BLACK);
                    DrawText("PRIVACY CONSIDERATION", 830, 440, 18, DARKBLUE);
                    DrawText("Listening patterns can reveal",830, 470, 15, BLACK);
                    DrawText("personal interests and habits.", 830, 495, 15, BLACK);
                }
                else {
                    DrawText("POTENTIAL BENEFIT", 830, 330, 18, DARKGREEN);
                    DrawText("Personalized recommendations can",830, 360, 15, BLACK);
                    DrawText("make shopping more relevant.", 830, 385, 15, BLACK);
                    DrawText("PRIVACY CONSIDERATION", 830, 440, 18, DARKBLUE);
                    DrawText("Shopping activity can reveal",830, 470, 15, BLACK);
                    DrawText("interests and buying habits.", 830, 495, 15, BLACK);
                }

                if (!appPromptGranted[appIndex]) {
                    DrawText("John declined this specific request.", 830, 550, 14, DARKGRAY);
                }
            }

            // draw the navigation controls
            DrawRectangleRec(backButton, LIGHTGRAY);
            DrawText("BACK", 855, 600, 15, BLACK);

            DrawRectangleRec(nextButton, BLUE);
            DrawText("NEXT", 1248, 600, 15, WHITE);

            if (continueStep == 0) {
                DrawText("1 / 3", 1075, 600, 16, DARKGRAY);
            }
            else if (continueStep == 1) {
                DrawText("2 / 3", 1075, 600, 16, DARKGRAY);
            }
            else {
                DrawText("3 / 3", 1075, 600, 16, DARKGRAY);
            }
        }

        // final reflection screen
        else if (currentScreen == 6) {

            ClearBackground(RAYWHITE);

            DrawText("FINAL REFLECTION", 40, 35, 32, DARKBLUE);
            DrawText("JOHN DOE'S DIGITAL FOOTPRINT",40, 80, 17, DARKGRAY);

            // first panel: what John's data could reveal
            DrawRectangle(40, 140, 420, 410, WHITE);
            DrawRectangleLines(40, 140, 420, 410, GRAY);

            DrawText("WHAT COULD HIS DATA REVEAL?",65, 165, 19, DARKBLUE);

            int reflectionY = 215;

            if (appUsed[0]) {
                DrawText("Instagram", 65, reflectionY, 15, DARKBLUE);
                DrawText("Interests and social connections", 180, reflectionY, 14, BLACK);
                reflectionY += 55;
            }

            if (appUsed[1]) {
                DrawText("Apple Health", 65, reflectionY, 15, DARKBLUE);
                DrawText("Activity habits and health patterns", 180, reflectionY, 14, BLACK);
                reflectionY += 55;
            }

            if (appUsed[2]) {
                DrawText("Google Maps", 65, reflectionY, 15, DARKBLUE);
                DrawText("Frequently visited places and routines",180, reflectionY, 14, BLACK);
                reflectionY += 55;
            }

            if (appUsed[3]) {
                DrawText("Apple Music", 65, reflectionY, 15, DARKBLUE);
                DrawText("Music preferences and interests", 180, reflectionY, 14, BLACK);
                reflectionY += 55;
            }

            if (appUsed[4]) {
                DrawText("Shopify", 65, reflectionY, 15, DARKBLUE);
                DrawText("Shopping habits and buying patterns",180, reflectionY, 14, BLACK);
            }

            // second panel: benefits of collecting data
            DrawRectangle(490, 140, 400, 410, WHITE);
            DrawRectangleLines(490, 140, 400, 410, GRAY);

            DrawText("POTENTIAL BENEFITS", 515, 165, 19, DARKGREEN);

            DrawText("Personalized recommendations",515, 220, 16, BLACK);
            DrawText("Apps can suggest content, music,",515, 250, 14, DARKGRAY);
            DrawText("and products based on preferences.",515, 272, 14, DARKGRAY);

            DrawText("Health and activity insights", 515, 320, 16, BLACK);
            DrawText("Activity records can help people", 515, 350, 14, DARKGRAY);
            DrawText("understand their habits.",515, 372, 14, DARKGRAY);

            DrawText("Convenience and useful features",515, 420, 16, BLACK);
            DrawText("Location history, saved routes, and", 515, 450, 14, DARKGRAY);
            DrawText("music sharing can make apps easier",515, 472, 14, DARKGRAY);
            DrawText("to use.", 515, 494, 14, DARKGRAY);

            // third panel: privacy risks
            DrawRectangle(920, 140, 440, 410, WHITE);
            DrawRectangleLines(920, 140, 440, 410, GRAY);

            DrawText("POTENTIAL PRIVACY RISKS", 945, 165, 19, DARKBLUE);

            DrawText("Detailed personal profiles",945, 220, 16, BLACK);
            DrawText("Combining data can reveal interests,",945, 250, 14, DARKGRAY);
            DrawText("routines, and behavior.",945, 272, 14, DARKGRAY);

            DrawText("Exposure of sensitive information",945, 320, 16, BLACK);
            DrawText("Health records and location history", 945, 350, 14, DARKGRAY);
            DrawText("can expose personal details.", 945, 372, 14, DARKGRAY);

            DrawText("Targeted advertising and sharing", 945, 420, 16, BLACK);
            DrawText("Companies may use collected data", 945, 450, 14, DARKGRAY);
            DrawText("to target users or share information", 945, 472, 14, DARKGRAY);
            DrawText("with other parties.", 945, 494, 14, DARKGRAY);


            // final message about the overall digital footprint
            DrawRectangle(40, 580, 1320, 125, WHITE);
            DrawRectangleLines(40, 580, 1320, 125, GRAY);

            DrawText("THE BIGGER PICTURE", 65, 600, 19, DARKBLUE);

            DrawText("Each app may only collect a piece of information, but combining those pieces",65, 635, 16, BLACK);
            DrawText("can create a much broader picture of a person's life. Data collection can be useful,",65, 658, 16, BLACK);
            DrawText("but users should understand what they share and companies should handle it responsibly.",65, 681, 16, BLACK);

            // small note about the visual presentation
            DrawText("P.S. Sorry about the font and visual quality.",1100, 25, 13, DARKGRAY);

            // return to the phone
            Rectangle backToPhoneButton = {1100, 665, 220, 40};

            DrawRectangleRec(backToPhoneButton, DARKBLUE);
            DrawText("BACK TO PHONE", 1135, 687, 16, WHITE);

            if (mouseClicked &&CheckCollisionPointRec(mouse, backToPhoneButton)) {

                currentScreen = 0;
            }

        }

        // this checks if John clicked the circular home button
        // only app screens use this button, not the final reflection
        if (currentScreen >= 1 && currentScreen <= 5 &&
            mouseClicked &&
            CheckCollisionPointRec(mouse, homeButton)) {

            showLocationPrompt = false;

            for (int i = 0; i < 5; i++) {
                showAppPrompt[i] = false;
            }

            continueStep = 0;
            currentScreen = 0;
        }

        EndDrawing();
    }

    // unload the phone image
    UnloadTexture(Phonephoto);

    // unload all app icons and interfaces
    for (int i = 0; i < 5; i++) {
        UnloadTexture(appIcons[i]);
        UnloadTexture(appInterfaces[i]);
    }

    CloseWindow();

    // this is where I put together the information from all the apps
    int appsOpened = 0;
    string combinedProfile = "";

    for (int i = 0; i < 5; i++) {

        if (appUsed[i] == true) {

            std::cout << "\n---- " << apps[i].getAppName() << " -----" << endl;

            std::cout << "\n---- Information Collected: "<< apps[i].getInformationCollected() << " -----" << endl;

            std::cout << "\n---- Possible Inferences: "<< apps[i].getPossibleInference() << " -----" << endl;

            // combine the possible inferences from each app
            combinedProfile += apps[i].getPossibleInference();
            combinedProfile += ". ";

            appsOpened++;
        }
    }

    // show the final profile depending on how many apps were opened
    if (appsOpened == 0) {
        std::cout << "Final Insights: John did not open any apps." << endl;
    }
    else if (appsOpened == 1) {
        std::cout << "Final Insights: John opened one app. "<< combinedProfile << " These are possible inferences, not confirmed facts."<< endl;
    }
    else {
        std::cout << "Final Insights: John opened multiple apps. "<< "Combining separate signals could create a broader profile: "<< combinedProfile<< "These are possible inferences, not confirmed facts."<< endl;
    }

    std::cout << endl;

    return 0;
}

// CITATIONS:

// CITATION: Chagpt helped us understand why cout was ambiguous with raylib. I think it was because of the raylib header, but basicaly gpt said to use std:: in from of cout to get rid of the error
// CITATION: app images were found on the web, and App interfaces were generated with ChatGPT.
// CITATION: Chatgpt helped troubleshoot the Codespaces Fluxbox connection issue. Disabling browser extensions fixed the connection problem.
// CITATION: Chatgpt helped us with the final reflection layout - with the rectangles and sqaures.