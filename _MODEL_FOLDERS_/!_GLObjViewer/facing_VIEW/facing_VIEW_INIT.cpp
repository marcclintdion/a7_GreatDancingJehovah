      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
      filePathName = [[NSBundle mainBundle] pathForResource:@"facing_VIEW_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &facing_VIEW_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, facing_VIEW_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"facing_VIEW" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &facing_VIEW_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, facing_VIEW_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/facing_VIEW/facing_VIEW_DOT3.bmp",          facing_VIEW_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/facing_VIEW/facing_VIEW.png",               facing_VIEW_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "facing_VIEW.cpp"                                                                                                                
      glGenBuffers(1,              &facing_VIEW_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, facing_VIEW_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(facing_VIEW), facing_VIEW, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------       
      #include    "facing_VIEW_INDICES.cpp"                                                                                                                
      glGenBuffers(1,              &facing_VIEW_INDICES_VBO);                                                                                                
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, facing_VIEW_INDICES_VBO);                                                                                                
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(facing_VIEW_INDICES), facing_VIEW_INDICES, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------       
