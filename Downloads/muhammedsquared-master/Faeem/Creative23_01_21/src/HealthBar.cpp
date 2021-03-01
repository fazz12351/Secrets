//
//  HealthBar.cpp
//  teapotScene
//
//  Created by Mohammed Ahmed on 17/02/2021.
//

#include "HealthBar.hpp"

Health::Health(){
    AnimalHealth=0;
    petinteract=false;


}

void Health::update(){
    if(petinteract==true){
        AnimalHealth+=1;
    }
    if(petinteract==false){
        AnimalHealth-=0.0001;
    }
    
    
}

void Health::draw(){
    for(int i=0;i<AnimalHealth;i++){
        ofFill();
        ofSetColor(0,255,100);
        ofDrawEllipse(ofGetWidth()/2-100+i, 100, 20, 20);
    }
    
    
}

