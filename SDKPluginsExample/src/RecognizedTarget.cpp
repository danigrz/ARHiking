//
//  RecognizedTarget.cpp
//  CommonLibrary
//
//  Created by Andreas Schacherbauer on 29/05/15.
//  Copyright (c) 2015 Wikitude. All rights reserved.
//

#include "RecognizedTarget.h"


namespace wikitude { namespace sdk {

    namespace impl {


        RecognizedTarget::RecognizedTarget(const std::string& name, const unsigned int distanceToTarget, const Rectangle& targetRectInCameraFrame, const Matrix4& modelView, const Matrix4& projection) :
        _name(name),
        _distanceToTarget(distanceToTarget),
        _targetRectInCameraFrame(targetRectInCameraFrame),
        _modelView(modelView),
        _projection(projection)
        {
        }

        const std::string& RecognizedTarget::getName() const {
            return _name;
        }

        const unsigned int& RecognizedTarget::getDistanceToTarget() const {
            return _distanceToTarget;
        }

        const Rectangle& RecognizedTarget::getTargetPositionInCameraFrame() const {
            return _targetRectInCameraFrame;
        }

        const Matrix4& RecognizedTarget::getModelViewMatrix() const {
            return _modelView;
        }

        const Matrix4& RecognizedTarget::getProjectionMatrix() const {
            return _projection;
        }
    }
}}
