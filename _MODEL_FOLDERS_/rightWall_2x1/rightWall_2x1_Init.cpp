
#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"rightWall_2x1_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightWall_2x1_NORMAL_TEX);
glBindTexture(GL_TEXTURE_2D, rightWall_2x1_NORMAL_TEX);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"rightWall_2x1" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightWall_2x1_TEXTURE1);
glBindTexture(GL_TEXTURE_2D, rightWall_2x1_TEXTURE1);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//---------------------------------------------------------------------------------------------------------------------      
#ifdef WIN32
        //loadTexture("_MODEL_FOLDERS_/rightWall_2x1/thirdTex.png",                              rightWall_2x1_THIRD_TEX);                                  
        loadTexture("_MODEL_FOLDERS_/rightWall_2x1/rightWall_2x1_DOT3.bmp",                           rightWall_2x1_NORMAL_TEX);                                 
        loadTexture("_MODEL_FOLDERS_/rightWall_2x1/rightWall_2x1.png",                                rightWall_2x1_TEXTURE1);                                   
#endif
//------------------------------------------------------------------------------------------|___LOAD_VBO                                    
#include    "rightWall_2x1.cpp"                                                                                                                
glGenBuffers(1,              &rightWall_2x1_VBO);                                                                                             
glBindBuffer(GL_ARRAY_BUFFER, rightWall_2x1_VBO);                                                                                             
glBufferData(GL_ARRAY_BUFFER, sizeof(rightWall_2x1), rightWall_2x1, GL_STATIC_DRAW);                                                               
glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                        
