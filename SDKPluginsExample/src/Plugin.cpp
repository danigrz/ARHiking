//
//  Plugin.cpp
//  CommonLibrary
//
//  Created by simon on 21/05/15.
//  Copyright (c) 2015 Wikitude. All rights reserved.
//

#include "Plugin.h"

namespace wikitude { namespace sdk {
    
    namespace impl {
        
        
        Plugin::Plugin(std::string identifier_) :
        _identifier(identifier_),
        _enabled(true)
        { /* Intentionally Left Blank */ }
        
        Plugin::~Plugin()
        { /* Intentionally Left Blank */ }
        
        void Plugin::initialize()
        { /* Intentionally Left Blank */ }
        
        void Plugin::pause()
        { /* Intentionally Left Blank */ }
        
        void Plugin::resume(unsigned int pausedTime_)
        { /* Intentionally Left Blank */ }

        void Plugin::surfaceChanged(int width, int height)
        { /* Intentionally Left Blank */ }
        
        void Plugin::destroy()
        { /* Intentionally Left Blank */ }
        
        void Plugin::startRender()
        { /* Intentionally Left Blank */ }
        
        void Plugin::endRender()
        { /* Intentionally Left Blank */ }
        
        bool Plugin::processesColorCameraFrames() {
            return false;
        }
        
        void Plugin::addToJavaScriptQueue(const std::string& javaScriptSnippet_) {
            _javaScriptQueue.push_back(javaScriptSnippet_);
        }
        
        std::list<std::string>& Plugin::getJavaScriptQueue() {
            return _javaScriptQueue;
        }
        
        const std::string& Plugin::getIdentifier() const {
            return _identifier;
        }
        
        bool Plugin::isEnabled() const {
            return _enabled;
        }
        
        void Plugin::setEnabled(bool enabled_) {
            _enabled = enabled_;
        }

    }

}}