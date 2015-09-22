
#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"plant_01_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &plant_01_NORMAL_TEX);
glBindTexture(GL_TEXTURE_2D, plant_01_NORMAL_TEX);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"plant_01" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &plant_01_TEXTURE1);
glBindTexture(GL_TEXTURE_2D, plant_01_TEXTURE1);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif          
//--------------------------------------------------------------------------------------------------------------------
#ifdef WIN32
        //loadTexture("_MODEL_FOLDERS_/plant_01/thirdTex.png",                                 plant_01_THIRD_TEX);                   
        loadTexture("_MODEL_FOLDERS_/plant_01/plant_01_DOT3.bmp",                           plant_01_NORMAL_TEX);                  
        loadTexture("_MODEL_FOLDERS_/plant_01/plant_01.png",                                plant_01_TEXTURE1);                    
#endif
//====================================================================================================================|___LOAD_VBO                              

#include    "plant_01.cpp"                                                                                                       
glGenBuffers(1,              &plant_01_VBO);                                                                                    
glBindBuffer(GL_ARRAY_BUFFER, plant_01_VBO);                                                                                    
glBufferData(GL_ARRAY_BUFFER, sizeof(plant_01), plant_01, GL_STATIC_DRAW);                                                   
glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                  
