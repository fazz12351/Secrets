//
//  Globe.cpp
//  teapotScene
//
//  Created by Mohammed Ahmed on 16/02/2021.
//

#include "Globe.hpp"


Globe::Globe(){
    ofDisableAlphaBlending();
    skeleton.setPosition(0, 0, 0);
    skeleton.setRadius(15);
    ofDisableArbTex();
    ofLoadImage(texture, "earth2.png");
    light.enable();
    light.setPosition(0, 0, 0);
    light.lookAt(ofVec3f(0,0,0));

}



void Globe::draw(){
    texture.bind();
    skeleton.draw();
    texture.unbind();
}
