#pragma once

#include "ofMain.h"
#include "skier.h"
#include "slope.h"


class ofApp : public ofBaseApp{
	private:
	    skier* player1;
		slope* slope1;
		bool bLeftKeyPressed = false;
		bool bRightKeyPressed = false;
	public:
		~ofApp();
		void setup();
		void update();
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
};
