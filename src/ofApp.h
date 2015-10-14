#pragma once

#include "ofMain.h"
#include "GuiApp.h"
#include "BaseArch.h"


struct Particle {
    
    ofPolyline pathPolyLine;
    float movingFactor = 0;
    float movingSpeed = ofRandom(0.1, 0.6) * 0.005;
    float direction = 1;
    int size = ofRandom(2, 5);
    
};



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
    
    BaseArch baseArch;
    shared_ptr<GuiApp> gui;

    float mainOffSetXPos, mainOffSetYPos;

    
    void initParticles();
    
    void drawParticles();
    
    vector<Particle> particles;
    
    
		
};
