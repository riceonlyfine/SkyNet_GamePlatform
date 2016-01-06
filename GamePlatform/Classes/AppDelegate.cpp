#include "AppDelegate.h"
#include "GameScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
    
	//改变分辨率
	glview->setDesignResolutionSize(800, 600, ResolutionPolicy::SHOW_ALL);
//    initScreenScale();
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	auto scene = GameScene::scene();

    // run
    director->runWithScene(scene);
	
    return true;
}

void AppDelegate::initScreenScale()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    Size sWin = director->getWinSizeInPixels();
    Size sDesign = Size(sWin.width, sWin.height);
    
    float r = sWin.height / sWin.width;
    if(sDesign.width > 800) sDesign.width = 800;
    if(sDesign.width < 600) sDesign.width = 600;
    
    sDesign.height = sDesign.width * r;
    
    glview->setDesignResolutionSize(sDesign.width, sDesign.height, ResolutionPolicy::SHOW_ALL);
};

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
