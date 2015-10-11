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
        
        if (particles[i].movingFactor > 1.0) {
            particles[i].movingFactor = 0;
        }
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
    
    ofSetColor(255, 180);
    for (int i=0; i<particles.size(); i++) {
        particles[i].pathPolyLine.draw();
    }
    
    ofSetColor(255, 255);
    for (int i=0; i<particles.size(); i++) {
        float _percent = particles[i].movingFactor;
        ofVec2f _v = particles[i].pathPolyLine.getPointAtPercent( _percent );
        ofDrawCircle( _v, particles[i].size );
    }

    
    ofSetColor(255, 120);

    for (int i=0; i<particles.size(); i++) {
        float _percentS = particles[i].movingFactor;
        ofVec2f _vS = particles[i].pathPolyLine.getPointAtPercent( _percentS );

        for (int j=0; j<particles.size(); j++) {

            if (i != j) {
                float _percentE = particles[i].movingFactor;
                ofVec2f _vE = particles[j].pathPolyLine.getPointAtPercent( _percentE );
                
                if ( ( _vE.distance(_vS) > 50 ) && ( _vE.distance(_vS) < 100 ) ){
                    ofDrawLine( _vS, _vE );
                }
            }
            
        }
        
    }

    
    ofPopStyle();
    
    ofPopMatrix();
    

}


//--------------------------------------------------------------
void ofApp::particleInit(){
    
    int _numParticles = 200;
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
