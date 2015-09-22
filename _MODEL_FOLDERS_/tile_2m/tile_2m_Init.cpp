
        #ifdef __APPLE__
        filePathName = [[NSBundle mainBundle] pathForResource:@"tile_2m_DOT3" ofType:@"bmp"];
        image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
        glGenTextures(1, &tile_2m_NORMAL_TEX);
        glBindTexture(GL_TEXTURE_2D, tile_2m_NORMAL_TEX);
        ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
        imgDestroyImage(image);   
        //---------------------
        filePathName = [[NSBundle mainBundle] pathForResource:@"tile_2m" ofType:@"png"];
        image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
        glGenTextures(1, &tile_2m_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, tile_2m_TEXTURE1);
        ConfigureAndLoadTexture(image->data,  image->width, image->height );    
        imgDestroyImage(image);
        #endif    
        //---------------------------------------------------------------------------------------------------------------------      
        #ifdef WIN32
        loadTexture("_MODEL_FOLDERS_/tile_2m/tile_2m_DOT3.bmp",                       tile_2m_NORMAL_TEX);                
        loadTexture("_MODEL_FOLDERS_/tile_2m/tile_2m.png",                            tile_2m_TEXTURE1);                  
        #endif
        //---------------------------------------------------------------------------------------------------------------------|___LOAD_VBO                        
  
        #include    "tile_2m.cpp"                                                                                           
        glGenBuffers(1,              &tile_2m_VBO);                                                                              
        glBindBuffer(GL_ARRAY_BUFFER, tile_2m_VBO);                                                                              
        glBufferData(GL_ARRAY_BUFFER, sizeof(tile_2m), tile_2m, GL_STATIC_DRAW);                                             
        glBindBuffer(GL_ARRAY_BUFFER, 0);    
