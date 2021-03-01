
#pragma once

#include "ofMain.h"
#include "Paintings.hpp"
#include "Globe.hpp"
#include "CatFiles.hpp"
#include "HealthBar.hpp"

using namespace glm;

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    void TeapotAndPedestalSetup();
    void TeapotAndPedestalDraw();
    void CameraAndLightingSetup();
    void addQuadFacet(ofMesh &curMesh, vec3 v0, vec3 v1, vec3 v2, vec3 v3, vec2 tMin, vec2 tMax);
    void StartGame();
    
    ofEasyCam camera;
    ofLight keyLight;
    ofVboMesh teapotMesh,teapotMesh1;
    ofVboMesh createCuboidMesh(float width, float height);
    ofVboMesh pedestaMesh,pedestaMesh1;
    ofMaterial pedestaMaterial,pedestaMaterial1;
    ofImage woodTexture;
    ofMaterial teapotMaterial,teapotMaterial1;
    ofLight light;
    ofTexture texture;
    
    ofBoxPrimitive floor;
    //class being called
    Painting myPaint;
    Globe myGlobe;
    Cat myCat;
    Health pethealth;
    
    ofSoundPlayer intro;
    
    
    bool interact;
    bool roomlight;
    bool petinteraction;
    
    int SceneCounter;
    int red,green,blue;
    
    float number1,number2;
    int rotateGlobe;
 

    
        
};
