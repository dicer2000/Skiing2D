#pragma once

#include "stdio.h"
#include "body.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
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
	private:

		// To start out, just have the sun written statically in draw()
		// Then make it it's own body object
		// Then make an array of bodies

		/* Step 2 */
		// My Sun
		body *s;
		// My single planet (for now)
//		body *p;

		/* Step 3 - build as an array of pointers */
		body *planets;
};
