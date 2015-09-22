
#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"spikyBall_0_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &spikyBall_0_NORMAL_TEX);
glBindTexture(GL_TEXTURE_2D, spikyBall_0_NORMAL_TEX);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"spikyBall_0" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &spikyBall_0_TEXTURE1);
glBindTexture(GL_TEXTURE_2D, spikyBall_0_TEXTURE1);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif        
//----------------------------------------------------------------------------------------------------------------------------      


#ifdef WIN32
        //loadTexture("_MODEL_FOLDERS_/spikyBall_0/thirdTex.png",                              spikyBall_0_THIRD_TEX);                                  
        loadTexture("_MODEL_FOLDERS_/spikyBall_0/spikyBall_0_DOT3.bmp",                           spikyBall_0_NORMAL_TEX);                                 
        loadTexture("_MODEL_FOLDERS_/spikyBall_0/spikyBall_0.png",                                spikyBall_0_TEXTURE1);                                   
#endif
//------------------------------------------------------------------------------------------|___LOAD_VBO                                    
#include    "spikyBall_0.cpp"                                                                                                                
glGenBuffers(1,              &spikyBall_0_VBO);                                                                                             
glBindBuffer(GL_ARRAY_BUFFER, spikyBall_0_VBO);                                                                                             
glBufferData(GL_ARRAY_BUFFER, sizeof(spikyBall_0), spikyBall_0, GL_STATIC_DRAW);                                                               
glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                        
