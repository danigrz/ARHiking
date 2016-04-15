//
//  Frame.h
//  SDKCore
//
//  Created by simon on 08/04/15.
//  Copyright (c) 2015 Wikitude. All rights reserved.
//

#ifndef FRAME_H
#define FRAME_H

#ifdef __cplusplus

#include "Geometry.h"


namespace wikitude { namespace sdk {
    
    namespace impl {
        
        class Frame {
        public:
            Frame(unsigned char* frameData_, int frameDataSize_, Size const size_, float scaledWidth_, float scaledHeight_);
            virtual ~Frame();
            
            /**
             * Returns
             */
            const unsigned char* getLuminanceData() const;
            const unsigned char* getFullColorSpaceData() const;
            
            int getFrameDataSize() const;

            const Size& getSize() const;

            const float getScaledWidth() const;
            const float getScaledHeight() const;

        private:
            unsigned char*      _frameData;
            int                 _frameDataSize;
            Size                _size;
            float               _scaledWidth;
            float               _scaledHeight;
        };
    }
    using impl::Frame;
}}

#endif /* __cplusplus */

#endif
