#pragma once

#include "stdio.h"
#include "body.h"
#include "ofMain.h"


class ofApp : public ofBaseApp{
	public:
		void setup();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	private:

		ofLight light; // creates a light and enables lighting
		ofEasyCam cam; // add mouse controls for camera movement

		// My Sun
		body *s;
};
