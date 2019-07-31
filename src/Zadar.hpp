//
//  Zadar.hpp
//  Zadar
//
//  Created by Enrico Becker on 30/07/2019.
//
//

#ifndef Zadar_hpp
#define Zadar_hpp

#include <stdio.h>
#include "ofMain.h"

#define RES 100

class Zadar
{
public:
    enum CURVES
    {
        RECT = 0,
        PWM,
        SAW,
        TRI,
        HALFSINE,
        ADSR,
        END
    };
    
    //inverse
    //reverse
    //morph?
    
    
    Zadar();
    Zadar(ofRectangle drawarea);
    ~Zadar();
    
    void setup(ofRectangle drawarea);
    void update();
    void update(float &dt);
    void draw();
    
    void setCurve(int id);
    float &getValue(){return out;};
    
private:
    void createCurves();
    
    ofRectangle         drawarea;
    ofFbo               preview;
    int                 curveID;
    float               dT;
    float               out;
    vector<ofPolyline>  curves;
    bool                inverse;
    bool                reverse;
};

#endif /* Zadar_hpp */
