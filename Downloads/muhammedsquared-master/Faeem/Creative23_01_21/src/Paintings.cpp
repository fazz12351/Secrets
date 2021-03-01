//
//  Paintings.cpp
//  teapotScene
//
//  Created by Mohammed Ahmed on 15/02/2021.
//

#include "Paintings.hpp"


Painting::Painting(){
    Frame.setPosition(30, 0,0);
    Frame.setDepth(4);
    Frame.setWidth(50);
    
    
    Frame1.setPosition(-90, 0,0);
    Frame1.setDepth(4);
    Frame1.setWidth(50);
    
    
    Frame2.setPosition(-125, 0,-60);
    Frame2.setDepth(50);
    Frame2.setWidth(4);
    
    Frame3.setPosition(-125, 0,-140);
    Frame3.setDepth(50);
    Frame3.setWidth(4);
    
    Frame4.setPosition(-125, 0,-220);
    Frame4.setDepth(50);
    Frame4.setWidth(4);
    
    Frame5.setPosition(30, 0,-275);
    Frame5.setDepth(4);
    Frame5.setWidth(50);
    
    Frame6.setPosition(-90, 0,-275);
    Frame6.setDepth(4);
    Frame6.setWidth(50);
    
    
    
    Frame7.setPosition(80, 0,-60);
    Frame7.setDepth(50);
    Frame7.setWidth(4);
    
    
    Frame8.setPosition(80, 0,-140);
    Frame8.setDepth(50);
    Frame8.setWidth(4);
    
    Frame9.setPosition(80, 0,-220);
    Frame9.setDepth(50);
    Frame9.setWidth(4);
    
    ofLoadImage(texture, "Mona.jpg");
    ofLoadImage(texture1, "Mona1.jpg");
    ofLoadImage(texture2, "Mona2.jpg");
    ofLoadImage(texture3, "Mona3.jpg");
    ofLoadImage(texture4, "Mona4.jpg");
    ofLoadImage(texture5, "Mona5.jpg");
    ofLoadImage(texture6, "Mona6.jpg");
    ofLoadImage(texture7, "Mona7.jpg");
    ofLoadImage(texture7, "Mona8.jpg");
    ofLoadImage(door, "door.jpg");
    
}


void Painting::draw(){
    texture.bind();
    Frame.draw();
    texture.unbind();
    
    texture1.bind();
    Frame1.draw();
    texture1.unbind();
    
    texture2.bind();
    Frame2.draw();
    texture2.unbind();
    
    texture3.bind();
    Frame3.draw();
    texture3.unbind();
    
    texture4.bind();
    Frame4.draw();
    texture4.unbind();
    
    texture5.bind();
    Frame5.draw();
    texture5.unbind();
    
    texture6.bind();
    Frame6.draw();
    texture6.unbind();

    texture7.bind();
    Frame7.draw();
    texture7.unbind();
    
    texture8.bind();
    Frame8.draw();
    texture8.unbind();
    
    door.bind();
    Frame9.draw();
    door.unbind();
}
