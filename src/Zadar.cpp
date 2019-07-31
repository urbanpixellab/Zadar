//
//  Zadar.cpp
//  Zadar
//
//  Created by Enrico Becker on 30/07/2019.
//
//

#include "Zadar.hpp"

Zadar::Zadar(){}

Zadar::Zadar(ofRectangle area)
{
    drawarea = area;
    preview.allocate(area.getWidth(),area.getHeight());
    createCurves();
}

Zadar::~Zadar(){}

void Zadar::setup(ofRectangle area)
{
    drawarea = area;
    preview.allocate(area.getWidth(),area.getHeight());
    createCurves();
}

void Zadar::update()
{
    
}

void Zadar::update(float &dt)
{
    
}

void Zadar::draw()
{
    ofSetColor(255);
    preview.draw(drawarea.x,drawarea.y);
}

void Zadar::setCurve(int id)
{
    ofSetLineWidth(3);
    curveID = id;
    ofSetColor(255);
    preview.begin();
    ofClear(0,0,0);
    ofPushMatrix();
    ofTranslate(0,200);
    ofScale(200,-200);
    curves[curveID].draw();
    ofPopMatrix();
    preview.end();
    ofSetLineWidth(1);
}

void Zadar::createCurves()
{
    curves.clear();
    //rect
    ofPolyline rect;
    rect.addVertex(0, 1);
    rect.addVertex(1, 1);
    curves.push_back(rect);
    //pwm
    ofPolyline pwm;
    pwm.addVertex(0, 1);
    pwm.addVertex(0.5, 1);
    pwm.addVertex(0.5000001, 0);
    pwm.addVertex(1, 0);
    curves.push_back(pwm);
    //saw
    ofPolyline saw;
    saw.addVertex(0, 1);
    saw.addVertex(1, 0);
    curves.push_back(saw);
    //triangle
    ofPolyline tri;
    tri.addVertex(0, 0);
    tri.addVertex(0.5, 1);
    tri.addVertex(1, 0);
    curves.push_back(tri);
    //halfsine
    ofPolyline halfSine;
    for (int i = 0; i < RES+1; i++)
    {
        halfSine.addVertex(i/float(RES), sin(i/float(RES)*PI));
    }
    curves.push_back(halfSine);
    //adsr
    ofPolyline adsr;
    adsr.addVertex(0,0);
    adsr.addVertex(0.1,1);
    adsr.addVertex(0.4,0.5);
    adsr.addVertex(0.8,0.5);
    adsr.addVertex(1,0);
    curves.push_back(adsr);
    
    
    setCurve(4);

}