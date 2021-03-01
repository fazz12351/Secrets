//
//  CatFiles.hpp
//  CreativeProjFinal
//
//  Created by Mohammed Ahmed on 05/02/2021.
//

#ifndef CatFiles_hpp
#define CatFiles_hpp

#include <stdio.h>
#include "ofMain.h"



#endif /* CatFiles_hpp */

class Cat {
public:
    Cat();
    void setup();
    void update();
    void menuScene();
    void eggHatchScene();
    void game();
    float timer;
    ofVec3f pos;
    ofVec3f posision;
    bool cameraView;
private:
    ofSpherePrimitive head,head1;
    ofTexture texture,texture1,texture2,texture3,texture4,texture5;
    ofEasyCam cam;
    ofLight light;
//    Health myCatHealth;
    
    
    
};

