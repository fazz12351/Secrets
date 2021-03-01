//
//  Globe.hpp
//  teapotScene
//
//  Created by Mohammed Ahmed on 16/02/2021.
//

#ifndef Globe_hpp
#define Globe_hpp

#include "ofMain.h"
#include <stdio.h>


#endif /* Globe_hpp */


class Globe{
public:
    Globe();
    void draw();
    void update();
    ofLight light;
    ofTexture texture;
private:
    ofSpherePrimitive skeleton;

    
    
};
