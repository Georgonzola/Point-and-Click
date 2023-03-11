#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "ScreenEntity.h"
#include "Screen.h"
#include "Menu.h"
#include "Map.h"
#include "Items.h"
using std::cout;
using std::endl;

int SCR_WIDTH = 700;
int SCR_HEIGHT = 600;

bool clicked = false;

double mousex;
double mousey;

int winW;
int winH;

//https://www.glfw.org/docs/3.3/window_guide.html#window_scale


class GlWindow {
public:

    GLFWwindow* window;
//Processes Mouse Input
    void processMouse(GLFWwindow* window, Menu& options, Map& map, Items& inventory, Player& player) {

        if ((glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) && clicked == false) {
            options.checkClick(mousex,mousey,map,inventory, player);
        };
    
    
    };
//Processes Hover
    void processHovers(GLFWwindow* window, Menu& options) {
        options.checkHover(mousex, mousey);
    }

//Processes Key Input
   void processKey(GLFWwindow* window) {

   

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && clicked == false) {
            //cout << mousex << " : " << mousey << endl;
            clicked = true;
        }

        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
            clicked = false;
        }

    };

//Creates Window
    int makeWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "VibeoGane", NULL, NULL);////////////////////////WINDOW SIZE AND NAME
        //glfwSetWindowUserPointer(window, static_cast<void*>(this));

        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window);

        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        glfwSetCursorPosCallback(window, cursorPositionCallback);//////////////////////////READ MOUSE POSITION
  
        glfwSetWindowAspectRatio(window, SCR_WIDTH, SCR_HEIGHT);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        };
 };


 

 

private:
 
   //retrieves window size for resizing image coordinates
   static void framebuffer_size_callback(GLFWwindow* window, int width, int height) ///FrameBuffer Window Resize
   {
       glViewport(0, 0, width, height);
       winW = width;
       winH = height;
   }
   //retrieves user mouse position
static void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos) //Mouse Position Reader
{
    if (winW > 0) {
      mousex = 2 * xPos / winW - 1;
    }
    else {
        mousex = 2 * xPos / SCR_WIDTH - 1;
    }

    if (winH > 0) {
        mousey = -2 * yPos / winH + 1;
    }
    else {
        mousey = -2 * yPos / SCR_HEIGHT + 1;
    }
}


};

