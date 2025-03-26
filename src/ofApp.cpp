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
	video.setVolume(0.1);
	video.play();

	// setup FBO
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);

	// load fragment and vertex shaders
	shader.load("shadersGL3/shader");
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();

	// resize fbo if needed?
	if (fbo.getWidth() != ofGetWidth() || fbo.getHeight() != ofGetHeight()) {
		fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
	}

	// draw content to frame buffer object
	fbo.begin();
	ofClear(0, 0, 0, 0);

	// calculate scaling
	// most of the time, the video is not scaled correctly to the window, and is upside down
	float windowWidth = ofGetWidth();
	float windowHeight = ofGetHeight();
	float videoWidth = video.getWidth();
	float videoHeight = video.getHeight();

	float scale = glm::min(windowWidth / videoWidth, windowHeight / videoHeight);
	float scaledWidth = videoWidth * scale;
	float scaledHeight = videoHeight * scale;

	// center the video on screen
	float x = (windowWidth - scaledWidth) / 2;
	float y = (windowHeight - scaledHeight) / 2;

	// apply scaling and draw video
	ofPushMatrix();
	ofTranslate(x, y + scaledHeight);
	ofScale(1, -1);
	video.draw(0, 0, scaledWidth, scaledHeight);
	ofPopMatrix();

	fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	shader.begin();

	// pass FBO texture to shader
	// pass other fragment shader information
	shader.setUniformTexture("tex0", fbo.getTexture(), 0);
	shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
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
	// recreate FBO with new dimensions
	fbo.allocate(w, h, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
