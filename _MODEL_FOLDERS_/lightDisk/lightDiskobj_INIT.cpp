      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"lightDiskobj_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &lightDiskobj_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, lightDiskobj_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"lightDiskobj" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &lightDiskobj_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, lightDiskobj_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/lightDiskobj/lightDiskobj_DOT3.bmp",          lightDiskobj_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/lightDiskobj/lightDiskobj.png",               lightDiskobj_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "lightDiskobj.cpp"                                                                                                                
      glGenBuffers(1,              &lightDiskobj_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, lightDiskobj_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(lightDiskobj), lightDiskobj, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------       
      #include    "lightDiskobj_INDICES.cpp"                                                                                                                
      glGenBuffers(1,              &lightDiskobj_INDICES_VBO);                                                                                                
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lightDiskobj_INDICES_VBO);                                                                                                
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(lightDiskobj_INDICES), lightDiskobj_INDICES, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------       
