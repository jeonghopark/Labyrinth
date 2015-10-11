#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate( 60 );
    ofBackground( 0 );
    
    ofEnableAlphaBlending();
    //    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    
    mainOffSetXPos = (ofGetWidth() - (baseArch.fassadeCorner[0].x + baseArch.fassadeCorner[1].x)) * 0.5;
    mainOffSetYPos = (ofGetHeight() - (baseArch.fassadeCorner[0].y + baseArch.fassadeCorner[3].y)) * 0.5;
    
    baseArch.mainOffSetXPos = mainOffSetXPos;
    baseArch.mainOffSetYPos = mainOffSetYPos;

    
    particleInit();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    gui->FrameRate = ofToString( ofGetFrameRate(), 2 );
    
    for (int i=0; i<particles.size(); i++) {
        particles[i].movingFactor = particles[i].movingFactor + particles[i].movingSpeed;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    
    ofTranslate( mainOffSetXPos, mainOffSetYPos );
    
    baseArch.guideFrames( ofColor(0) );
    baseArch.drawEdgeCover();
    baseArch.guideLines();
    baseArch.guidePoints();
    
    ofPopMatrix();

    
    
    
    ofPushMatrix();
    
    ofTranslate( mainOffSetXPos, mainOffSetYPos );

    ofPushStyle();
    
    ofSetColor(255, 0, 0, 255);
    for (int i=0; i<particles.size(); i++) {
        particles[i].pathPolyLine.draw();
        
        float _percent = sin( ofDegToRad(particles[i].movingFactor) ) * 0.5 + 0.5;
        ofVec2f _v = particles[i].pathPolyLine.getPointAtPercent( _percent );
        
        ofDrawCircle( _v, 3 );
        
    }
    
    ofPopStyle();
    
    ofPopMatrix();
    

}


//--------------------------------------------------------------
void ofApp::particleInit(){
    
    int _numParticles = 100;
    particles.resize(_numParticles);
    
    for (int j=0; j<_numParticles; j++) {
        int _xIndex = floor(ofRandom(23));
        int _yIndex = floor(ofRandom(6));
        
        
        ofPolyline _p;
        for (int i=0; i<10; i++) {
            
            int _directionXY = floor(ofRandom(4));
            
            switch (_directionXY) {
                case 0:
                    _xIndex = _xIndex - 1;
                    _yIndex = _yIndex + 0;
                    break;
                case 1:
                    _xIndex = _xIndex + 0;
                    _yIndex = _yIndex - 23;
                    break;
                case 2:
                    _xIndex = _xIndex + 1;
                    _yIndex = _yIndex + 0;
                    break;
                case 3:
                    _xIndex = _xIndex + 0;
                    _yIndex = _yIndex + 23;
                    break;
                    
                default:
                    break;
            }
            
            ofVec2f _v = baseArch.framesCenter[abs(_xIndex)%23][abs(_yIndex)%6];
            _p.addVertex( _v );
        }
        
        particles[j].pathPolyLine = _p;
        
        particles[j].movingFactor = 0;
        particles[j].movingSpeed = ofRandom(0.5, 0.7);
    }
    

    
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    particleInit();

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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

    mainOffSetXPos = (ofGetWidth() - (baseArch.fassadeCorner[0].x + baseArch.fassadeCorner[1].x)) * 0.5;
    mainOffSetYPos = (ofGetHeight() - (baseArch.fassadeCorner[0].y + baseArch.fassadeCorner[3].y)) * 0.5;
    baseArch.mainOffSetXPos = mainOffSetXPos;
    baseArch.mainOffSetYPos = mainOffSetYPos;

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
