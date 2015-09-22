GLuint      rockRing_SHADER_VERTEX;                                                                                                      
GLuint      rockRing_SHADER_FRAGMENT;                                                                                                    
GLuint      rockRing_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_rockRing;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_rockRing;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_rockRing;                                                                                          
GLuint      UNIFORM_SHININESS_rockRing;                                                                                                  
GLuint      UNIFORM_ATTENUATION_rockRing;                                                                                                  
GLuint      UNIFORM_TEXTURE_DOT3_rockRing;                                                                                               
GLuint      UNIFORM_TEXTURE_rockRing;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     rockRing_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     rockRing_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     rockRing_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     rockRing_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     rockRing_SHININESS             =    80.0;                                                                                    
GLfloat     rockRing_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      rockRing_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      rockRing_NORMALMAP;                                                                                                          
GLuint      rockRing_TEXTUREMAP;                                                                                                         
