#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"plantPot_01_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &plantPot_01_NORMAL_TEX);
glBindTexture(GL_TEXTURE_2D, plantPot_01_NORMAL_TEX);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"plantPot_01" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &plantPot_01_TEXTURE1);
glBindTexture(GL_TEXTURE_2D, plantPot_01_TEXTURE1);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif          
//--------------------------------------------------------------------------------------------------------------------
        #ifdef WIN32
        //loadTexture("_MODEL_FOLDERS_/plantPot_01/thirdTex.png",                        plantPot_01_THIRD_TEX);                   
        loadTexture("_MODEL_FOLDERS_/plantPot_01/plantPot_01_DOT3.bmp",                  plantPot_01_NORMAL_TEX);                  
        loadTexture("_MODEL_FOLDERS_/plantPot_01/plantPot_01.png",                       plantPot_01_TEXTURE1);                    
#endif
//====================================================================================================================|___LOAD_VBO                              
#include    "plantPot_01.cpp"                                                                                                       
glGenBuffers(1,              &plantPot_01_VBO);                                                                                    
glBindBuffer(GL_ARRAY_BUFFER, plantPot_01_VBO);                                                                                    
glBufferData(GL_ARRAY_BUFFER, sizeof(plantPot_01), plantPot_01, GL_STATIC_DRAW);                                                   
glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                  
