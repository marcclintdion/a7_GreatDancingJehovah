
#ifdef __APPLE__
/*
filePathName = [[NSBundle mainBundle] pathForResource:@"backDrop_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &backDrop_NORMAL_TEX);
glBindTexture(GL_TEXTURE_2D, backDrop_NORMAL_TEX);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);  
 */
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"backDrop" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &backDrop_TEXTURE1);
glBindTexture(GL_TEXTURE_2D, backDrop_TEXTURE1);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//---------------------------------------------------------------------------------------------------------------------   

#ifdef WIN32
//loadTexture("_MODEL_FOLDERS_/backDrop/thirdTex.png",                              backDrop_THIRD_TEX);                                  
//loadTexture("_MODEL_FOLDERS_/backDrop/backDrop_DOT3.bmp",                           backDrop_NORMAL_TEX);                                 
loadTexture("_MODEL_FOLDERS_/backDrop/backDrop.png",                                backDrop_TEXTURE1);                                   
#endif

//------------------------------------------------------------------------------------------|___LOAD_VBO                                    
#include    "backDrop.cpp"                                                                                                                
glGenBuffers(1,              &backDrop_VBO);                                                                                             
glBindBuffer(GL_ARRAY_BUFFER, backDrop_VBO);                                                                                             
glBufferData(GL_ARRAY_BUFFER, sizeof(backDrop), backDrop, GL_STATIC_DRAW);                                                               
glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                        
