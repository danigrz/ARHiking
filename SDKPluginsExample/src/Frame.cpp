//
// Created by simon on 08/04/15.
// Copyright (c) 2015 Wikitude. All rights reserved.
//

#include "Frame.h"

namespace wikitude { namespace sdk {

    namespace impl {
        
        Frame::Frame(unsigned char* frameData_, int frameDataSize_, Size const size_, float scaledWidth_, float scaledHeight_) :
        _frameData(frameData_),
        _frameDataSize(frameDataSize_),
        _size(size_),
        _scaledWidth(scaledWidth_),
        _scaledHeight(scaledHeight_)
        {}
        
        Frame::~Frame()
        {}

        const unsigned char* Frame::getLuminanceData() const {
            return _frameData;
        }

        const unsigned char* Frame::getFullColorSpaceData() const {
            return _frameData;
        }
        
        int Frame::getFrameDataSize() const {
            return _frameDataSize;
        }

        const Size& Frame::getSize() const {
            return _size;
        }

        const float Frame::getScaledWidth() const {
            return _scaledWidth;
        }

        const float Frame::getScaledHeight() const {
            return _scaledHeight;
        }
    }
}}
