
//  Created by Mohammed Ahmed on 05/02/2021.
//

//get x and y value of floor. Add width of floor to the pos.x. Use conditional statemetn to check if the cat  pos.x == floor.pos.x

#include "CatFiles.hpp"

Cat::Cat(){
    timer=0;
    pos.x=200,
    posision.x=0;
    posision.y=0;
    posision.z=-50;
    pos.y=ofGetHeight()/2;
    ofDisableAlphaBlending();
    ofEnableDepthTest();
    ofDisableArbTex();
    ofDisableAlphaBlending();
    light.enable();
    light.setPosition(ofGetWidth()/2, 50, 200);
    
    ofLoadImage(texture, "cat.jpg");
    ofLoadImage(texture1, "eggcrack.jpg");
    ofLoadImage(texture2, "eggcrack1.jpg");
    ofLoadImage(texture3, "eggcrack2.jpg");
    ofLoadImage(texture4, "eggcrack3.jpg");
    ofLoadImage(texture5, "eggcrack4.jpg");
    head.setRadius(70);
    
    
    
    
    

}

void Cat::menuScene(){
    if(ofGetMouseX()<=ofGetWidth()/2){
        pos.x=ofGetMouseX();
    }
    head.setPosition(pos.x, pos.y, 0);
    ofPushMatrix();
    texture.bind();
    head.draw();
  
    texture.unbind();
    ofPopMatrix();

    

    
}

void Cat ::eggHatchScene(){
    ofDrawBitmapString("Give me a sec whilst i break out of HEREEEEEE!!!", ofGetWidth()/2, 20);
    timer+=0.1;
    
    if(timer <=5){
        texture1.bind();
    }
    if(timer >=5&&timer<=10){
        texture2.bind();
    }
    if(timer >=10&&timer<=15){
        texture3.bind();
    }
    if(timer >=15&&timer<=20){
        texture4.bind();
    }
    if(timer >=20){
        cam.setDistance(200);
        texture5.bind();
        
    }
    
    head1.draw();
    texture1.unbind();
    texture2.unbind();
    texture3.unbind();
 

    
}

void Cat::game(){
    head.setRadius(10);
    head.setPosition(posision.x, posision.y, posision.z);
    texture.bind();
//    if(myCatHealth.AnimalHealth<=4){
//        ofFill();
//        ofSetColor(255, 0, 0);
//    }
//    if(myCatHealth.AnimalHealth>=4){
//        ofFill();
//        ofSetColor(0, 255, 0);
//    }
    head.draw();
    texture.unbind();

    
}


