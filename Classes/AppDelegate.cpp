#include "AppDelegate.h"

#include "Scene/PlaneWarScene.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
		glview = GLView::createWithRect("PlaneWar", cocos2d::Rect(0, 0, 680 * 3 / 5, 960*3/5));
        director->setOpenGLView(glview);
    }
	glview->setDesignResolutionSize(680, 960, ResolutionPolicy::EXACT_FIT);
	
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);

	auto scene = PlaneWarScene::create();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
