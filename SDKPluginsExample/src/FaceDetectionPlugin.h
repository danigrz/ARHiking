//
//  FaceDetectionPlugin.h
//  Native Examples
//
//  Created by Alami Yacine on 29/07/15.
//  Copyright (c) 2015 Wikitude. All rights reserved.
//

#ifndef __DevApplication__FaceDetectionPlugin__
#define __DevApplication__FaceDetectionPlugin__

#include <vector>
#include <iostream>
#include <sstream>
#include "jni.h"

#include <opencv.hpp>

#include <Plugin.h>
#include <Frame.h>
#include <RecognizedTarget.h>


class FaceDetectionPluginObserver {
public:
    virtual ~FaceDetectionPluginObserver() {}
    
    virtual void faceDetected(const float* modelViewMatrix) = 0;
    virtual void faceLost() = 0;
    virtual void projectionMatrixChanged(const float* projectionMatrix) = 0;
	virtual void renderDetectedFaceAugmentation() = 0;
};

class FaceDetectionPlugin : public wikitude::sdk::Plugin {
    
public:
	
	FaceDetectionPlugin(int cameraFrameWidth_, int cameraFrameHeight_, FaceDetectionPluginObserver* observer_);
	
	virtual ~FaceDetectionPlugin();
	
	virtual void initialize();
	virtual void destroy();
	virtual void cameraFrameAvailable(const wikitude::sdk::Frame& cameraFrame_);
	virtual void update(const std::list<wikitude::sdk::RecognizedTarget>& recognizedTargets_);
	virtual void startRender() override;
    
	inline bool isLoaded(){ return _isDatabaseLoaded; };
    
    void setFlipFlag(int flipFlag_);

public:
    static FaceDetectionPlugin* 			instance;
    static std::string                      _databasePath;

protected:
    void convertFaceRectToModelViewMatrix(cv::Mat& frame_, cv::Rect& faceRect_);
    void calculateProjection(int flipFlag, float left, float right, float bottom, float top, float near, float far);
    
protected:

	bool                                    _isDatabaseLoaded;

	cv::Mat                                 _grayFrame;
    
    cv::CascadeClassifier                   _cascadeDetector;
	std::vector<cv::Rect>                   _result;
    
    int                                     _cameraFrameWidth;
    int                                     _cameraFrameHeight;
    
    float                                   _scaledCameraFrameWidth;
    float                                   _scaledCameraFrameHeight;

    float                                   _modelViewMatrix[16];
    float                                   _projectionMatrix[16];
    
    float                                   _aspectRatio;
	
	int                                     _flipFlag;

    FaceDetectionPluginObserver*            _observer;
};

#endif /* defined(__DevApplication__FaceDetectionPlugin__) */
