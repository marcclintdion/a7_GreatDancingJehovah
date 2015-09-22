GLuint      baseMain_SHADER_VERTEX;                                                                                                      
GLuint      baseMain_SHADER_FRAGMENT;                                                                                                    
GLuint      baseMain_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_baseMain;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_baseMain;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_baseMain;                                                                                          
GLuint      UNIFORM_SHININESS_baseMain;  
GLuint      UNIFORM_ATTENUATION_baseMain;                                                                                                
GLuint      UNIFORM_TEXTURE_DOT3_baseMain;                                                                                               
GLuint      UNIFORM_TEXTURE_baseMain;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     baseMain_POSITION[]            =  {  2.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     baseMain_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     baseMain_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
//-----------------------------------------------------------------                                                                       
GLfloat     baseMain_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     baseMain_SHININESS             =    80.0;                                                                                    
GLfloat     baseMain_ATTENUATION           =     1.0;                                                                                    
//-----------------------------------------------------------------                                                                       
GLuint      baseMain_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      baseMain_NORMALMAP;                                                                                                          
GLuint      baseMain_TEXTUREMAP;                                                                                                         
