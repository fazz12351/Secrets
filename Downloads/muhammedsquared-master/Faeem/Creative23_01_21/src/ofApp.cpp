
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    intro.load("tamagotchi.mp3");
    intro.setVolume(0.6);
    intro.play();
    intro.setLoop(true);
    
    teapotMesh.load("teapot.ply");
    teapotMesh1.load("teapot.ply");
    ofLoadImage(texture, "floor.jpg");
    
    floor.setPosition(0, -70, -95);
    floor.setDepth(270);
    floor.setHeight(5);
    floor.setWidth(200);
    
    ofSetBackgroundColor(0);
    camera.setDistance(1);
    CameraAndLightingSetup();
    TeapotAndPedestalSetup();
    
    interact=false;
    roomlight=false;
    petinteraction=false;
    SceneCounter =0;

  
    
    
  
    

}

//--------------------------------------------------------------
void ofApp::update(){
//    //this will show the light on the cameraview;
    if(roomlight==true){
        ofVec3f cpos = camera.getPosition();
        ofVec3f lpos=light.getPosition();
        ofVec3f delta=cpos-lpos;
        ofVec3f fin(100,100,100);
      
        if(delta.length()>5){
            light.setPosition(lpos+delta/fin);
                
        }

    }
    
    if(roomlight==false){
        light.setPosition(0, 0, 0);
        
    }
    //we call the health class update function.
    
    pethealth.update();
    

    
        
    
    

    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(SceneCounter == 0){
        myCat.menuScene();
        
    }
    if(SceneCounter == 1){
        ofPushMatrix();
        intro.setVolume(0.05);
        camera.begin();
        camera.setDistance(0);
        camera.setDistance(100);
        myCat.eggHatchScene();
        camera.end();
        ofPopMatrix();
        if(myCat.timer>=25){
            SceneCounter= 2;
        }
    
    }
    
    if(SceneCounter==2){
        pethealth.draw();
        StartGame();
    }
    
 
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r'){
        interact = true;
        pethealth.petinteract=true;
    }

    
    if(key == 't'){
        interact = false;
    }
    
    if(key == OF_KEY_UP){
        roomlight=true;

    }

    if(key == OF_KEY_DOWN){
        roomlight=false;
    }
    
    if(SceneCounter == 2){
        if(key == 'a'){
            myCat.posision.x+=5;
            pethealth.petinteract=true;
 
        
            
        }
        if(key == 'd'){
            myCat.posision.x-=5;
            pethealth.petinteract=true;
          
            
        }
        if(key == 'w'){
            myCat.posision.z+=5;
            pethealth.petinteract=true;
  
            
        }
        if(key == 's'){
            myCat.posision.z-=5;
            pethealth.petinteract=true;
        }
        
    }

    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(SceneCounter == 2){
        if(key == 'a'){

            pethealth.petinteract=false;
 
        
            
        }
        if(key == 'd'){
            pethealth.petinteract=false;
          
            
        }
        if(key == 'w'){

            pethealth.petinteract=false;
  
            
        }
        if(key == 's'){
            pethealth.petinteract=false;
        }
        
    }


    
 



}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
 

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(SceneCounter==0){
        if(ofGetMouseX()<=ofGetWidth()/2-60&&ofGetMouseY()>=326&&ofGetMouseY()<=442){
            SceneCounter=1;
        }

    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

void ofApp::addQuadFacet(ofMesh &curMesh, vec3 v0, vec3 v1, vec3 v2, vec3 v3, vec2 tMin, vec2 tMax) {
    // Adds a quadrilateral facet based on positions of the 4 vertex positions and min and max
    // values for the texture coordinates. Automatically calculates the normal based on a CCW winding
    // order for the vertex positions.

    int baseIndex = curMesh.getNumVertices();

    curMesh.addVertex(v0);
    curMesh.addVertex(v1);
    curMesh.addVertex(v2);
    curMesh.addVertex(v3);

    vec3 n = normalize(cross(v1 - v0, v3 - v0));
    curMesh.addNormal(n);
    curMesh.addNormal(n);
    curMesh.addNormal(n);
    curMesh.addNormal(n);

    curMesh.addTexCoord(vec2(tMin.x, tMin.y));
    curMesh.addTexCoord(vec2(tMax.x, tMin.y));
    curMesh.addTexCoord(vec2(tMax.x, tMax.y));
    curMesh.addTexCoord(vec2(tMin.x, tMax.y));

    curMesh.addTriangle(baseIndex, baseIndex + 1, baseIndex + 2);
    curMesh.addTriangle(baseIndex, baseIndex + 2, baseIndex + 3);
}




ofVboMesh ofApp::createCuboidMesh(float width, float height) {
    ofVboMesh curMesh;

    curMesh.setMode(OF_PRIMITIVE_TRIANGLES);

    // Pedestal width and height values
    const float w = 0.5f * width;
    const float h = height;

    // Facets for the 4 sides
    addQuadFacet(curMesh, vec3(-w, 0, w), vec3(w, 0, w), vec3(w, h, w), vec3(-w, h, w), vec2(0.0, 0.0), vec2(0.25, 1.0));
    addQuadFacet(curMesh, vec3(w, 0, w), vec3(w, 0, -w), vec3(w, h, -w), vec3(w, h, w), vec2(0.25, 0.0), vec2(0.5, 1.0));
    addQuadFacet(curMesh, vec3(w, 0, -w), vec3(-w, 0, -w), vec3(-w, h, -w), vec3(w, h, -w), vec2(0.5, 0.0), vec2(0.75, 1.0));
    addQuadFacet(curMesh, vec3(-w, 0, -w), vec3(-w, 0, w), vec3(-w, h, w), vec3(-w, h, -w), vec2(0.75, 0.0), vec2(1.0, 1.0));

    // Facet for the top
    addQuadFacet(curMesh, vec3(-w, h, w), vec3(w, h, w), vec3(w, h, -w), vec3(-w, h, -w), vec2(0.0, 0.0), vec2(0.25, 0.25));

    // Facet for the bottom
    addQuadFacet(curMesh, vec3(-w, 0, w), vec3(-w, 0, -w), vec3(w, 0, -w), vec3(w, 0, w), vec2(0.25, 0.25), vec2(0.5, 0.5));

    return curMesh;
}

void ofApp::TeapotAndPedestalSetup(){
    //teapot initialize
    teapotMaterial.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
    teapotMaterial.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
    teapotMaterial.setShininess(50.0);
    teapotMaterial.setAmbientColor(ofFloatColor(0.4, 0.4, 0.4));
    
    
  
    //pedesta material setup
    
    pedestaMesh=createCuboidMesh(16,50);
    pedestaMaterial.setSpecularColor(ofFloatColor(0.3,0.3,0.3));
    pedestaMaterial.setShininess(10.0);
    ofEnableNormalizedTexCoords();
    woodTexture.load("woodTexA.jpg");
    
    
    //pedesta material setup
    
    pedestaMesh1=createCuboidMesh(16,50);
    pedestaMaterial1.setSpecularColor(ofFloatColor(0.3,0.3,0.3));
    pedestaMaterial1.setShininess(10.0);
    ofEnableNormalizedTexCoords();
    woodTexture.load("woodTexA.jpg");
    
}


void ofApp::TeapotAndPedestalDraw(){
    //First Teapot
    ofTranslate(0,-60);
    ofPushMatrix();
    ofTranslate(-50, 60);
    teapotMaterial.begin();
    teapotMesh.draw();
    teapotMaterial.end();
    ofPopMatrix();
    
    //teapot stand
    ofPushMatrix();
    ofTranslate(-50, 0);
    woodTexture.bind();
    pedestaMaterial.begin();
    pedestaMesh.draw();
    pedestaMaterial.end();
    woodTexture.unbind();
    ofPopMatrix();
    
    

    
    for(int i=0;i<20;i++){
        ofPushMatrix();
        ofTranslate(30+i, 0+i,0);
        woodTexture.bind();
        pedestaMaterial1.begin();
        pedestaMesh1.draw();
        pedestaMaterial1.end();
        woodTexture.unbind();
        ofPopMatrix();
        
    }

    
    
}

void ofApp::CameraAndLightingSetup(){
    camera.setPosition(vec3(20.0, 70.0, 140.0));
    camera.setTarget(vec3(0.0, 0.0, 0.0));
    camera.setFov(35.0);
    camera.setAutoDistance(false);
    camera.setDistance(100);
    
    light.enable();
    light.setPosition(0, 00, 0);
    
    
    //lights setup
    keyLight.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
    keyLight.setSpecularColor(keyLight.getDiffuseColor());
    keyLight.setPosition(vec3(120.0, 100.0, 120.0));
    
}

void ofApp::StartGame(){
    ofColor colorOne(7);
    ofColor colorTwo(0);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
    
    ofSetColor(255,255,255);
    ofDrawBitmapString(": Use Up and Down Arrows to turn on and off light, Press r to rotate Globe and t to stop", ofGetWidth()/2-210, 20);
    ofDrawBitmapString(": Double click mouse to get a first person view of painting and objects", ofGetWidth()/2-210, 40);
    
    ofDrawBitmapString(": Use letters A,S,W and D to interact with PET", ofGetWidth()/2-210, 60);

    
    //we enable camera interation here
    ofEnableDepthTest();
    camera.begin();
    ofEnableLighting();
   
    
    
    //we draw our floor here, i did not use aa class as its a simple 3d primitive being used.
    texture.bind();
    floor.draw();
    texture.unbind();
    
    //to keep the code clean, i created a fuction which will be called in draw. This function has ann the code for the Tepot and Pedestal
    TeapotAndPedestalDraw();
    
//we draw our painting using our pain class.
    ofPushMatrix();
    ofTranslate(30, 60,60);
    myPaint.draw();
    ofPopMatrix();
    
    //we draw our globe here, we centre it ontop of our second parting.
    ofPushMatrix();
    ofTranslate(50, 83,0);
    if(interact == true){
        rotateGlobe-=1;
        ofRotateYDeg(rotateGlobe);
    }
    myGlobe.draw();
    ofPopMatrix();
    
    //we draw our cat here
    ofPushMatrix();
    if(pethealth.AnimalHealth>=20){
        ofFill;
        ofSetColor(0, 255, 0);
    };
    if(pethealth.AnimalHealth<=20){
        ofFill;
        ofSetColor(255, 0, 0);
    };
    myCat.game();
    ofPopMatrix();
    
    
    
    //we close our camera activity.
    ofDisableLighting();
    camera.end();
}
