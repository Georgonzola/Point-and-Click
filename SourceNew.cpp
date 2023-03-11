#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Texture.h"
#include "Window.h"
#include "ScreenEntity.h"
#include "Screen.h"
#include "Menu.h"
#include "Map.h"
#include "Items.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"

using std::cout;
using std::endl;

//GLAD setup
//https://youtu.be/7-dL6a5_B3I

//Learn OpenGL
//https://learnopengl.com/book/book_pdf.pdf

//Font
//https://www.dafont.com/alagard.font




int main(void)
{

    //Create Class Objects
    
    Map GameMap(1, 3, 1);
    Items Inventory;


    GlWindow GameWindow;
    GameWindow.makeWindow();
    Menu menu;
    Screen GameScreen;
  /*
    Inventory.SetKey(0);
    Inventory.SetKey(1);
    Inventory.SetKey(2);
    Inventory.SetKey(3);
    Inventory.SetKey(4);
    Inventory.SetKey(5);
    Inventory.SetKey(6);
*/



    Player Man(100, 20, 8, 0, 0);
    Enemy Steph(60, 20, 7, "Stephen", 100, 0);

    //GameMap.battle(Man, Steph);

    GameMap.RunRoom(Inventory, Man);



    //GameScreen.items[0].setData("Sky", -0.5f, 0.5f, 1.0f, 0.0f, "sky.png");
    //GameScreen.items[1].setData("Container", 0.0f, 1.0f, 0.0f, -1.0f, "Container.png");
    //GameScreen.items[2].setData("Tim", -1.0f, 0.0f, 0.0f, -1.0f, "Tim.png");

    GameScreen.items[0].setData("Menu", 0, 350, 0, 300, "Images/MenuTemp.png");







    //Main game/drawing loop

    while (!glfwWindowShouldClose(GameWindow.window))
    {

        //checks whether text had aleady been printed to the screen
        if (GameMap.getPrinted() == false) {
            GameMap.RunRoom(Inventory, Man);
            GameMap.setPrinted(true);
        };

        //Processes user input
        GameWindow.processMouse(GameWindow.window, menu, GameMap, Inventory, Man);
        GameWindow.processKey(GameWindow.window);


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //////////BACKGROUND COLOUR 
        glClear(GL_COLOR_BUFFER_BIT);

        //Draws the Menu
        GameScreen.drawEntities();

        //Checks whther the mouse is hovering over menu sections
        menu.checkHover(mousex, mousey);

        //Draw Non-menu area section
        GameMap.DrawRoom();



        glfwSwapBuffers(GameWindow.window);
        glfwPollEvents();
    }
    //Deletes Entities
    GameScreen.deleteEntities();

    glfwTerminate();
    return 0;


}
