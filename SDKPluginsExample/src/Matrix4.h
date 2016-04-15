//
//  Mat4.h
//  CommonLibrary
//
//  Created by simon on 08/05/15.
//  Copyright (c) 2015 Wikitude. All rights reserved.
//

#ifndef CommonLibrary_Mat4_h
#define CommonLibrary_Mat4_h

#ifdef __cplusplus

namespace wikitude { namespace sdk {
    
    namespace impl {

        class Matrix4 {
        public:
            Matrix4(float* data) : _data(data) {}
        public:
            float* _data;
        };
    }
    
    using impl::Matrix4;
}}

#endif /* __cplusplus */

#endif
