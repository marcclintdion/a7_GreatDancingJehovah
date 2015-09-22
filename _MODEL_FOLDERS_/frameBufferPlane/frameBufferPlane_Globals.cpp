GLuint      frameBufferPlane_SHADER_VERTEX;                                                                                                      
GLuint      frameBufferPlane_SHADER_FRAGMENT;                                                                                                    
GLuint      frameBufferPlane_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_frameBufferPlane;                                                                                              
GLuint      UNIFORM_LIGHT_MATRIX_frameBufferPlane;                                                                                               
//--------------------------------------                                                                                                  
GLuint      UNIFORM_LIGHT_POSITION_01_frameBufferPlane;                                                                                          
GLuint      UNIFORM_SHININESS_frameBufferPlane;                                                                                                  
GLuint      UNIFORM_ATTENUATION_frameBufferPlane;  
                                                                                                
GLuint      UNIFORM_ratio_Global_2_Component_frameBufferPlane;   

GLuint      UNIFORM_SHADER_SELECTION_frameBufferPlane;  

GLuint      UNIFORM_TEXTURE_2_frameBufferPlane;  
GLuint      UNIFORM_TEXTURE_frameBufferPlane; 
                                                                                                   
//--------------------------------------                                                                                                  
GLfloat     frameBufferPlane_POSITION[]            =  {  0.0, 0.0, 0.0, 1.0};                                                                    
GLfloat     frameBufferPlane_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
                                                                
//-----------------------------------------------------------------                                                                       
GLfloat     frameBufferPlane_LIGHT_POSITION_01[]   =  {  2.0, 15.0, 30.0, 1.0};                                                                  
GLfloat     frameBufferPlane_ATTENUATION           =     1.0;                                                                                    
GLfloat     frameBufferPlane_SHININESS             =    534.502;   
                                                                                 
//-----------------------------------------------------------------                                                                       
GLuint      frameBufferPlane_VBO;                                                                                                                
//-----------------------------------------------------------------                                                                       
GLuint      frameBufferPlane_NORMALMAP;                                                                                                          
GLuint      frameBufferPlane_TEXTUREMAP;                                                                                                         
