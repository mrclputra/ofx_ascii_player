#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetWindowTitle("ofxAsciiPlayer");
	ofBackground(0);
	ofSetFrameRate(30);
	ofDisableAntiAliasing();

	// graphics settings
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofDisableDepthTest();

	// load video
	video.load("videos/tg.mp4");
	video.setVolume(0.2);
	video.play();

	// load fragment and vertex shaders
	shader.load("shadersGL3/shader");
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	shader.begin();

	// pass fragment shader information
	shader.setUniformTexture("tex0", video.getTexture(), 0);
	shader.setUniform2f("texSize", video.getWidth(), video.getHeight());
	shader.setUniform2f("windowSize", ofGetWidth(), ofGetHeight());
	shader.setUniform2f("charSize", 12, 12);

	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
