
#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"backWall_2x2_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &backWall_2x2_NORMAL_TEX);
glBindTexture(GL_TEXTURE_2D, backWall_2x2_NORMAL_TEX);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"backWall_2x2" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &backWall_2x2_TEXTURE1);
glBindTexture(GL_TEXTURE_2D, backWall_2x2_TEXTURE1);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif        
//----------------------------------------------------------------------------------------------------------------------------

#ifdef WIN32
        //loadTexture("_MODEL_FOLDERS_/backWall_2x2/thirdTex.png",                              backWall_2x2_THIRD_TEX);                                  
        loadTexture("_MODEL_FOLDERS_/backWall_2x2/backWall_2x2_DOT3.bmp",                       backWall_2x2_NORMAL_TEX);                                 
        loadTexture("_MODEL_FOLDERS_/backWall_2x2/backWall_2x2.png",                            backWall_2x2_TEXTURE1);                                   
#endif
//============================================================================================================================|___LOAD_VBO                                    
#include    "backWall_2x2.cpp"                                                                                                                
glGenBuffers(1,              &backWall_2x2_VBO);                                                                                             
glBindBuffer(GL_ARRAY_BUFFER, backWall_2x2_VBO);                                                                                             
glBufferData(GL_ARRAY_BUFFER, sizeof(backWall_2x2), backWall_2x2, GL_STATIC_DRAW);                                                               
glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                        
