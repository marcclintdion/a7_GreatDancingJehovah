//#import <OpenGLES/ES2/gl.h>
//#import <OpenGLES/ES2/glext.h>
//=================================================================================================================================


marc_SHADER = glCreateProgram();
//---------------------------------------------------------------------
#include "MarcWoodShader.vert"
//---------------------------------------------------------------------
marc_SHADER_VERTEX = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(marc_SHADER_VERTEX, 1, &vertexSource, NULL);
glCompileShader(marc_SHADER_VERTEX);    
//---------------------------------------------------------------------
#include "MarcWoodShader.frag"
//---------------------------------------------------------------------
marc_SHADER_FRAGMENT = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(marc_SHADER_FRAGMENT, 1, &fragmentSource, NULL);
glCompileShader(marc_SHADER_FRAGMENT);      
//------------------------------------------------
glAttachShader(marc_SHADER, marc_SHADER_VERTEX);
glAttachShader(marc_SHADER, marc_SHADER_FRAGMENT);
//------------------------------------------------    
glBindAttribLocation(marc_SHADER, 0, "position");       
glBindAttribLocation(marc_SHADER, 1, "texture");
//glBindAttribLocation(marc _SHADER, 2, "normal");   
//------------------------------------------------    
glLinkProgram(marc_SHADER);
//------------------------------------------------
#ifdef __APPLE__    
glDetachShader(marc_SHADER, marc_SHADER_VERTEX);
glDetachShader(marc_SHADER, marc_SHADER_FRAGMENT);
#endif     
//------------------------------------------------
glDeleteShader(marc_SHADER_VERTEX);
glDeleteShader(marc_SHADER_FRAGMENT);

//------------------------------------------------------------------------------------------------------------//___LOAD_UNIFORMS

UNIFORM_MODELVIEWPROJ                   = glGetUniformLocation(marc_SHADER,  "modelViewProjectionMatrix");
UNIFORM_LIGHT_MATRIX                    = glGetUniformLocation(marc_SHADER,  "lightMatrix");    
//UNIFORM_NORMAL_marcLeftUpperArm       = glGetUniformLocation(marc _SHADER, "normalMatrix");

UNIFORM_marc_LIGHT_POSITION_01          = glGetUniformLocation(marc_SHADER,  "light_POSITION_01");      
UNIFORM_TEXTURE_DOT3_marc                    = glGetUniformLocation(marc_SHADER,  "NormalMap");
UNIFORM_TEXTURE_marc                         = glGetUniformLocation(marc_SHADER,  "Texture1");


//------------------------------------------------------------------------------------------------------------//___LOAD_TEXTURES



//=================================================================================================================================


#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"hips_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &hips_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, hips_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"hips" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &hips_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, hips_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/hips/hips_DOT3.bmp",          hips_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/hips/hips.png",               hips_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "hips/hips.cpp"
glGenBuffers(1,              &hips_VBO);
glBindBuffer(GL_ARRAY_BUFFER, hips_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(hips), hips, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================
#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"torso_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &torso_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, torso_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"torso" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &torso_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, torso_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/torso/torso_DOT3.bmp",          torso_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/torso/torso.png",               torso_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "torso/torso.cpp"
glGenBuffers(1,              &torso_VBO);
glBindBuffer(GL_ARRAY_BUFFER, torso_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(torso), torso, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"leftUpperArm_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftUpperArm_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, leftUpperArm_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"leftUpperArm" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftUpperArm_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, leftUpperArm_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/leftUpperArm/leftUpperArm_DOT3.bmp",          leftUpperArm_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/leftUpperArm/leftUpperArm.png",               leftUpperArm_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "leftUpperArm/leftUpperArm.cpp"
glGenBuffers(1,              &leftUpperArm_VBO);
glBindBuffer(GL_ARRAY_BUFFER, leftUpperArm_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(leftUpperArm), leftUpperArm, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"leftLowerArm_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftLowerArm_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, leftLowerArm_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"leftLowerArm" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftLowerArm_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, leftLowerArm_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/leftLowerArm/leftLowerArm_DOT3.bmp",          leftLowerArm_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/leftLowerArm/leftLowerArm.png",               leftLowerArm_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "leftLowerArm/leftLowerArm.cpp"
glGenBuffers(1,              &leftLowerArm_VBO);
glBindBuffer(GL_ARRAY_BUFFER, leftLowerArm_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(leftLowerArm), leftLowerArm, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"leftHand_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftHand_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, leftHand_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"leftHand" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftHand_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, leftHand_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/leftHand/leftHand_DOT3.bmp",          leftHand_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/leftHand/leftHand.png",               leftHand_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "leftHand/leftHand.cpp"
glGenBuffers(1,              &leftHand_VBO);
glBindBuffer(GL_ARRAY_BUFFER, leftHand_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(leftHand), leftHand, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 

//=================================================================================================================================    

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"rightUpperArm_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightUpperArm_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, rightUpperArm_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"rightUpperArm" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightUpperArm_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, rightUpperArm_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/rightUpperArm/rightUpperArm_DOT3.bmp",          rightUpperArm_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/rightUpperArm/rightUpperArm.png",               rightUpperArm_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "rightUpperArm/rightUpperArm.cpp"
glGenBuffers(1,              &rightUpperArm_VBO);
glBindBuffer(GL_ARRAY_BUFFER, rightUpperArm_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(rightUpperArm), rightUpperArm, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"rightLowerArm_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightLowerArm_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, rightLowerArm_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"rightLowerArm" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightLowerArm_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, rightLowerArm_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/rightLowerArm/rightLowerArm_DOT3.bmp",          rightLowerArm_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/rightLowerArm/rightLowerArm.png",               rightLowerArm_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "rightLowerArm/rightLowerArm.cpp"
glGenBuffers(1,              &rightLowerArm_VBO);
glBindBuffer(GL_ARRAY_BUFFER, rightLowerArm_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(rightLowerArm), rightLowerArm, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"rightHand_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightHand_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, rightHand_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"rightHand" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightHand_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, rightHand_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/rightHand/rightHand_DOT3.bmp",          rightHand_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/rightHand/rightHand.png",               rightHand_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "rightHand/rightHand.cpp"
glGenBuffers(1,              &rightHand_VBO);
glBindBuffer(GL_ARRAY_BUFFER, rightHand_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(rightHand), rightHand, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 

//=================================================================================================================================     

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"leftUpperLeg_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftUpperLeg_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, leftUpperLeg_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"leftUpperLeg" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftUpperLeg_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, leftUpperLeg_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/leftUpperLeg/leftUpperLeg_DOT3.bmp",          leftUpperLeg_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/leftUpperLeg/leftUpperLeg.png",               leftUpperLeg_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "leftUpperLeg/leftUpperLeg.cpp"
glGenBuffers(1,              &leftUpperLeg_VBO);
glBindBuffer(GL_ARRAY_BUFFER, leftUpperLeg_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(leftUpperLeg), leftUpperLeg, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================     

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"leftLowerLeg_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftLowerLeg_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, leftLowerLeg_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"leftLowerLeg" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftLowerLeg_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, leftLowerLeg_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/leftLowerLeg/leftLowerLeg_DOT3.bmp",          leftLowerLeg_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/leftLowerLeg/leftLowerLeg.png",               leftLowerLeg_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "leftLowerLeg/leftLowerLeg.cpp"
glGenBuffers(1,              &leftLowerLeg_VBO);
glBindBuffer(GL_ARRAY_BUFFER, leftLowerLeg_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(leftLowerLeg), leftLowerLeg, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================      

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"leftFoot_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftFoot_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, leftFoot_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"leftFoot" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &leftFoot_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, leftFoot_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/leftFoot/leftFoot_DOT3.bmp",          leftFoot_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/leftFoot/leftFoot.png",               leftFoot_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "leftFoot/leftFoot.cpp"
glGenBuffers(1,              &leftFoot_VBO);
glBindBuffer(GL_ARRAY_BUFFER, leftFoot_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(leftFoot), leftFoot, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 

//=================================================================================================================================       

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"rightUpperLeg_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightUpperLeg_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, rightUpperLeg_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"rightUpperLeg" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightUpperLeg_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, rightUpperLeg_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/rightUpperLeg/rightUpperLeg_DOT3.bmp",          rightUpperLeg_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/rightUpperLeg/rightUpperLeg.png",               rightUpperLeg_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "rightUpperLeg/rightUpperLeg.cpp"
glGenBuffers(1,              &rightUpperLeg_VBO);
glBindBuffer(GL_ARRAY_BUFFER, rightUpperLeg_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(rightUpperLeg), rightUpperLeg, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================     

#ifdef __APPLE__
filePathName = [[NSBundle mainBundle] pathForResource:@"rightLowerLeg_DOT3" ofType:@"bmp"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightLowerLeg_NORMALMAP);
glBindTexture(GL_TEXTURE_2D, rightLowerLeg_NORMALMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
imgDestroyImage(image);   
//---------------------
filePathName = [[NSBundle mainBundle] pathForResource:@"rightLowerLeg" ofType:@"png"];
image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
glGenTextures(1, &rightLowerLeg_TEXTUREMAP);
glBindTexture(GL_TEXTURE_2D, rightLowerLeg_TEXTUREMAP);
ConfigureAndLoadTexture(image->data,  image->width, image->height );    
imgDestroyImage(image);
#endif    
//------------------------------------------------------------------------------------------
#ifdef WIN32     
loadTexture("_MODEL_FOLDERS_/marcParts/rightLowerLeg/rightLowerLeg_DOT3.bmp",          rightLowerLeg_NORMALMAP);    
loadTexture("_MODEL_FOLDERS_/marcParts/rightLowerLeg/rightLowerLeg.png",               rightLowerLeg_TEXTUREMAP);
#endif  
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "rightLowerLeg/rightLowerLeg.cpp"
glGenBuffers(1,              &rightLowerLeg_VBO);
glBindBuffer(GL_ARRAY_BUFFER, rightLowerLeg_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(rightLowerLeg), rightLowerLeg, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================      
/*
 #ifdef __APPLE__
 filePathName = [[NSBundle mainBundle] pathForResource:@"rightFoot_DOT3" ofType:@"bmp"];
 image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
 glGenTextures(1, &_NORMALMAP);
 glBindTexture(GL_TEXTURE_2D, _NORMALMAP);
 ConfigureAndLoadTexture(image->data,  image->width, image->height ); 
 imgDestroyImage(image);   
 //---------------------
 filePathName = [[NSBundle mainBundle] pathForResource:@"rightFoot" ofType:@"png"];
 image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);
 glGenTextures(1, &_TEXTUREMAP);
 glBindTexture(GL_TEXTURE_2D, _TEXTUREMAP);
 ConfigureAndLoadTexture(image->data,  image->width, image->height );    
 imgDestroyImage(image);
 #endif    
 //------------------------------------------------------------------------------------------
 #ifdef WIN32     
 loadTexture("_MODEL_FOLDERS_/marcParts/rightFoot/rightFoot_DOT3.bmp",          _NORMALMAP);    
 loadTexture("_MODEL_FOLDERS_/marcParts/rightFoot/rightFoot.png",               _TEXTUREMAP);
 #endif
*/
//------------------------------------------------------------------------------------------------------------//___LOAD_VBO      
#include    "rightFoot/rightFoot.cpp"
glGenBuffers(1,              &rightFoot_VBO);
glBindBuffer(GL_ARRAY_BUFFER, rightFoot_VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(rightFoot), rightFoot, GL_STATIC_DRAW);
glBindBuffer(GL_ARRAY_BUFFER, 0); 
//=================================================================================================================================     



