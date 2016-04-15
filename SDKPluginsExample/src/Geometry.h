//
//  Rectangle.h
//  CommonLibrary
//
//  Created by simon on 13/04/15.
//  Copyright (c) 2015 Wikitude. All rights reserved.
//

#ifndef CommonLibrary_Rectangle_h
#define CommonLibrary_Rectangle_h

#ifdef __cplusplus

namespace wikitude { namespace sdk {
    
        struct Point {
            int x;
            int y;
        };

        struct Size {
            int width;
            int height;
        };

        struct Rectangle {
            Point   origin;
            Size    size;
        };
        
}}

#endif /* __cplusplus */

#endif
