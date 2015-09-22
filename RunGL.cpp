
//####################################################################################################################


#ifdef WIN32
#define glGenerateMipmap       glGenerateMipmapEXT        
#define glGenFramebuffers      glGenFramebuffersEXT    
#define glBindFramebuffer      glBindFramebufferEXT          
#define glFramebufferTexture2D glFramebufferTexture2DEXT            

#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream.h>
#include <fstream.h>
//using namespace std; //___used for string object

#include <GL/gl.h>

HDC	       hDC        = NULL;
HGLRC      hRC        = NULL;
HWND       hWnd       = NULL;
HINSTANCE  hInstance  = NULL;
//-------------------------------
int        WINAPI       WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT    CALLBACK     WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//-------------------------------
void       ProcessKeyboard();
int        LoadTexture(char *texture_name, GLuint *texture);
//-------------------------------
bool keys[256], keypressed[256];



#include "headerFiles/glext.h" 
#include "headerFiles/glext_Init_A.cpp" 

#include "headerFiles/VSync.h"   

#include <windows.h>

void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
#include "headerFiles/FreeImage.h"
#include "cpp/freeImage.cpp"


#endif



//####################################################################################################################


#include <math.h>


//###############################################################################################################################################

#include "MATRIX_MATH.cpp"

//###############################################################################################################################################
//-------------------------------------------------------------------------------------------------------------- 

void RenderGL(void);
void InitGL  (void);
void shutDownGL(void);


  GLfloat rotateModel[] = {0.0, 0.0, 0.0, 0.0};

        int screenWidth;
        int screenHeight; 

#ifdef WIN32
GLfloat viewWidth    = 1920;
GLfloat viewHeight   = 1080;
#endif
#ifdef __APPLE__
GLfloat viewWidth;
GLfloat viewHeight;
GLuint  viewFramebuffer;        
#endif  
        #include "cpp/WGL_ARB_multisample.h"

GLuint textureID;
GLuint textureMap[10];

GLuint fbo, color, depth;
GLuint componentShaderPass_fbo, componentShaderPass_color, componentShaderPass_depth;

const       int TEXTURE_WIDTH  = 2048;
const       int TEXTURE_HEIGHT = 2048;
//------------------------------------
GLuint      shadow_2D_ID; 
GLuint      shadowMap_2D;
//--------------------------------------
GLuint      fboId; 
GLuint      gaussianBlurHorizontalPass_fboId;
GLuint      gaussianBlurVerticalPass_fboId;
#include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass_vboGlobals.cpp"  //vboID = 300
#include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurVerticalPass/gaussianBlurVerticalPass_vboGlobals.cpp"  //vboID = 301



extern GLuint msaaFramebuffer;

//--------------------------------------------------------------------------------------------------------------
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//----------------------------------------------------------------------------------------


void DrawModels(void);


      
//-------------------------------------------------------------------------------

GLfloat eyePosition[3];
GLfloat look_LEFT_RIGHT;
GLfloat look_UP_DOWN;   

GLfloat screenBuffer_EyePosition[3];




//#########################################################################################################|_FREE_IMAGE

void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{
        #ifdef __APPLE__
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        #endif
        
        #ifdef WIN32
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
        #endif  
}

//===============================================================================================================================                                                   

GLfloat     modelView[16];
GLfloat     projection[16];
GLfloat     mvpMatrix[16];
GLfloat     mvpMatrixInverse[16];
GLfloat     lightMatrix[16];  
GLfloat     moveSetMatrix[16]; 
GLfloat     textureMatrix[16];
GLfloat     ProjectionShadow[16];
GLfloat     LightModelViewMatrix[16];

GLfloat     ScreenBufferMatrix[16];

GLuint      UNIFORM_MODELVIEWPROJ;
GLuint      UNIFORM_MODELVIEWPROJ_INVERSE;
GLuint      UNIFORM_LIGHT_MATRIX;

//===============================================================================================================================

GLfloat frameRateAdjustment  =     1.0; 

//######################################################################################################################


//-----------------------------------------------------------------------------------------------------------
bool TAB_KEY_RESET = true;
bool KEY_V_IS_RESET = true;
bool KEY_C_IS_RESET = true;

GLfloat       ChangeShaderSelection                                     = 2;                                 
//========================================
GLfloat       backGroundLight_01_POSITION[]                             = {0.0, 10.0, 500, 1.0}; 
//========================================
GLfloat       globalLinearAttenuation                                   =     0.09;
GLfloat       offset[]                                                  =  {20.04, 4.58902, 4.18, 1};
GLfloat       moveSet[]                                                 = {0.0, 0.0, 0.0}; 
//---------------------------------------------------- 
#include    "_SHADERS/SHADOWS/shadows_24B_GLOBALS.cpp"                              
//----------------------------------------------------
bool          BASE_LIGHTING                                             = false;
GLfloat       baseLighting_LIGHT_POSITION_01[]                          =  {  -0.068917, 3.9, -0.715183, 1};
GLfloat       ambient_baseLighting                                      =      0.451993;   
#include    "_SHADERS/BASIC/baseLighting_GLOBALS.cpp"
//----------------------------------------------------
bool          GOLDEN_SUNSET_LIGHTING                                    = true; 
GLfloat       goldenSunset_LIGHT_POSITION_01[]                          =  {  -0.068917, 3.9, -0.715183, 1};
GLfloat       ambient_goldenSunset                                      =  0.941993; 
#include    "_SHADERS/BACKGROUND/goldenSunset_GLOBALS.cpp"
//--------------------------------------------------------
GLfloat       wood_LIGHT_POSITION_01[]                                  =  {  -0.168917, 4.73002, -0.115183, 1};
GLfloat       shininess_wood                                            =     34.3499;
GLfloat       ambient_wood                                              =      0.106997;                            
GLfloat       attenuation_SHINY_wood                                    =      1/0.014997;                              
#include    "_SHADERS/BACKGROUND/wood_GLOBALS.cpp"  
//------------------------------------------------------ 
//#include    "_SHADERS/BACKGROUND/wood_32B_GLOBALS.cpp"                                                         
//------------------------------------------------------
GLfloat       backDrop_LIGHT_POSITION_01[]                              =  {  -0.168917, 4.73002, -0.115183, 1};
GLfloat       shininess_backDrop                                        =     34.3499;
GLfloat       ambient_backDrop                                          =      0.0619971;                             
#include    "_SHADERS/BACKGROUND/backDrop_GLOBALS.cpp"                                  
//----------------------------------------------------                              
GLfloat       plant_LIGHT_POSITION_01[]                                 =  {  -0.168917, 4.73002, -0.115183, 1};
GLfloat       ambient_plant                                             =      0.0539995;                                 
#include    "_SHADERS/BACKGROUND/plant_GLOBALS.cpp"
//-------------------------------------------------   

//====================================================================================                                          

GLfloat     frameBufferPlane_SCALE[]                                        =  {1920.0/1080.0, 1.0,  1.0, 1.0};   
GLfloat     frameBufferPlane_ratio_Global_2_Component                       =   1.0;  
//-----------
#include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_Globals.cpp"        
                                                        

GLfloat     frameBufferPlane_GaussianHorizontal_SCALE[]                                        =  {1920.0/1080.0, 1.0,  1.0, 1.0};   
GLfloat     frameBufferPlane_GaussianHorizontal_ratio_Global_2_Component                       =   1.0;  
//-----------
#include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_GaussianHorizontal_Globals.cpp"        
  
GLfloat     frameBufferPlane_GaussianVertical_SCALE[]                                        =  {1920.0/1080.0, 1.0,  1.0, 1.0};   
GLfloat     frameBufferPlane_GaussianVertical_ratio_Global_2_Component                       =   1.0;  
//-----------
#include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_GaussianVertical_Globals.cpp"        
  
//====================================================================================  
//------------
GLfloat       globalIllumination_01_LIGHT_POSITION_01[]                                             =  {  -0.068917, 3.9, -0.715183, 1};

  GLfloat     ambient_globalIllumination_01        =  .3;
  GLfloat     scaleInverse_NdotL1_globalIllumination_01           =  0.412042;

#include      "_SHADERS/GLOBAL_ILLUMINATION/globalIllumination_01_GLOBALS.cpp"
//--------------------------------------------------     
GLfloat       globalIllumination_02_LIGHT_POSITION_01[]                                             =  {  -0.068917, 3.9, -0.715183, 1};

   
  GLfloat     ambient_globalIllumination_02        =  7.04106;
  GLfloat     scaleInverse_NdotL1_globalIllumination_02           =  -0.204999;

#include    "_SHADERS/GLOBAL_ILLUMINATION/FOG_SSS/globalIllumination_02_GLOBALS.cpp"
//--------------------------------------------------        
GLfloat       MIRROR_SPECULAR_LIGHT_POSITION_01[]                                                   =  {  -0.068917, 3.9, -0.715183, 1};


  GLfloat     ambient_MIRROR_SPECULAR        =  0.250001;
  GLfloat     scaleInverse_NdotL1_MIRROR_SPECULAR           =  17.8503;

#include    "_SHADERS/GLOBAL_ILLUMINATION/MIRROR_SPECULAR/MIRROR_SPECULAR_GLOBALS.cpp"
//--------------------------------------------------        
GLfloat       globalIllumination_ORIGINAL_LIGHT_POSITION_01[]                                       =  {  -0.068917, 3.9, -0.715183, 1};

  
  GLfloat     ambient_globalIllumination_ORIGINAL        =  4.05;
  GLfloat     scaleInverse_NdotL1_globalIllumination_ORIGINAL           =  7.61008;


#include    "_SHADERS/GLOBAL_ILLUMINATION/ORIGINAL/globalIllumination_ORIGINAL_GLOBALS.cpp"
//--------------------------------------------------                  
//--------------------------------------------------        
GLfloat       globalIllumination_SQUARED_LIGHT_POSITION_01[]                                        =  {  -0.068917, 3.9, -0.715183, 1};

 

  GLfloat     ambient_globalIllumination_SQUARED        =  14.2903;
  GLfloat     scaleInverse_NdotL1_globalIllumination_SQUARED           =  0.942;

#include    "_SHADERS/GLOBAL_ILLUMINATION/SQUARED/globalIllumination_SQUARED_GLOBALS.cpp"
//--------------------------------------------------    


//=====================================================================================================================
//=====================================================================================================================

GLuint SHADER_SELECTION;
   
         


void ShaderSelection(void)
{
         
         //_SHADER_SELECTION = 0 -> COMPONENT_SHADER                                                       
         //_SHADER_SELECTION = 1 -> GLOBAL_ILLUMINATION_01
         //_SHADER_SELECTION = 2 -> GLOBAL_ILLUMINATION_02
         //_SHADER_SELECTION = 3 -> MIRROR_SPECULAR
         //_SHADER_SELECTION = 4 -> ORIGINAL
         //_SHADER_SELECTION = 5 -> SQUARED
         
         
         
         
         //-------------------------------------------------------------------------------------------------
         if(SHADER_SELECTION == 1)
         {       
                 frameBufferPlane_ratio_Global_2_Component        =  0.568996;
                 #include "_SHADERS/GLOBAL_ILLUMINATION/globalIllumination_01_RENDER.cpp"                                                                        
         } 
         //-------------------------------------------------------------------------------------------------
         if(SHADER_SELECTION == 2)
         {       
                  frameBufferPlane_ratio_Global_2_Component        =  1.0;
                 #include "_SHADERS/GLOBAL_ILLUMINATION/FOG_SSS/globalIllumination_02_RENDER.cpp"                                                                        
         } 
         //-------------------------------------------------------------------------------------------------
         if(SHADER_SELECTION == 3)
         {       
                  frameBufferPlane_ratio_Global_2_Component        =  0.5;
                 #include "_SHADERS/GLOBAL_ILLUMINATION/MIRROR_SPECULAR/MIRROR_SPECULAR_RENDER.cpp"                                                                        
         } 
         //-------------------------------------------------------------------------------------------------
         if(SHADER_SELECTION == 4)
         {       
                 frameBufferPlane_ratio_Global_2_Component        =  0.27;
                 #include "_SHADERS/GLOBAL_ILLUMINATION/ORIGINAL/globalIllumination_ORIGINAL_RENDER.cpp"                                                                        
         } 
         //-------------------------------------------------------------------------------------------------
         if(SHADER_SELECTION == 5)
         {       
                 frameBufferPlane_ratio_Global_2_Component        =  0.21;  
                 #include "_SHADERS/GLOBAL_ILLUMINATION/SQUARED/globalIllumination_SQUARED_RENDER.cpp"                                                                        
         } 
         //-------------------------------------------------------------------------------------------------
} 
//#######################################################################################################################
//#######################################################################################################################
//#######################################################################################################################
//#######################################################################################################################





       
        
//######################################################################################################################                          
GLfloat       adjustShadowMove[]                                        =  {  0.11, 0.0, 0.0, 1.0}; 
//=========================================================================================== 
GLfloat       shadows_POSITION[]                                        =  {  0.0, 0.0, 0.0, 1.0}; 
GLfloat       shadows_ROTATE[]                                          =  {  1.0, 0.0, 0.0, 0.0};
//-------------------------
GLfloat       moveShadow_A[]                                            =  { -0.2, 2.2, -6.8, 1};
GLfloat       rotateShadow_A[]                                          =  {  0, 1, 1, 00.0};
GLfloat       adjustMarcShadowAngle                                     =    0.0;
GLfloat       adjustModelShadow_A_ROTATION                              =    0.0;
//-------------------------
GLfloat       moveShadow_B[]                                            =  {  0.71,   -0.27,    0.0,      1.0};
GLfloat       rotateShadow_02[]                                         =  {  0.12,   -4.7,     2.42,   -32.456};
GLfloat       adjustModelShadow_02_ROTATION                             =    25.0;
//-------------------------
GLfloat       moveShadow_03[]                                           =  { -0.515, -12.6952, -0.440011,   1.0};
GLfloat       rotateShadow_03[]                                         =  {  0.0,     1.0,       1.0,    29.28};                           
GLfloat       darkness_shadow[]                                         =  {  0.0,     0.0,       0.0,     1.0};                                                     
//===========================================================================================  
                                GLfloat       movePiece[]                                               =  {  0.0,     0.0,       0.0,     0.0};
                                //--------------------------------------------------------------                                                    
                                GLfloat       backDrop_POSITION[]                                       =  {  0.0,  1000.0,       0.0,     1.0};     
                                #include    "_MODEL_FOLDERS_/backDrop/backDrop_Globals.cpp"                                                          
                                //===================================================================================================================
                                #include    "_MODEL_FOLDERS_/marcParts/marc_GLOBALS.cpp"
                                //----------------------------------------------------------------------------------
                                #include    "_MODEL_FOLDERS_/marcParts/head/head_Globals.cpp"                                                                
                                //----------------------------------------------------------------------------------
                                GLfloat       chestArmor_LIGHT_POSITION_01[]     =  {2.99999, 4.42999, 13.88, 1.0};
                                #include    "_MODEL_FOLDERS_/chestArmor/chestArmor_Globals.cpp"                                                            
                                //=================================================================================================================== 
                                //GLfloat     tile_2m_LIGHT_POSITION_01[]                               = { 1.0, 5.0, 2.0, 1.0};
                                GLuint        tile_2m_NORMALMAP;
                                GLuint        tile_2m_TEXTUREMAP;
                                #include    "_MODEL_FOLDERS_/tile_2m/tile_2m_Globals.cpp" 
                                //---------------------
                                //GLfloat     pyramidTile_LIGHT_POSITION[]                              = { 1.0, 5.0, 2.0, 1.0};
                                #include    "_MODEL_FOLDERS_/pyramidTile/pyramidTile_Globals.cpp"     
                                //--------------------------------------------------------------
                                //GLfloat     smallPillar_LIGHT_POSITION[]                              = { 1.0, 5.0, 2.0, 1.0};
                                #include    "_MODEL_FOLDERS_/smallPillar/smallPillar_Globals.cpp"     
                                //--------------------------------------------------------------
                                GLfloat       moveShadow_PlantPot_01[]                                  =  {-4.0, -6.28005, 0, 1};
                                GLfloat       plantPot_01_LIGHT_POSITION[]                              =  { 0.38, -2.04, 9.82004, 1};
                                #include    "_MODEL_FOLDERS_/plantPot_01/plantPot_01_Globals.cpp"   
                                //--------------------------------------------------------------  
                                GLfloat       plant_01_POSITION[]                                       =  { 0, -0, 0, 1.0};                                                                 
                                GLfloat       plant_01_ROTATE[]                                         =  { 0.0, 1.0,  0.0, 0.0};                                                                
                                //------------
                                GLfloat       moveShadow_plant_01[]                                     =  { 0.216, 0.0, -0.61, 1};
                                GLfloat       adjustMoveShadow_plant_01[]                               =  { 0.0, 0.0, 0.0, 1};
                                //------------
                                GLfloat       scaleMoveShadow_plant_01                                  =    0.058;
                                //------------
                                GLfloat       scaleShadow_plant_01                                      =    1.105005;
                                GLfloat       scaleShadow_plant_02                                      =    1.0;
                                //------------
                                GLfloat       plant_01_Shadow_POSITION[]                                =  {-0.2, -20.4001, 6.3, 1};  
                                
                                GLfloat       plant_01_Shadow_ROTATE[]                                  =  { 5.07, 5.39, 4.84, 43.1701};
                                GLfloat       plant_01_LIGHT_POSITION[]                                 =  { 0.0, 0.0, 0.0, 1.0}; 
                                GLfloat       plant_01_AMBIENT                                          =    0.198903;
                                #include    "_MODEL_FOLDERS_/plant_01/plant_01_Globals.cpp"                                                          
                                //-------------------------------------------------------------------
                                #include    "_MODEL_FOLDERS_/rightWall_2x1/rightWall_2x1_Globals.cpp"                                                          
                                //-------------------------------------------------------------------                                                    
                                GLfloat       backWall_2x2_LIGHT_POSITION[]                             = { -0.2, -1.4, 3, 1};
                                #include    "_MODEL_FOLDERS_/backWall_2x2/backWall_2x2_Globals.cpp"                                                          
                                //====================================================================================                                                   
                                GLfloat       spikyBall_00_time                                         =    0.0;
                                //---------------------------------------------                              
                                GLfloat       initialVelocitySpikyBall_1                                =    0.0;
                                GLuint        UNIFORM_initialVelocitySpikyBall_1;
                                //---------------------------------------------
                                GLfloat       velocityIncreaseRotation_1                                =    1.0;
                                GLfloat       velocitySwap_1[]                                          = {  0.0, 0.0, 0.0, 0.0};
                                #include     "ADD_COLLISION_BALL/GLOBALS_1.cpp"
                                //---------------------------------------------
                                GLfloat       spikyBall_0_POSITION[]                                    = {  0.5, 0.5, 0.5};                                                                       
                                GLfloat       spikyBall_0_ROTATE[]                                      = {  1.0, 0.0,  0.0, 0.0};                                                                         
                                GLfloat       spikyBall_0_SCALE                                         =    0.21;  
                                //------------
                                GLfloat       moveShadow_A_spikyBall_0[]                                = {  0.286, 0.0, -0.809998, 1.0};
                                GLfloat       moveShadow_B_spikyBall_0[]                                = {  0.286, 0.0, -0.809998, 1.0};
                                GLfloat       rotateShadow_SpikyBall[]                                  = {  1.0, 0.0, 0.0, 0.16};
                                GLfloat       scaleSpikeyBallShadowMove                                 =    0.00;
                                #include    "_MODEL_FOLDERS_/spikyBall_0/spikyBall_0_Globals.cpp"                                                          
                                //==============================================================================================================================


                                #include "_MODEL_FOLDERS_/springBoard/baseMain/baseMain_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/springBoard/springCore/springCore_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/springBoard/spring/spring_Globals.cpp"                                                                
                                //====================================================================================   


#include "_MODEL_FOLDERS_/lightDisk/lightDiskobj_Globals.cpp"                                                                
//====================================================================================                                          
   


//======================================================================================================================================================================================


                                        
  

//======================================================================================================================================================================================




//------------------------------------------------------------------------------------------------------------------------                 
//------------------------------------------------------------------------------------------------------------------------                 
                                                            
GLfloat    moveModel[]                           = {0.0, 0.0, 0.0, 0.0};

GLfloat    positionY                             =  0.0;
GLfloat    positionX                             =  0.0;                                  

GLfloat    boundingBox_MAIN_CHARACTER_left_edge  = -0.179;      
GLfloat    boundingBox_MAIN_CHARACTER_right_edge =  0.179; 
GLfloat    boundingBox_MAIN_CHARACTER_lower_edge =  0.01;
GLfloat    boundingBox_MAIN_CHARACTER_upper_edge =  1.253;
GLfloat    boundingBox_MAIN_CHARACTER_near_edge  =  0.179;     
GLfloat    boundingBox_MAIN_CHARACTER_far_edge   = -0.179;

int        numberOfCollisionObjects              =  5;

GLfloat    left_edge_SecondaryObjects[500];
GLfloat    right_edge_SecondaryObjects[500];
GLfloat    lower_edge_SecondaryObjects[500];
GLfloat    upper_edge_SecondaryObjects[500];
GLfloat    near_edge_SecondaryObjects[500];
GLfloat    far_edge_SecondaryObjects[500];

bool       RIGHT = true;
bool       LEFT  = true;                                      
bool       UP    = true;
bool       DOWN  = true;

GLuint     objectNumber;

#include "cpp/collisionCheck.cpp" 
//------------------------------------------------------------------------------------------------------------------------------------

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################

#ifdef __APPLE__
#import <AVFoundation/AVFoundation.h>
AVAudioPlayer *funkLoop;
//------------------------------------
AVAudioPlayer *laser;
//------------------------------------
#endif


//#include <AudioToolbox/AudioToolbox.h>
//SystemSoundID _pewPewSound;
//------------------------------------


void InitGL( void )//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END_INIT__
{

#ifdef __APPLE__        
        //NSString *pewPewPath = [[NSBundle mainBundle]  pathForResource:@"funkLoop" ofType:@"mp3"];
        //NSURL *pewPewURL = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"funkLoop" ofType:@"mp3"]];
        //AudioServicesCreateSystemSoundID((CFURLRef)pewPewURL, &_pewPewSound);
        //AudioServicesPlaySystemSound(_pewPewSound);
        
        //====================================================================================================================            
        NSURL *url = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"funkLoop" ofType:@"mp3"]];
        funkLoop = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:nil];
	    funkLoop.numberOfLoops = -1;
	    funkLoop.volume = 1.0;
        [funkLoop play];  
        //====================================================================================================================           
        NSURL *url2 = [NSURL fileURLWithPath:[[NSBundle mainBundle]  pathForResource:@"laser" ofType:@"wav"]];
        laser = [[AVAudioPlayer alloc] initWithContentsOfURL:url2 error:nil];
	    laser.numberOfLoops = -1;
	    laser.volume = 1.0;
        [laser play];  
        //====================================================================================================================         
#endif       
       
        eyePosition[0]                     =  -0.0; 
        eyePosition[1]                     =  -4.49996; 
        eyePosition[2]                     =   7.45011;
        
        look_LEFT_RIGHT                   =    0.0;
        look_UP_DOWN                      =    8.6;   
        
        
        
        
        screenBuffer_EyePosition[0]                     =   0.0; 
        screenBuffer_EyePosition[1]                     =   0.0; 
        screenBuffer_EyePosition[2]                     =   0.5;  //57.4      
        
        
        //==========================================================================
#ifdef WIN32    
#include "cpp/setPixelFormat.cpp"
#include "headerFiles/glext_Init_B.cpp" 
        //-------------------------------------
        SetVSyncState(false);        
#endif
        
        //====================================================================================================================
        
        //====================================================================================================================    
        glGenTextures(1, &shadowMap_2D);
        glBindTexture(GL_TEXTURE_2D, shadowMap_2D);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        glBindTexture(GL_TEXTURE_2D, 0);   
        //-----------------------------------------
        glGenFramebuffers(1, &shadow_2D_ID);
        glBindFramebuffer(GL_FRAMEBUFFER, shadow_2D_ID);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, shadowMap_2D, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        //====================================================================================================================                                         

/*
// Create an FBO
glGenFramebuffersEXT(1, &fbo);
// Create color texture
glGenTextures(1, &color);
glBindTexture(GL_TEXTURE_2D, color);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
// Bind the FBO and attach color texture to it
glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo);
glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, color, 0); 

glGenRenderbuffersEXT(1, &depth);
glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, depth); 
glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT24, (GLsizei)viewWidth, (GLsizei)viewHeight);  
*/


    glGenFramebuffersEXT(1, &fbo);
    //----------------------------------------------------------------------------
    glGenTextures(1, &color);
    glBindTexture(GL_TEXTURE_2D, color);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
    //----------------------------------------------------------------------------
    glGenTextures(1, &depth);
    glBindTexture(GL_TEXTURE_2D, depth);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth, (GLsizei)viewHeight,  0, GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);        
    //----------------------------------------------------------------------------
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, color, 0);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT,  GL_TEXTURE_2D, depth, 0);




     
       //====================================================================================================================           
        
/*
glGenFramebuffersEXT(1, &componentShaderPass_fbo);

glGenTextures(1, &componentShaderPass_color);
glBindTexture(GL_TEXTURE_2D, componentShaderPass_color);
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, componentShaderPass_fbo);
glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, componentShaderPass_color, 0); 

glGenRenderbuffersEXT(1, &componentShaderPass_depth);
glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, componentShaderPass_depth); 
glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT24, (GLsizei)viewWidth, (GLsizei)viewHeight);  
*/
    glGenFramebuffersEXT(1, &componentShaderPass_fbo);
    //----------------------------------------------------------------------------
    glGenTextures(1, &componentShaderPass_color);
    glBindTexture(GL_TEXTURE_2D, componentShaderPass_color);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
    //----------------------------------------------------------------------------
    glGenTextures(1, &componentShaderPass_depth);
    glBindTexture(GL_TEXTURE_2D, componentShaderPass_depth);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth, (GLsizei)viewHeight,  0, GL_DEPTH_COMPONENT, GL_UNSIGNED_SHORT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);        
    //----------------------------------------------------------------------------
    glBindFramebufferEXT(GL_FRAMEBUFFER, componentShaderPass_fbo);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, componentShaderPass_color, 0);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT,  GL_TEXTURE_2D, componentShaderPass_depth, 0);



     
       //====================================================================================================================           
              
  
    glGenFramebuffersEXT(1, &gaussianBlurHorizontalPass_fboId);    
    glGenTextures(1, &textureMap[1]);
    glBindTexture(GL_TEXTURE_2D, textureMap[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);    
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, gaussianBlurHorizontalPass_fboId);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, textureMap[1], 0);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    glGenFramebuffersEXT(1, &gaussianBlurVerticalPass_fboId);    
    glGenTextures(1, &textureMap[2]);
    glBindTexture(GL_TEXTURE_2D, textureMap[2]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, gaussianBlurVerticalPass_fboId);
    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, textureMap[2], 0);
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        
        
        
        //====================================================================================================================          
        
//#include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurHorizontalPass/gaussianBlurHorizontalPass_shaderInit.cpp"  //vboID = 300  

//#include "_MODEL_FOLDERS_/gaussianBlur/gaussianBlurVerticalPass/gaussianBlurVerticalPass_shaderInit.cpp"  //vboID = 301
        
        #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_GaussianHorizontal_Init.cpp"                                                                   
      
      
        #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_GaussianVertical_Init.cpp"                                                                   
      
      //====================================================================================           
        //-------------------------------------------------------------------------------------------------------------------     
        #include "_SHADERS/BASIC/baseLighting_INIT.cpp"  
        //-------------------------------------------------------------------------------------------------------------------         
        #include "_SHADERS/BACKGROUND/goldenSunset_INIT.cpp"  
        //-------------------------------------------------------------------------------------------------------------------     
        #include "_SHADERS/BACKGROUND/plant_INIT.cpp"      
        //-------------------------------------------------------------------------------------------------------------------     
        #include "_SHADERS/BACKGROUND/wood_INIT.cpp"  
        //-------------------------------------------------------------------------------------------------------------------     
        //#include "_SHADERS/BACKGROUND/wood_32B_INIT.cpp"       
        //-------------------------------------------------------------------------------------------------------------------     
        #include "_SHADERS/SHADOWS/shadows_24B_INIT.cpp"                            
        //-------------------------------------------------------------------------------------------------------------------  
        #include "_SHADERS/BACKGROUND/backDrop_INIT.cpp"      //__SHADER_AND_MODEL_WERE_GIVEN_SAME_NAME
        #include "_MODEL_FOLDERS_/backDrop/backDrop_Init.cpp" //__SHADER_AND_MODEL_WERE_GIVEN_SAME_NAME
        //-------------------------------------------------------------------------------------------------------------------  
       
        //############################################################################################         
        #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_Init.cpp"                                                                   
        //====================================================================================  
       
               
        #include "_SHADERS/GLOBAL_ILLUMINATION/globalIllumination_01_INIT.cpp"  
        //-------------------------------------------------------------------------------------------------------------------  
        #include "_SHADERS/GLOBAL_ILLUMINATION/FOG_SSS/globalIllumination_02_INIT.cpp"  
        //-------------------------------------------------------------------------------------------------------------------  
        #include "_SHADERS/GLOBAL_ILLUMINATION/MIRROR_SPECULAR/MIRROR_SPECULAR_INIT.cpp"  
        //-------------------------------------------------------------------------------------------------------------------  
        #include "_SHADERS/GLOBAL_ILLUMINATION/ORIGINAL/globalIllumination_ORIGINAL_INIT.cpp"                 
        //-------------------------------------------------------------------------------------------------------------------  
        #include "_SHADERS/GLOBAL_ILLUMINATION/SQUARED/globalIllumination_SQUARED_INIT.cpp"                 
        
        //############################################################################################
       
        
        //===================================================================================================================
        #include "_MODEL_FOLDERS_/marcParts/marc_INIT.cpp"
        //------------------------------------------------------------------------------------------------------------------- 
        #include "_MODEL_FOLDERS_/marcParts/head/head_Init.cpp"                                                                   
        //-------------------------------------------------------------------------------------------------------------------    
        #include "_MODEL_FOLDERS_/chestArmor/chestArmor_Init.cpp"          
        //-------------------------------------------------------------------------------------------------------------------
        #include "_MODEL_FOLDERS_/tile_2m/tile_2m_Init.cpp"     
        //-------------------------------------------------------------------------------------------------------------------
        #include "_MODEL_FOLDERS_/pyramidTile/pyramidTile_Init.cpp"        
        //-------------------------------------------------------------------------------------------------------------------
        #include "_MODEL_FOLDERS_/smallPillar/smallPillar_Init.cpp"        
        //-------------------------------------------------------------------------------------------------------------------
        #include "_MODEL_FOLDERS_/plantPot_01/plantPot_01_Init.cpp"        
        //-------------------------------------------------------------------------------------------------------------------
        #include "_MODEL_FOLDERS_/plant_01/plant_01_Init.cpp"                                                             
        //--------------------------------------------------------------                                                    
        #include "_MODEL_FOLDERS_/rightWall_2x1/rightWall_2x1_Init.cpp"                                                             
        //--------------------------------------------------------------                                                    
        #include "_MODEL_FOLDERS_/backWall_2x2/backWall_2x2_Init.cpp"                                                             
        //--------------------------------------------------------------                                                    
        #include "_MODEL_FOLDERS_/spikyBall_0/spikyBall_0_Init.cpp"                                                             
        //===================================================================================================================         
        #include "_MODEL_FOLDERS_/springBoard/baseMain/baseMain_Init.cpp"                                                                   
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/springBoard/springCore/springCore_Init.cpp"                                                                   
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/springBoard/spring/spring_Init.cpp"                                                                   
        //====================================================================================           

#include "_MODEL_FOLDERS_/lightDisk/lightDiskobj_Init.cpp"                                                                   
//====================================================================================                                          
                                        
       
        //=================================================================================================================== 

                                        
       
        //=================================================================================================================== 
        
        
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);	
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //glAlphaFunc(GL_GREATER, 0.1);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);  
        
        
        //=====================================================================================================================
        
        
        
        
        
}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END_INIT__


//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################

void DrawModels(void)
{
        //ambient_globalIllumination_01 -= 0.001;
        
        
          
         if(SHADER_SELECTION == 1)
         {       
                 ambient_globalIllumination_01 = 1.0;   
                 
                 globalIllumination_01_LIGHT_POSITION_01[0] = spikyBall_0_POSITION[0];
                 globalIllumination_01_LIGHT_POSITION_01[1] = spikyBall_0_POSITION[1];
                 globalIllumination_01_LIGHT_POSITION_01[2] = spikyBall_0_POSITION[2];  
                 
                 #include "_MODEL_FOLDERS_/lightDisk/lightDiskobj_Render.cpp"   
                 
                                                                               
                 
                    
         //====================================================================================                            
         } 
         //-------------------------------------------------------------------------------------------------
         if(SHADER_SELECTION == 2)
         {       
                 globalIllumination_02_LIGHT_POSITION_01[0] = spikyBall_0_POSITION[0];
                 globalIllumination_02_LIGHT_POSITION_01[1] = spikyBall_0_POSITION[1];
                 globalIllumination_02_LIGHT_POSITION_01[2] = spikyBall_0_POSITION[2];                                                                       
         } 
         //-------------------------------------------------------------------------------------------------
         if(SHADER_SELECTION == 3)
         {       
                 MIRROR_SPECULAR_LIGHT_POSITION_01[0] = spikyBall_0_POSITION[0];
                 MIRROR_SPECULAR_LIGHT_POSITION_01[1] = spikyBall_0_POSITION[1];
                 MIRROR_SPECULAR_LIGHT_POSITION_01[2] = spikyBall_0_POSITION[2];                                                                      
         }         
         //-------------------------------------------------------------------------------------------------
         if(SHADER_SELECTION == 4)
         {       
                 globalIllumination_ORIGINAL_LIGHT_POSITION_01[0] = spikyBall_0_POSITION[0];
                 globalIllumination_ORIGINAL_LIGHT_POSITION_01[1] = spikyBall_0_POSITION[1];
                 globalIllumination_ORIGINAL_LIGHT_POSITION_01[2] = spikyBall_0_POSITION[2];                                                                      
         }          
        
         //-------------------------------------------------------------------------------------------------
         if(SHADER_SELECTION == 5)
         {       
                 globalIllumination_SQUARED_LIGHT_POSITION_01[0] = spikyBall_0_POSITION[0];
                 globalIllumination_SQUARED_LIGHT_POSITION_01[1] = spikyBall_0_POSITION[1];
                 globalIllumination_SQUARED_LIGHT_POSITION_01[2] = spikyBall_0_POSITION[2];                                                                      
         }         
        
        //================================================================================================= -5
        //================================================================================================= -5
        ambient_globalIllumination_01 = 1.0; 
        backDrop_POSITION[0] =  0.0;                                                                                                 
        backDrop_POSITION[1] =  1400;                                                                                                 
        backDrop_POSITION[2] =  0.0;                                                        
        #include "_MODEL_FOLDERS_/backDrop/backDrop_Render.cpp"         
       
       
        ambient_globalIllumination_01 = 0.4; 
        
        //#######################################################################################################################
        //#######################################################################################################################
        //#######################################################################################################################
        //================================================================================================= -5
        if(moveSet[0] > -4.0 && moveSet[0] < 20.0)
        {
                backGroundLight_01_POSITION[0]     =  -0.068917;  
                backGroundLight_01_POSITION[1]     =   3.9;        
                backGroundLight_01_POSITION[2]     =   500.0;          
        
        #include "_RENDER/draw_negative5.cpp"
        }
        //================================================================================================= -4
        if(moveSet[0] > -6.0 && moveSet[0] < 18.0)
        {
        #include "_RENDER/draw_negative4.cpp"
        }
        //================================================================================================= -3
        if(moveSet[0] > -8.0 && moveSet[0] < 16.0)
        {
                backGroundLight_01_POSITION[0]                            =  -0.068917;  
                backGroundLight_01_POSITION[1]                            =   3.9; 
                backGroundLight_01_POSITION[2]                            =  -0.715183;
                
        #include "_RENDER/draw_negative3.cpp"
        }
        //================================================================================================= -2
        if(moveSet[0] > -10.0 && moveSet[0] < 14.0)
        {
        #include "_RENDER/draw_negative2.cpp"
        }        
        //================================================================================================= 0
        if(moveSet[0] > -12.0 && moveSet[0] < 12.0)
        {
        #include "_RENDER/draw_0.cpp"
        }
        
        //----------------------------------------------------------------------------------------------0,1,-7----WINDOW 
        
        //================================================================================================= 2
        if(moveSet[0] > -14.0 && moveSet[0] < 10.0)
        {
        #include "_RENDER/draw_positive2.cpp"
        }
        //================================================================================================= 3
        if(moveSet[0] > -14 && moveSet[0] < 10)
        {
        #include "_RENDER/draw_positive3.cpp"
        }
        
        //=============================================================================================== 4
        
        if(moveSet[0] > -16 && moveSet[0] < 8)
        {
        #include "_RENDER/draw_positive4.cpp"
        }                                                      
        
        //=============================================================================================== 5
        
        if(moveSet[0] > -16 && moveSet[0] < 8)
        {
        #include "_RENDER/draw_positive5.cpp"
        }   
        
        //=============================================================================================== 6
        
        if(moveSet[0] > -18 && moveSet[0] < 6)
        {
        #include "_RENDER/draw_positive6.cpp"
        }   
        
        //
        //=============================================================================================== 8
        
        if(moveSet[0] > -20 && moveSet[0] < 4)
        {
        #include "_RENDER/draw_positive8.cpp"
        }   
        //============================================================================================================
        
        //-------------------------------------------------------------------------------------------------------------------------------------|_WINDOW
        
        //============================================================================================================ 10
        if(moveSet[0] > -22.0 && moveSet[0] < 2.0)
        {
        #include "_RENDER/draw_positive10.cpp"
        }   
        
        //============================================================================================================ 11
        
        if(moveSet[0] > -22.0 && moveSet[0] < 2.0)
        {
        #include "_RENDER/draw_positive11.cpp"
        }   
        
        //============================================================================================================ 12
        
        if(moveSet[0] > -24.0 && moveSet[0] < 0.0)
        {
        #include "_RENDER/draw_positive12.cpp"
        }   
        
        //============================================================================================================ 14                                   CEILING
        
        if(moveSet[0] > -26.0 && moveSet[0] < -2.0)
        {
        #include "_RENDER/draw_positive14.cpp"
        }  
        
        //--------------------------------------------------------------------------------------------------------------------------WINDOW_3
        
        //============================================================================================================ 15
        if(moveSet[0] > -26.0 && moveSet[0] < -2.0)
        {
        #include "_RENDER/draw_positive15.cpp"
        }  
        
        //============================================================================================================ 16
        if(moveSet[0] > -28.0 && moveSet[0] < -4.0)
        {
        #include "_RENDER/draw_positive16.cpp"
        } 
        //============================================================================================== 18
        if(moveSet[0] > -30.0 && moveSet[0] < -6.0)
        {
        #include "_RENDER/draw_positive18.cpp"
        } 
        
        //=========================================================================================== 20
        if(moveSet[0] > -32.0 && moveSet[0] < -8.0)
        {
        #include "_RENDER/draw_positive20.cpp"
        } 
        //=========================================================================================== 22
        if(moveSet[0] > -34.0 && moveSet[0] < -10.0)
        {
        #include "_RENDER/draw_positive22.cpp"
        } 
        //============================================================================================ 23
        if(moveSet[0] > -34.0 && moveSet[0] < -10.0)
        {
        #include "_RENDER/draw_positive23.cpp"
        } 
        //=========================================================================================== 24
        if(moveSet[0] > -36.0 && moveSet[0] < -12.0)
        {
        #include "_RENDER/draw_positive24.cpp"
        } 
        //============================================================================================ 26
        if(moveSet[0] > -38.0 && moveSet[0] < -14.0)
        {
        #include "_RENDER/draw_positive26.cpp"
        }
        //============================================================================================ 27
        if(moveSet[0] > -38.0 && moveSet[0] < -14.0)
        {
        #include "_RENDER/draw_positive27.cpp"
        }
        //============================================================================================ 28
        if(moveSet[0] > -40.0 && moveSet[0] < -16.0)
        {
        #include "_RENDER/draw_positive28.cpp"
        }
        //============================================================================================ 29
        if(moveSet[0] > -40.0 && moveSet[0] < -16.0)
        {
        #include "_RENDER/draw_positive29.cpp"
        }
        
        //============================================================================================ 30
        if(moveSet[0] > -42.0 && moveSet[0] < -18.0)
        {
        #include "_RENDER/draw_positive30.cpp"
        }
        
        //============================================================================================ 31
        if(moveSet[0] > -42.0 && moveSet[0] < -18.0)
        {
        #include "_RENDER/draw_positive31.cpp"
        }
        
        //============================================================================================ 32
        if(moveSet[0] > -44.0 && moveSet[0] < -20.0)
        {
        #include "_RENDER/draw_positive32.cpp"
        }
        //============================================================================================ 34
        if(moveSet[0] > -46.0 && moveSet[0] < -22.0)
        {
        #include "_RENDER/draw_positive34.cpp"
        }
        //============================================================================================ 35
        if(moveSet[0] > -46.0 && moveSet[0] < -22.0)
        {
        #include "_RENDER/draw_positive35.cpp"
        }
        //============================================================================================ 36
        if(moveSet[0] > -48.0 && moveSet[0] < -24.0)
        {
        #include "_RENDER/draw_positive36.cpp"
        }
        //============================================================================================ 37
        if(moveSet[0] > -48.0 && moveSet[0] < -24.0)
        {
        #include "_RENDER/draw_positive37.cpp"
        }
        //============================================================================================ 38
        if(moveSet[0] > -50.0 && moveSet[0] < -26.0)
        {
        #include "_RENDER/draw_positive38.cpp"
        }
        //============================================================================================ 40
        if(moveSet[0] > -52.0 && moveSet[0] < -28.0)
        {
        #include "_RENDER/draw_positive40.cpp"
        }
        //============================================================================================ 42
        if(moveSet[0] > -54.0 && moveSet[0] < -30.0)
        {
        #include "_RENDER/draw_positive42.cpp"
        }
        //============================================================================================ 43
        if(moveSet[0] > -54.0 && moveSet[0] < -30.0)
        {
        #include "_RENDER/draw_positive43.cpp"
        }
        //============================================================================================ 44
        if(moveSet[0] > -56.0 && moveSet[0] < -32.0)
        {
        #include "_RENDER/draw_positive44.cpp"
        }
        //============================================================================================ 46
        if(moveSet[0] > -58.0 && moveSet[0] < -34.0)
        {
        #include "_RENDER/draw_positive46.cpp"
        }
        //============================================================================================ 48
        if(moveSet[0] > -60.0 && moveSet[0] < -36.0)
        {
        #include "_RENDER/draw_positive48.cpp"
        }
        //============================================================================================ 50
        if(moveSet[0] > -62.0 && moveSet[0] < -38.0)
        {
        #include "_RENDER/draw_positive50.cpp"
        }
        //============================================================================================ 52
        if(moveSet[0] > -64.0 && moveSet[0] < -40.0)
        {
        #include "_RENDER/draw_positive52.cpp"
        }
        //============================================================================================ 53
        if(moveSet[0] > -64.0 && moveSet[0] < -40.0)
        {
        #include "_RENDER/draw_positive53.cpp"
        }
        //============================================================================================ 54
        if(moveSet[0] > -66.0 && moveSet[0] < -42.0)
        {
        #include "_RENDER/draw_positive54.cpp"
        }
        //============================================================================================ 55
        if(moveSet[0] > -66.0 && moveSet[0] < -42.0)
        {
        #include "_RENDER/draw_positive55.cpp"
        }
        //============================================================================================ 56
        if(moveSet[0] > -68.0 && moveSet[0] < -44.0)
        {
        #include "_RENDER/draw_positive56.cpp"
        }
        //============================================================================================ 57
        if(moveSet[0] > -68.0 && moveSet[0] < -44.0)
        {
        #include "_RENDER/draw_positive57.cpp"
        }
        //============================================================================================ 58
        if(moveSet[0] > -70.0 && moveSet[0] < -46.0)
        {
        #include "_RENDER/draw_positive58.cpp"
        }
        //============================================================================================ 59                
        if(moveSet[0] > -70.0 && moveSet[0] < -46.0)
        {
        #include "_RENDER/draw_positive59.cpp"
        }
        //============================================================================================ 60                  
        if(moveSet[0] > -72.0 && moveSet[0] < -48.0)
        {
        #include "_RENDER/draw_positive60.cpp"
        }
        //============================================================================================ 62       
        if(moveSet[0] > -74.0 && moveSet[0] < -50.0)
        {
        #include "_RENDER/draw_positive62.cpp"
        }
        //============================================================================================ 64                  
        if(moveSet[0] > -76.0 && moveSet[0] < -52.0)
        {
        #include "_RENDER/draw_positive64.cpp"
        }
        //============================================================================================ 66  
        
        //======================================================================================================================
        #include "_MODEL_FOLDERS_/marcParts/RenderMarc.cpp"
        //======================================================================================================================
        
        
                
        
        #include "_MODEL_FOLDERS_/spikyBall_0/spikyBall_0_Render.cpp"              
        //============================================================================================        
      
        #include "_MODEL_FOLDERS_/springBoard/baseMain/baseMain_Render.cpp"                                                                 
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/springBoard/springCore/springCore_Render.cpp"                                                                 
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/springBoard/spring/spring_Render.cpp"                                                                 
        //==================================================================================== 
        
         
                                              
           
          
}

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################


void RenderGL(void)
{
        

                 if(marcWalking)
                 {
                           if(resetAnimation)
                           {
                                    mainBodyPosition_setSelection         = 1;
                                    setSelection_LEFT_ARM                 = 1;
                                    setSelection_RIGHT_ARM                = 1;
                                    setSelection_LEFT_LEG                 = 1;
                                    setSelection_RIGHT_LEG                = 1;                                    
                                    setSelection_HEAD                     = 1;
                                    setSelection_TORSO                    = 1;
                                    setSelection_HIPS                     = 1;
                                    
                                    resetAnimation = false;
                           }
                           
                           #include "_MODEL_FOLDERS_/marcParts/ME_AnimationSet_WALK.cpp"
                           #include "_MODEL_FOLDERS_/marcParts/ME_animationSequencing.cpp" 
                 }      

        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
        //======================================================_SHADOWS_BEGIN_===========================================================================	                       
       
       
        #include  "ADD_COLLISION_BALL/RENDER_1.cpp"
        
        
        
        
        //=============================================================================================================================  
        
        glBindFramebuffer(GL_FRAMEBUFFER, shadow_2D_ID);//-----------------------F.B.O.     
        //----------------------------------------------------------------
        //glColor4f(color is changed using fragment program)
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glClear (GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, TEXTURE_WIDTH, TEXTURE_HEIGHT);
        //----------------------------------------------------------------
        
        
        //-----------------------------------------------------------------------------------------------------------------------------                                
        
        
        glDisable(GL_BLEND);
        glDisable(GL_DEPTH_TEST);
        
        
        PerspectiveMatrix(ProjectionShadow, 45, 1.0, 0.001, 10000.0);
        
        
        //Rotate(ProjectionShadow, 0.0, 1.0, 0.0, 20.0);
        Rotate(ProjectionShadow, 1.0, 0.0, 0.0, 90.0);
        
        
        
        
        
        glUseProgram(SHADER_shadow);//---------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  
        
        //############################################################################################################################################################|__SHADOW_01
        //============================================================================================================================================================|__LAYER__01
        glColorMask(GL_TRUE, GL_FALSE, GL_FALSE, GL_TRUE); 
        //===================================================== 
        darkness_shadow[0] = 0.5;
        darkness_shadow[1] = 0.5;
        darkness_shadow[2] = 0.5;
        
        
        
        //-----------------------------------------------------                        
        #include "_MODEL_FOLDERS_/spikyBall_0/spikyBall_0_Shadow_01.cpp"  
        //------------------------------------------------------------------  
        
        //-----------------------------------------------------------                      
        #include "_MODEL_FOLDERS_/marcParts/RenderMarc_SHADOW_01.cpp"
        //================================================================================================================   
        
        //================================================================================================================   
        //#include "_MODEL_FOLDERS_/springBoard/baseMain/baseMain_Shadow_00.cpp"                                                              
        //====================================================================================         
        //#include "_MODEL_FOLDERS_/springBoard/springCore/springCore_Shadow_01.cpp"                                                              
        //====================================================================================                                          
        //#include "_MODEL_FOLDERS_/springBoard/springCore/springCore_Shadow_00.cpp"                                                              
        //====================================================================================                                          
        //#include "_MODEL_FOLDERS_/springBoard/spring/spring_Shadow_01.cpp"                                                              
        //====================================================================================                                          
        //#include "_MODEL_FOLDERS_/springBoard/spring/spring_Shadow_00.cpp"                                                              
        //====================================================================================                                          
          
        //============================================================================================================================================================|__LAYER__02       
        glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE); 
        //===========================================================                     
        
        
        
        
                   
        //###################################################################################################################################################
        //###################################################################################################################################################      
        //###################################################################################################################################################          
                    

                      
                      
                      
        //==============================================================================                      
                  plant_01_POSITION[0]                                       =  -2.0;                                                                                                 
                  plant_01_POSITION[1]                                       =   0.68;                                                                                                 
                  plant_01_POSITION[2]                                       =  -2.0;                                
        #include "_MODEL_FOLDERS_/plant_01/plant_01_SHADOW_01.cpp"
        //-----------------------------------------------------------------------------
                  plant_01_POSITION[0]                                       =   2.0;                                                                                                 
                  plant_01_POSITION[1]                                       =   0.68;                                                                                                 
                  plant_01_POSITION[2]                                       =  -2.0;          
        #include "_MODEL_FOLDERS_/plant_01/plant_01_SHADOW_01.cpp"
        //==============================================================================                                  
        
        
        
        //############################################################################################################################################################|__SHADOW_02
        
        
        
        //============================================================================================================================================================|__LAYER__01
        glColorMask(GL_TRUE, GL_FALSE, GL_FALSE, GL_TRUE); 
        //===========================================================                       
        darkness_shadow[0] = 0.3;
        darkness_shadow[1] = 0.3;
        darkness_shadow[2] = 0.3;
        
        
        
        //============================================================================================================================================================|__LAYER__02     
        glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE); 
        //===========================================================
        
        
        
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------- 
        LoadIdentity(textureMatrix);
        AssignMatrix(textureMatrix, ProjectionShadow); 
        //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                      
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); 	                       
	glBindFramebuffer(GL_FRAMEBUFFER, 0);	                       
       
        //======================================================_SHADOWS_END_=============================================================================	                       
        //======================================================_SHADOWS_END_=============================================================================	                       
        //======================================================_SHADOWS_END_=============================================================================	                       
        //======================================================_SHADOWS_END_=============================================================================	 
   
   glEnable(GL_DEPTH_TEST);       


//##################################################################################################################################################################################################        
//##################################################################################################################################################################################################         
//##################################################################################################################################################################################################         
//##################################################################################################################################################################################################          
        


#ifdef WIN32    
         glBindFramebufferEXT(GL_FRAMEBUFFER_EXT,  componentShaderPass_fbo);
        // glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, componentShaderPass_depth);
#endif         
      
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_frameBuffer____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!        
        //---------------------------------------------------RETURN_TO_MAIN_frameBuffer____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!          
        //========================================================================================================================================================
        
        //=========================================================================================================================================================    
        glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        //========================================================================================================================================================= 
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        PerspectiveMatrix(projection, 45,(float)viewWidth / (float)viewHeight, 0.1, 1000);
#ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        projection[12] = eyePosition[1];
        projection[13] = eyePosition[0];
        projection[15] = eyePosition[2];
#endif
        //=========================================================================================================================================================
        
#ifdef WIN32
        projection[12] = eyePosition[0];
        projection[13] = eyePosition[1];
        projection[15] = eyePosition[2];                 
#endif
        
        
        Rotate(projection, 1.0, 0.0, 0.0,  rotateModel[1]);
        Rotate(projection, 0.0, 1.0, 0.0,  rotateModel[0]);        
        
        //#################################################################################################################################################################        
        
        //moveSet[0] -= 0.01;
        //moveSet[1] -= 0.004;        
        
        
        
        
                                                          


 SHADER_SELECTION = 0;
    DrawModels();    
		     
             
glBindFramebuffer(GL_FRAMEBUFFER, 0);        
       
        
        
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        
 //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^       
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        
    


#ifdef __APPLE__    
        glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
#endif    
#ifdef WIN32    
         glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo);
         //glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, depth);
#endif         
      
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_frameBuffer____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!        
        //---------------------------------------------------RETURN_TO_MAIN_frameBuffer____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!          
        //========================================================================================================================================================
        
        //=========================================================================================================================================================    
        glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        //========================================================================================================================================================= 
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        PerspectiveMatrix(projection, 45,(float)viewWidth / (float)viewHeight, 0.1, 1000);
#ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        projection[12] = eyePosition[1];
        projection[13] = eyePosition[0];
        projection[15] = eyePosition[2];
#endif
        //=========================================================================================================================================================
        
#ifdef WIN32
        projection[12] = eyePosition[0];
        projection[13] = eyePosition[1];
        projection[15] = eyePosition[2];                 
#endif
        
        
    Rotate(projection, 1.0, 0.0, 0.0,  rotateModel[1]);
        Rotate(projection, 0.0, 1.0, 0.0,  rotateModel[0]);         
        
        //#################################################################################################################################################################        
        
        //moveSet[0] -= 0.01;
        //moveSet[1] -= 0.004;        
        
        
                                                         


    SHADER_SELECTION = (GLuint)ChangeShaderSelection;
    DrawModels();    
		     
             
glBindFramebuffer(GL_FRAMEBUFFER, 0);
        
//*******************************************************************************************************************************************       
//*******************************************************************************************************************************************        
//*******************************************************************************************************************************************         
//*******************************************************************************************************************************************       
//*******************************************************************************************************************************************        
//*******************************************************************************************************************************************         


                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, gaussianBlurHorizontalPass_fboId);//-----F.B.O.__HORIZONTAL_BLUR

        //=========================================================================================================================================================    
        glClearColor( 1.0f, 1.0f, 1.0f, 0.5f );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        //----------------------------------------------------------------------------------
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        
        PerspectiveMatrix2(ScreenBufferMatrix,viewWidth / viewHeight);
        
        //=========================================================================================================================================================
        #ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        ScreenBufferMatrix[12] = screenBuffer_EyePosition[0];
        ScreenBufferMatrix[13] = screenBuffer_EyePosition[2];
        ScreenBufferMatrix[15] = screenBuffer_EyePosition[1];        
        #endif        
        //=========================================================================================================================================================        
        #ifdef WIN32        
        ScreenBufferMatrix[12] = screenBuffer_EyePosition[0];
        ScreenBufferMatrix[13] = screenBuffer_EyePosition[1];
        ScreenBufferMatrix[15] = screenBuffer_EyePosition[2];  
        #endif           
        //=========================================================================================================================================================               
        Rotate(ScreenBufferMatrix, 1.0, 0.0, 0.0,  0);
        Rotate(ScreenBufferMatrix, 0.0, 1.0, 0.0, -0);        
    

    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, color);                 
//====================================================================================                                          
#include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_GaussianHorizontal_Render.cpp"                                                                 
//====================================================================================                                       
                                                                
//==================================================================================== 
                              
                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);    //--------------------------------F.B.O.__HORIZONTAL_BLUR             

//==========================================================================================================================================================
//==========================================================================================================================================================
//==========================================================================================================================================================                               

                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, gaussianBlurVerticalPass_fboId);//-----F.B.O.__HORIZONTAL_BLUR

        //=========================================================================================================================================================    
        glClearColor( 1.0f, 1.0f, 1.0f, 0.5f );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        //----------------------------------------------------------------------------------
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        
        PerspectiveMatrix2(ScreenBufferMatrix,viewWidth / viewHeight);
        
        //=========================================================================================================================================================
        #ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        ScreenBufferMatrix[12] = screenBuffer_EyePosition[0];
        ScreenBufferMatrix[13] = screenBuffer_EyePosition[2];
        ScreenBufferMatrix[15] = screenBuffer_EyePosition[1];        
        #endif        
        //=========================================================================================================================================================        
        #ifdef WIN32        
        ScreenBufferMatrix[12] = screenBuffer_EyePosition[0];
        ScreenBufferMatrix[13] = screenBuffer_EyePosition[1];
        ScreenBufferMatrix[15] = screenBuffer_EyePosition[2];  
        #endif           
        //=========================================================================================================================================================               
        Rotate(ScreenBufferMatrix, 1.0, 0.0, 0.0,  0);
        Rotate(ScreenBufferMatrix, 0.0, 1.0, 0.0, -0);        
    

    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D,  textureMap[1]);                 
//====================================================================================                                          
#include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_GaussianVertical_Render.cpp"                                                                 
//====================================================================================                                       
                                                                
//==================================================================================== 
                              
                              glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);    //--------------------------------F.B.O.__HORIZONTAL_BLUR             
 
        //=========================================================================================================================================================    
        glClearColor( 1.0f, 1.0f, 1.0f, 0.5f );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        //----------------------------------------------------------------------------------
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        
        PerspectiveMatrix2(ScreenBufferMatrix,viewWidth / viewHeight);
        
        //=========================================================================================================================================================
        #ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        ScreenBufferMatrix[12] = screenBuffer_EyePosition[0];
        ScreenBufferMatrix[13] = screenBuffer_EyePosition[2];
        ScreenBufferMatrix[15] = screenBuffer_EyePosition[1];        
        #endif        
        //=========================================================================================================================================================        
        #ifdef WIN32        
        ScreenBufferMatrix[12] = screenBuffer_EyePosition[0];
        ScreenBufferMatrix[13] = screenBuffer_EyePosition[1];
        ScreenBufferMatrix[15] = screenBuffer_EyePosition[2];  
        #endif           
        //=========================================================================================================================================================               
        Rotate(ScreenBufferMatrix, 1.0, 0.0, 0.0,  0);
        Rotate(ScreenBufferMatrix, 0.0, 1.0, 0.0, -0);        
    
    glActiveTexture (GL_TEXTURE1);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, componentShaderPass_color);      
    //---------------------------------------------
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, textureMap[2]);  //_USE_FOR_BLUR-->>  textureMap[2]             
//====================================================================================                                          
#include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_Render.cpp"                                                                 
//====================================================================================      
        
        
#ifdef WIN32
        SwapBuffers( hDC );
#endif
}

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################


#ifdef WIN32 
void ProcessKeyboard()					
{
//#########################################################################################################################################################       

    
//#include "_MODEL_FOLDERS_/lightDisk/lightDiskobj_Keyboard.cpp"                                                               
//====================================================================================                                          
       
    
    //------------------------------------------------------------------------------
    if (keys['B'])
	{
          BASE_LIGHTING                 = true;
          GOLDEN_SUNSET_LIGHTING        = false;
    }	
    if (keys['V'])
	{
          BASE_LIGHTING                 = false;
          GOLDEN_SUNSET_LIGHTING        = true;
    }
    //=======================================================================================
    
    //=======================================================================================
    if (keys[VK_TAB] && TAB_KEY_RESET && !keys[VK_SHIFT])
    {
             ChangeShaderSelection         +=  1;
             TAB_KEY_RESET                  = false;
    }
    if (!keys[VK_TAB])
    {
            TAB_KEY_RESET                 = true;
    }

    if (keys[VK_TAB] && TAB_KEY_RESET && keys[VK_SHIFT])
    {
             ChangeShaderSelection         -=  1;
             TAB_KEY_RESET           = false;
    }
    if (!keys[VK_TAB])
    {
            TAB_KEY_RESET           = true;
    }
    //=======================================================================================
   
    //=======================================================================================
     if (keys['J'])                                                                                                                   
    {                                                                                                                                   
             lightDiskobj_POSITION[0]         -=  0.01;                                                                         
    }	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             lightDiskobj_POSITION[0]         +=  0.01;                                                                            
    }                                                                                                                                   
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             lightDiskobj_POSITION[1]         +=  0.01;                                                                            
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             lightDiskobj_POSITION[1]         -=  0.01;                                                                            
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             lightDiskobj_POSITION[2]         +=  0.01;                                                                            
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             lightDiskobj_POSITION[2]         -=  0.01;      
    }
    
        if (keys[VK_F8]) 			                                                                                                                   
        {                                                                                                                                              
                ofstream outKeys("lightDisk.cpp");                                                                                     
                
                outKeys << "  GLfloat     lightDiskobj_POSITION[] = {"           << lightDiskobj_POSITION[0] << ", "                               
                                                                                   << lightDiskobj_POSITION[1] << ", "                               
                                                                                   << lightDiskobj_POSITION[2] << ", " << 1.0 << "};\n";          
                
         
         }     
    
    //=======================================================================================        
 
    if (keys['H'])                                                                                                                      
    {	                                                                                                                                  
             frameBufferPlane_ratio_Global_2_Component                  +=  .01;                                                                            
    }	                                                                                                                                  
    if (keys['G'])                                                                                                                      
    {	                                                                                                                                  
             frameBufferPlane_ratio_Global_2_Component                  -=  .01;                                                                            
    }  
      
    if (keys['Y'])                                                                                                                      
    {	                                                                                                                                  
             ambient_goldenSunset                  +=  .01;                                                                            
    }	                                                                                                                                  
    if (keys['T'])                                                                                                                      
    {	                                                                                                                                  
             ambient_goldenSunset                  -=  .01;                                                                            
    }             

 

//################################################################################################         
if(SHADER_SELECTION == 1)
{       
     
     if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             ambient_globalIllumination_01                  +=  .01;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             ambient_globalIllumination_01                  -=  .01;                                                                            
    }      
    
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_globalIllumination_01                 +=   .01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_globalIllumination_01                 -=   .01;                                                                            
    }          
        if (keys[VK_F8]) 			                                                                                                                   
        {                                                                                                                                              
                ofstream outKeys("CALIBRATION.cpp");                                                                                     
                
                //outKeys << "  GLfloat     screenBuffer_EyePosition[] = {"           << screenBuffer_EyePosition[0] << ", "                               
                 //                                                                   << screenBuffer_EyePosition[1] << ", "                               
                 //                                                                   << screenBuffer_EyePosition[2] << ", " << 1.0 << "};\n";          
                
               outKeys << "  ambient_goldenSunset        =  " << ambient_goldenSunset   << ";\n"; 
               
               outKeys << "  frameBufferPlane_ratio_Global_2_Component        =  " << frameBufferPlane_ratio_Global_2_Component   << ";\n";                                    
                
                outKeys << "  GLfloat     ambient_globalIllumination_01        =  " << ambient_globalIllumination_01   << ";\n";                                    
                
                outKeys << "  GLfloat     scaleInverse_NdotL1_globalIllumination_01           =  " << scaleInverse_NdotL1_globalIllumination_01  << ";\n";                                       
        }            
} 
//-------------------------------------------------------------------------------------------------
 if(SHADER_SELECTION == 2)
{       
     if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             ambient_globalIllumination_02                  +=  .01;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             ambient_globalIllumination_02                  -=  .01;                                                                            
    }      
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_globalIllumination_02                 +=   .01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_globalIllumination_02                 -=   .01;                                                                            
    }          
        
        
        if (keys[VK_F8]) 			                                                                                                                   
        {                                                                                                                                              
                ofstream outKeys("CALIBRATION.cpp");                                                                                     
                
                outKeys << "  GLfloat     screenBuffer_EyePosition[] = {"           << screenBuffer_EyePosition[0] << ", "                               
                                                                        << screenBuffer_EyePosition[1] << ", "                               
                                                                        << screenBuffer_EyePosition[2] << ", " << 1.0 << "};\n";          
                
              
               outKeys << "  ambient_goldenSunset        =  " << ambient_goldenSunset   << ";\n"; 
               
               outKeys << "  frameBufferPlane_ratio_Global_2_Component        =  " << frameBufferPlane_ratio_Global_2_Component   << ";\n";                                    
              
              
                outKeys << "  GLfloat     ambient_globalIllumination_02        =  " << ambient_globalIllumination_02   << ";\n";                                    
                
                outKeys << "  GLfloat     scaleInverse_NdotL1_globalIllumination_02           =  " << scaleInverse_NdotL1_globalIllumination_02  << ";\n";                                       
        }                                                                        
} 
//-------------------------------------------------------------------------------------------------
if(SHADER_SELECTION == 3)
{       
    if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             ambient_MIRROR_SPECULAR                  +=  .01;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             ambient_MIRROR_SPECULAR                  -=  .01;                                                                            
    }      
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_MIRROR_SPECULAR                 +=   .01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_MIRROR_SPECULAR                 -=   .01;                                                                            
    }          
        
        if (keys[VK_F8]) 			                                                                                                                   
        {                                                                                                                                              
                ofstream outKeys("CALIBRATION.cpp");                                                                                     
                
                outKeys << "  GLfloat     screenBuffer_EyePosition[] = {"           << screenBuffer_EyePosition[0] << ", "                               
                                                                        << screenBuffer_EyePosition[1] << ", "                               
                                                                        << screenBuffer_EyePosition[2] << ", " << 1.0 << "};\n";          
                
               outKeys << "  frameBufferPlane_ratio_Global_2_Component        =  " << frameBufferPlane_ratio_Global_2_Component   << ";\n";                                    
        
       
                outKeys << "  GLfloat     ambient_MIRROR_SPECULAR        =  " << ambient_MIRROR_SPECULAR   << ";\n";                                    
                
                outKeys << "  GLfloat     scaleInverse_NdotL1_MIRROR_SPECULAR           =  " << scaleInverse_NdotL1_MIRROR_SPECULAR  << ";\n";                                       
        }                                                                      
}         
//-------------------------------------------------------------------------------------------------
if(SHADER_SELECTION == 4)
{       
        
    if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             ambient_globalIllumination_ORIGINAL                  +=  .01;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             ambient_globalIllumination_ORIGINAL                  -=  .01;                                                                            
    }      
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_globalIllumination_ORIGINAL                  +=   .01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_globalIllumination_ORIGINAL                  -=   .01;                                                                            
    }          
        
        if (keys[VK_F8]) 			                                                                                                                   
        {                                                                                                                                              
                ofstream outKeys("CALIBRATION.cpp");                                                                                     
                
                outKeys << "  GLfloat     screenBuffer_EyePosition[] = {"           << screenBuffer_EyePosition[0] << ", "                               
                                                                        << screenBuffer_EyePosition[1] << ", "                               
                                                                        << screenBuffer_EyePosition[2] << ", " << 1.0 << "};\n";          
                
               outKeys << "  frameBufferPlane_ratio_Global_2_Component        =  " << frameBufferPlane_ratio_Global_2_Component   << ";\n";                                    
          
         
                outKeys << "  GLfloat     ambient_globalIllumination_ORIGINAL        =  " << ambient_globalIllumination_ORIGINAL   << ";\n";                                    
                
                outKeys << "  GLfloat     scaleInverse_NdotL1_globalIllumination_ORIGINAL           =  " << scaleInverse_NdotL1_globalIllumination_ORIGINAL  << ";\n";                                       
        }                                                                      
         }          
        
//-------------------------------------------------------------------------------------------------
if(SHADER_SELECTION == 5)
{       
        
    if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             ambient_globalIllumination_SQUARED                  +=  .01;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             ambient_globalIllumination_SQUARED                  -=  .01;                                                                            
    }      
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_globalIllumination_SQUARED                  +=   .01;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             scaleInverse_NdotL1_globalIllumination_SQUARED                  -=   .01;                                                                            
    }            
       
        if (keys[VK_F8]) 			                                                                                                                   
        {                                                                                                                                              
                ofstream outKeys("CALIBRATION.cpp");                                                                                     
                
                outKeys << "  GLfloat     screenBuffer_EyePosition[] = {"           << screenBuffer_EyePosition[0] << ", "                               
                                                                                    << screenBuffer_EyePosition[1] << ", "                               
                                                                                    << screenBuffer_EyePosition[2] << ", " << 1.0 << "};\n\n";          
                
                outKeys << "  frameBufferPlane_ratio_Global_2_Component        =  " << frameBufferPlane_ratio_Global_2_Component   << ";\n\n";                                    
               
                outKeys << "  GLfloat     ambient_globalIllumination_SQUARED        =  " << ambient_globalIllumination_SQUARED   << ";\n";                                    
                
                outKeys << "  GLfloat     scaleInverse_NdotL1_globalIllumination_SQUARED           =  " << scaleInverse_NdotL1_globalIllumination_SQUARED  << ";\n";                                       
        }                                                                       
}        
//################################################################################################                                                             





#include "_MODEL_FOLDERS_/marcParts/marc_KEYBOARD_CONTROLS.cpp"

//--------------------------------------------------------------------    
    if (keys['A'])
	{
          eyePosition[0]    += .05;
    }	
    if (keys['D'])
	{
          eyePosition[0]    -= .05;
    }
//-----------------------------------
    if (keys['S'])
	{
          eyePosition[2] += .05;
    }
          if (keys['S'] && keys[VK_SHIFT])
	      {
                eyePosition[2] += 0.5;
          
          }    
//-----------------------------------	
    if (keys['W'])
	{
          eyePosition[2] -= .05;       
    }    
	      if (keys['W'] && keys[VK_SHIFT])
	      {
                eyePosition[2] -= 0.5;      
          }	
//-----------------------------------    
    if (keys['E'])
	{
          eyePosition[1] -= 0.05;
    }
	      if (keys['E'] && keys[VK_SHIFT])
	      {
                eyePosition[1] -= 0.5;      
          }		
    
    if (keys['Q'])
	{
          eyePosition[1] += 0.05;      
    }
	      if (keys['Q'] && keys[VK_SHIFT])
	      {
                eyePosition[1] += 0.5;      
          }            

//#########################################################################################################################################################       
}
#endif


//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################



void shutDownGL( void )
{
#ifdef WIN32
#include "cpp/shutDownWin.cpp"
#endif 	 
        
        //====================================================================================
        #include "_SHADERS/BACKGROUND/goldenSunset_SHUTDOWN.cpp"
        //====================================================================================
        #include "_SHADERS/BASIC/baseLighting_SHUTDOWN.cpp"
        //====================================================================================        
        #include "_SHADERS/GLOBAL_ILLUMINATION/globalIllumination_01_SHUTDOWN.cpp"            
        //====================================================================================        
        #include "_SHADERS/GLOBAL_ILLUMINATION/FOG_SSS/globalIllumination_02_SHUTDOWN.cpp"            
        //====================================================================================        
        #include "_SHADERS/GLOBAL_ILLUMINATION/MIRROR_SPECULAR/MIRROR_SPECULAR_SHUTDOWN.cpp"              
        //====================================================================================       
        #include "_SHADERS/GLOBAL_ILLUMINATION/ORIGINAL/globalIllumination_ORIGINAL_SHUTDOWN.cpp"              
        //====================================================================================            
        #include "_SHADERS/GLOBAL_ILLUMINATION/SQUARED/globalIllumination_SQUARED_SHUTDOWN.cpp"              
        //====================================================================================               
        
        //------------------------------------------------------------------------------------
        #include "_MODEL_FOLDERS_/marcParts/DeleteMarc.cpp"  
        //====================================================================================
        #include "_MODEL_FOLDERS_/marcParts/head/head_Shutdown.cpp"   
        //====================================================================================                                                                      
        #include "_MODEL_FOLDERS_/chestArmor/shutDown.cpp"        
        //====================================================================================   
        #include "_MODEL_FOLDERS_/springBoard/baseMain/baseMain_Shutdown.cpp"                                                               
        //====================================================================================         
        #include "_MODEL_FOLDERS_/springBoard/springCore/springCore_Shutdown.cpp"                                                               
        //====================================================================================                                                              
        #include "_MODEL_FOLDERS_/springBoard/spring/spring_Shutdown.cpp"                                                               
        //====================================================================================        
#include "_MODEL_FOLDERS_/lightDisk/lightDiskobj_Shutdown.cpp"                                                               
//====================================================================================        
        
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================




